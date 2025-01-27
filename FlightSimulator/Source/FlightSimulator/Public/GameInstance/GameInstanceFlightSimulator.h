
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "GameInstanceFlightSimulator.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHTSIMULATOR_API UGameInstanceFlightSimulator : public UGameInstance
{
	GENERATED_BODY()
	
	public:
	
	UPROPERTY()
	FString SelectedAirplaneName;
	
};
