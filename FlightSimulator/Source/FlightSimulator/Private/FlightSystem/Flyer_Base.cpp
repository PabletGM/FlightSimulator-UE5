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
    // Print the value on the screen
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("HandleYaw InputValue: %f"), InputValue));
    }
    AddControllerRollInput(InputValue * RollRateMultiplier * GetWorld()->GetDeltaSeconds());
    
}

//IT WORKS, the vertical inclination
void AFlyer_Base::HandlePitchAxis_VerticalInclination(const FInputActionValue& Value)
{
    float InputValue = Value.Get<float>();
    // Print the value on the screen
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("HandleYaw InputValue: %f"), InputValue));
    }
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