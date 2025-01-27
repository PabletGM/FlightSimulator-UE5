// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/AirplaneSelector_GameMode.h"

AAirplaneSelector_GameMode::AAirplaneSelector_GameMode()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprints/PlayerController/BP_Selector_PlayerController"));
	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}
