// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/AirplanePauseMenuWidget.h"
#include "Gameplay_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHTSIMULATOR_API AGameplay_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	//UI PAUSE MENU
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UAirplanePauseMenuWidget> AirplanePauseMenuWidgetTemplate;

	UPROPERTY()
	UAirplanePauseMenuWidget* AirplanePauseMenuWidget;
	
	//PAUSE MENU
    void TogglePauseMenu();

public:
	virtual void BeginPlay() override;
	
};
