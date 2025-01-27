// Copyright Epic Games, Inc. All Rights Reserved.


#include "FlightSimulatorGameModeBase.h"


#include "GameInstance/GameInstanceFlightSimulator.h"




AFlightSimulatorGameModeBase::AFlightSimulatorGameModeBase()
{
	
}


void AFlightSimulatorGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	// Access the GameInstance
	if (UGameInstance* GI = GetGameInstance())
	{
		UGameInstanceFlightSimulator* MyGI = Cast<UGameInstanceFlightSimulator>(GI);
		if (MyGI)
		{
			FString SelectedAirplaneName = MyGI->SelectedAirplaneName;

			// Dynamically set the DefaultPawnClass based on the selected airplane
			if (!SelectedAirplaneName.IsEmpty())
			{
				if(AirplaneMap.Contains(SelectedAirplaneName))
				{
					SelectedAirplaneClass = AirplaneMap[SelectedAirplaneName];
				}

				if (SelectedAirplaneClass)
				{
					DefaultPawnClass = SelectedAirplaneClass;
					UE_LOG(LogTemp, Log, TEXT("DefaultPawnClass set to: %s"), *SelectedAirplaneClass->GetName());
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("SelectedAirplaneClass is invalid!"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("No airplane selected in GameInstance."));
			}
		}
	}
}

