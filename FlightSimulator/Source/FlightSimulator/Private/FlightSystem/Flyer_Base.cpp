// Fill out your copyright notice in the Description page of Project Settings.

#include "FlightSimulator/Public/FlightSystem/Flyer_Base.h"

#include "Components/CapsuleComponent.h"


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
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    // Create the Camera and attach to the SpringArm
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false;
}



float AFlyer_Base::CalculateHeightFromGround()
{
	FVector Start = GetActorLocation(); // Posición actual del actor
	FVector End = Start - FVector(0.0f, 0.0f, 100000.0f); // Traza hacia abajo

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this); // Ignorar el propio actor

	// Realizar el trace
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams))
	{
		// Si colisiona con algo, calcula la distancia
		return (Start - HitResult.Location).Size();
	}

	// Si no colisiona, devuelve una altura muy grande (indicando que no hay suelo debajo)
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
                Subsystem->AddMappingContext(FlyerInputMappingContext, 0);
            }
        }
    }
   
}

// Tick
void AFlyer_Base::Tick(float DeltaTime)
{
    
    Super::Tick(DeltaTime);

    //Calculate accelerations
    const float CurrentAccForward = -GetActorRotation().Pitch * DeltaTime * Acceleration;

	const float CurrentAccSide = -GetActorRotation().Roll * DeltaTime * Acceleration;
	
	//calculate new forward speed if it is not in vertical, 180 grades or -180 grades
	if(GetActorRotation().Roll < 160 || GetActorRotation().Roll > -160)
	{
		const float NewForwardSpeed = CurrentForwardSpeed + CurrentAccForward;
		CurrentForwardSpeed = FMath::Clamp(NewForwardSpeed, MinSpeed, MaxSpeed);
	}
	else
	{
		//minimum of forward speed
		CurrentForwardSpeed= 10.f;
	}
	
	//calculate new side speed if there is any inclination more than 40 grades or -40 grades
	if(GetActorRotation().Roll > 20 || GetActorRotation().Roll < -20)
	{
		const float NewSideSpeed = CurrentSideSpeed + CurrentAccSide;
		CurrentSideSpeed = FMath::Clamp(NewSideSpeed, MinSpeed, MaxSpeed);
	}
	else
	{
		//minimum of sideSpeed
		CurrentSideSpeed = 100.f;
	}

	

	const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaTime,0,CurrentSideSpeed * DeltaTime);
    AddActorLocalOffset(LocalMove,true);

	//check of height if it is near the ground to reduce speed
	if(CalculateHeightFromGround() <=minimumHeightToReduceSpeed)
	{
		CurrentForwardSpeed= 0.f;
		CurrentSideSpeed = 0.f;
	}
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
    	
	}
}