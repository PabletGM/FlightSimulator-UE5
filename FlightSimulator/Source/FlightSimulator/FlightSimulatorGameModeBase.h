// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FlightSystem/Flyer_Base.h"
#include "FlightSimulatorGameModeBase.generated.h"

/**
 * 
 */
class UGameInstanceFlightSimulator;
class AFlyer_Base;
UCLASS()
class FLIGHTSIMULATOR_API AFlightSimulatorGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	AFlightSimulatorGameModeBase();
	
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
public:
	// Map for airplane names and their corresponding blueprints
	UPROPERTY(EditDefaultsOnly, Category = "Airplanes")
	TMap<FString, TSubclassOf<AActor>> AirplaneMap;

	// Reference to the selected airplane blueprint
	UPROPERTY(BlueprintReadOnly, Category = "Airplanes")
	TSubclassOf<AActor> SelectedAirplaneClass;
};
