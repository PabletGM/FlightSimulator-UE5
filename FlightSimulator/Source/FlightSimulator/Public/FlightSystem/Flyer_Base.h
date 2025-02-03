// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay_PlayerController.h"
#include "Flyer_Base.generated.h"

class UInputMappingContext;
class UInputAction;
class USceneComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UCapsuleComponent;
class AGameplay_PlayerController;
class UAirplanePauseMenuWidget;
class UGameInstanceFlightSimulator;

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
	float MinSpeed{800.f};

	// Rotation multipliers to make the effect input enough
	UPROPERTY(EditAnywhere, Category = "Flight")
	float RollRateMultiplier{20.0f};
	UPROPERTY(EditAnywhere, Category = "Flight")
	float PitchRateMultiplier{10.0f};

	//controls how much the Roll should affect the Yaw.
	UPROPERTY(EditAnywhere, Category = "Flight")
	float YawScalingFactor {0.1f};

	//controls acceleration multipliers
	UPROPERTY(EditAnywhere, Category = "Flight")
	float PitchEffectMultiplier = 1.f;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float RollEffectMultiplier = 100.f;


	//maximum degree turn on vertical to have forward velocity
	UPROPERTY(EditAnywhere, Category = "Flight")
	float maxTurnDegreeVertical = 80.0f;

	//minimum degree turn on horizontal to have lateral velocity
	UPROPERTY(EditAnywhere, Category = "Flight")
	float minimumTurnDegreeHorizontal = 10.0f;
	
	UPROPERTY(VisibleAnywhere, Category = "Flight")
	float CurrentForwardSpeed{100.f};

	UPROPERTY(VisibleAnywhere, Category = "Flight")
	float CurrentSideSpeed{100.f};


	//GameplayController
	AGameplay_PlayerController* GameplayController;

protected:
	float CalculateHeightFromGround();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flight")
	float CurrentHeight;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flight")
	float minimumHeightToReduceSpeed = 100.f;

protected:
	// Spring Arm Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArm;

	// Camera Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

	//ROOT
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;

	// Static Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* FlyerMesh;

	

	// Input handling
		// Change RollActorRotation
		void HandleRollAxis_HorizontalInclination(const FInputActionValue& Value);
		//Change PitchActorRotation
		void HandlePitchAxis_VerticalInclination(const FInputActionValue& Value);
		//change Yaw based on Roll
		float CalculateYawEffect_HorizontalInclination(float RollInput, float deltaTime);

	//calculate accelerations
		float CalculateAccelerationForward(float PitchInput, float deltaTime, float PitchEffectMultiplier);
		float CalculateAccelerationSide(float RollInput, float deltaTime, float RollEffectMultiplier);

	//calculate speed
		void CalculateFrontSpeed(float PitchInput, float CurrentAccForward );
		void CalculateLateralSpeed(float RollInput, float CurrentAccSide, float DeltaTime );
	
	//DEBUG
		void calculate_debugging_axis_degree_inclination_speeds(float RollInput, float PitchInput, float YawEffect);

	//Apply movement
		void ApplyMovement(float DeltaTime);

	//GETTERS
		//RollActorRotation
		float GetActorRotationRoll();
		//PitchActorRotation
		float GetActorRotationPitch();
	


	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Reference to Input Mapping Context
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* FlyerInputMappingContext;

	
    
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_Turn;
    
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_LookUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_PauseMenu;


	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TogglePauseMenu();
	

};
