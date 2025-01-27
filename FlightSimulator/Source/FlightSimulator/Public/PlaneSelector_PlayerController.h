// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Blueprint/UserWidget.h"
#include "UI/AirplaneSelectorWidget.h"
#include "PlaneSelector_PlayerController.generated.h"

class UAirplaneSelectorWidget;
class UInputAction;
class UInputMappingContext;
class APlaneSelector_PlayerController;
/**
 * 
 */
UCLASS()
class FLIGHTSIMULATOR_API APlaneSelector_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// Called to bind functionality to input, in the PlayerController, you call it manually
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) ;

	//INPUT
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_Enter;
    
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_RightChoice;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* IA_LeftChoice;


	//TMAP SELECTOR
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Airplanes")
	TMap<FString, TSubclassOf<AActor>> AirplaneMap;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Airplanes")
	FString CurrentAirplaneName;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Airplanes");
	TSubclassOf<AActor> CurrentAirplaneClass;

	//by default
	FVector SpawnLocation = FVector(-251460.0f, -2490.0f, 700970.0f);

	UPROPERTY()
	AActor* CurrentSpawnedAirplane = nullptr;
	
	//Input methods
	void ChangeAirplaneRightChoice();

	void ChangeAirplaneLeftChoice();

	void EnterLevelGameplay();

	void SpawnCurrentAirplane();
	

	UPROPERTY(EditDefaultsOnly) TSubclassOf<UAirplaneSelectorWidget> AirplaneSelectorWidgetTemplate = nullptr;
	
	UPROPERTY()
	UAirplaneSelectorWidget* AirplaneSelectorWidget = nullptr;
};
