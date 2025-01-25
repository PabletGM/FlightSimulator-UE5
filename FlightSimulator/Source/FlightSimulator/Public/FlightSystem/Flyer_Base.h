// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Flyer_Base.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class FLIGHTSIMULATOR_API AFlyer_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFlyer_Base();

	UPROPERTY(EditAnywhere, Category = "Flight")
	float Acceleration{30.f};
	UPROPERTY(EditAnywhere, Category = "Flight")
	float MaxSpeed{4000.f};
	UPROPERTY(EditAnywhere, Category = "Flight")
	float MinSpeed{500.f};

	// Rotation multipliers
	UPROPERTY(EditAnywhere, Category = "Flight")
	float RollRateMultiplier{200.0f};
	UPROPERTY(EditAnywhere, Category = "Flight")
	float PitchRateMultiplier{200.0f};
	
	UPROPERTY(VisibleAnywhere, Category = "Flight")
	float CurrentForwardSpeed{100.f};

	UPROPERTY(VisibleAnywhere, Category = "Flight")
	float CurrentSideSpeed{100.f};
	

protected:

	// Input handling
	void HandleRollAxis_HorizontalInclination(const FInputActionValue& Value);  // A/D for Yaw
	void HandlePitchAxis_VerticalInclination(const FInputActionValue& Value); // W/S for Pitch
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Reference to Input Mapping Context
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* FlyerInputMappingContext;

	
    
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_Turn;
    
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_LookUp;


	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
