// Fill out your copyright notice in the Description page of Project Settings.

#include "FlightSimulator/Public/FlightSystem/Flyer_Base.h"


// Constructor
AFlyer_Base::AFlyer_Base()
{
    // Enable ticking every frame
    PrimaryActorTick.bCanEverTick = true;
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
	if(GetActorRotation().Roll < 150 || GetActorRotation().Roll > -150)
	{
		const float NewForwardSpeed = CurrentForwardSpeed + CurrentAccForward;
		CurrentForwardSpeed = FMath::Clamp(NewForwardSpeed, MinSpeed, MaxSpeed);
	}
	else
	{
		CurrentForwardSpeed= 300.f;
	}
	
	//calculate new side speed if there is any inclination more than 10 grades or -10 grades
	if(GetActorRotation().Roll > 20 || GetActorRotation().Roll < -20)
	{
		const float NewSideSpeed = CurrentSideSpeed + CurrentAccSide;
		CurrentSideSpeed = FMath::Clamp(NewSideSpeed, MinSpeed, MaxSpeed);
	}
	else
	{
		CurrentSideSpeed = 0;
	}

	

	const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaTime,0,CurrentSideSpeed * DeltaTime);
    AddActorLocalOffset(LocalMove,true);

	//GEngine->AddOnScreenDebugMessage(0,0, FColor::Green, FString::Printf(TEXT("ForwardSpeed: %f"), CurrentForwardSpeed));
	//GEngine->AddOnScreenDebugMessage(0,0, FColor::Green, FString::Printf(TEXT("SideSpeed: %f"), CurrentSideSpeed));
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