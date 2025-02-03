// Fill out your copyright notice in the Description page of Project Settings.

#include "FlightSimulator/Public/FlightSystem/Flyer_Base.h"

#include "Blueprint/UserWidget.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameInstance/GameInstanceFlightSimulator.h"



// Constructor
AFlyer_Base::AFlyer_Base()
{
    // Enable ticking every frame
    PrimaryActorTick.bCanEverTick = true;
	
	// Configure the existing CapsuleComponent
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	GetCapsuleComponent()->SetNotifyRigidBodyCollision(true);
	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
	GetCapsuleComponent()->SetCapsuleRadius(48.0f);
	
    // Create the Static Mesh Component
    FlyerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlyerMesh"));
    FlyerMesh->SetupAttachment(GetCapsuleComponent());

    // Create the SpringArm and attach to CapsuleComponent
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(GetCapsuleComponent());
    SpringArm->TargetArmLength= 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    // Create the Camera and attach to the SpringArm
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false;
}



float AFlyer_Base::CalculateHeightFromGround()
{
	//start position of player
	FVector Start = GetActorLocation();
	//end position of raycast, going down x units
	FVector End = Start - FVector(0.0f, 0.0f, 100000.0f);

	//create raycast
	
	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	//Ignore the actor
	QueryParams.AddIgnoredActor(this); 

	// Make the trace
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams))
	{
		//if it hits, calculate distance
		return (Start - HitResult.Location).Size();
	}

	//if it doesnt collide, it returns a big altitude
	return 10000.0f; // Altura máxima si no detecta el suelo
}

void AFlyer_Base::HandleRollAxis_HorizontalInclination(const FInputActionValue& Value)
{
    float InputValue = Value.Get<float>();
    AddControllerRollInput(InputValue * RollRateMultiplier * GetWorld()->GetDeltaSeconds());
}

//IT WORKS, the vertical inclination
void AFlyer_Base::HandlePitchAxis_VerticalInclination(const FInputActionValue& Value)
{
    float InputValue = Value.Get<float>();
    AddControllerPitchInput(InputValue * PitchRateMultiplier * GetWorld()->GetDeltaSeconds()); 
}

float AFlyer_Base::CalculateYawEffect_HorizontalInclination(float RollInput, float deltaTime)
{
	float YawEffect = RollInput * YawScalingFactor;
	AddControllerYawInput(YawEffect * deltaTime);
	
	return YawEffect;
}

float AFlyer_Base::CalculateAccelerationForward(float PitchInput, float deltaTime, float pitchEffectMultiplier)
{
	return (-FMath::Sin(FMath::DegreesToRadians(PitchInput)) * Acceleration * pitchEffectMultiplier * deltaTime);
}

float AFlyer_Base::CalculateAccelerationSide(float RollInput, float deltaTime, float rollEffectMultiplier)
{
	return FMath::Sin(FMath::DegreesToRadians(RollInput)) * rollEffectMultiplier * Acceleration * deltaTime;
}

void AFlyer_Base::CalculateFrontSpeed(float PitchInput, float CurrentAccForward)
{
	// Apply FRONT Speed if it does not surpass the maxTurnDegreeVertical
    	if (FMath::Abs(PitchInput) < maxTurnDegreeVertical) 
    	{
    		const float NewForwardSpeed = CurrentForwardSpeed + CurrentAccForward;
    		CurrentForwardSpeed = FMath::Clamp(NewForwardSpeed, MinSpeed, MaxSpeed);
    	}
    	else
    	{
    		CurrentForwardSpeed = FMath::Max(CurrentForwardSpeed, MinSpeed);
    	}
}

void AFlyer_Base::CalculateLateralSpeed(float RollInput, float CurrentAccSide, float DeltaTime)
{
		// Apply LATERAL Speed only if airplane has a minimum of inclination
		if (FMath::Abs(RollInput) > minimumTurnDegreeHorizontal) 
		{
			//*deltaTime because it is currently accumulating acceleration
			CurrentSideSpeed = CurrentAccSide * DeltaTime;
		}
		else
		{
			CurrentSideSpeed = 0.f;
		}
}

void AFlyer_Base::calculate_debugging_axis_degree_inclination_speeds(float RollInput, float PitchInput, float YawEffect)
{
	if (GEngine)
	{
		FString DebugMessage = FString::Printf(TEXT("Forward Speed: %.2f, Side Speed: %.2f, Roll: %.2f, Pitch: %.2f, Yaw: %.2f"),
			CurrentForwardSpeed, CurrentSideSpeed, RollInput, PitchInput, YawEffect);
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, DebugMessage);
	}
}

void AFlyer_Base::ApplyMovement(float DeltaTime)
{
	//Apply movement
	const FVector LocalMove = FVector(
		CurrentForwardSpeed * DeltaTime,  // front movement
		CurrentSideSpeed * DeltaTime,     // lateral movement
		0.0f                              
	);

	//Apply this move to actor
	AddActorLocalOffset(LocalMove, true);
}

float AFlyer_Base::GetActorRotationRoll()
{
	return GetActorRotation().Roll;
}

float AFlyer_Base::GetActorRotationPitch()
{
	return GetActorRotation().Pitch;
}


// BeginPlay
void AFlyer_Base::BeginPlay()
{
    Super::BeginPlay();
    if (FlyerInputMappingContext)
    {
        // Add the input mapping context to the enhanced input subsystem
        if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
        {
            if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
            {
                Subsystem->AddMappingContext(FlyerInputMappingContext, 1);
            }
        }
    }


	//UI PAUSE MENU
	// Obtener el Gameplay_PlayerController
	GameplayController = Cast<AGameplay_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (!GameplayController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gameplay_PlayerController not found!"));
	}
	
}

// Tick
void AFlyer_Base::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    
	// 🛠️ 1️⃣ OBTENER LOS VALORES ACTUALES DE LOS EJES
	float RollInput = GetActorRotationRoll(); // Rotación actual en Roll
	float PitchInput = GetActorRotationRoll(); // Rotación actual en Pitch

	// 🌀 2️⃣ CÁLCULO DEL GIRO EN YAW BASADO EN ROLL
	float YawEffect = CalculateYawEffect_HorizontalInclination(RollInput, DeltaTime);
	

	//ACCELERATIONS
	float CurrentAccForward = CalculateAccelerationForward( PitchInput, PitchEffectMultiplier, DeltaTime);
	float CurrentAccSide = CalculateAccelerationSide(RollInput, DeltaTime, RollEffectMultiplier);



	// SPEED
		//Front
		CalculateFrontSpeed(PitchInput, CurrentAccForward);
		//Lateral
		CalculateLateralSpeed(RollInput,CurrentAccSide, DeltaTime);

	//Apply movement
	ApplyMovement(DeltaTime);

	// 🔽 6️⃣ Control of minimum height for  COLLISIONS
	if (CalculateHeightFromGround() <= minimumHeightToReduceSpeed)
	{
		CurrentForwardSpeed = 0.f;
		CurrentSideSpeed = 0.f;
	}

	calculate_debugging_axis_degree_inclination_speeds(RollInput,PitchInput,  YawEffect);
}

// SetupPlayerInputComponent
void AFlyer_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Bind Yaw (Horizontal Rotation)
        EnhancedInputComponent->BindAction(IA_Turn, ETriggerEvent::Triggered, this, &AFlyer_Base::HandleRollAxis_HorizontalInclination);
        // Bind Pitch (Vertical Rotation)
        EnhancedInputComponent->BindAction(IA_LookUp, ETriggerEvent::Triggered, this, &AFlyer_Base::HandlePitchAxis_VerticalInclination);
    	// Bind Pause Widget P
    	EnhancedInputComponent->BindAction(IA_PauseMenu, ETriggerEvent::Triggered, this, &AFlyer_Base::TogglePauseMenu);
    }
}

void AFlyer_Base::TogglePauseMenu()
{
	GameplayController->TogglePauseMenu();
}
