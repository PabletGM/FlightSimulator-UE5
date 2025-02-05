// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay_PlayerController.h"

#include "Kismet/GameplayStatics.h"

void AGameplay_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (AirplanePauseMenuWidgetTemplate)
	{
		// Create widget
		AirplanePauseMenuWidget = Cast<UAirplanePauseMenuWidget>(CreateWidget<UUserWidget>(this, AirplanePauseMenuWidgetTemplate));
		if (AirplanePauseMenuWidget)
		{
			AirplanePauseMenuWidget->AddToViewport();
			AirplanePauseMenuWidget->SetVisibility(ESlateVisibility::Hidden);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create AirplanePauseMenuWidget!"));
		}
	}
}


void AGameplay_PlayerController::TogglePauseMenu()
{
	if (!AirplanePauseMenuWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("AirplanePauseMenuWidget is null in TogglePauseMenu!"));
		return;
	}

	
		//show menu and pause game
		AirplanePauseMenuWidget->SetVisibility(ESlateVisibility::Visible);
		UGameplayStatics::SetGamePaused(GetWorld(), true);

		//Let Input for UI and Game
		bShowMouseCursor = true;
		FInputModeGameAndUI InputMode;
		InputMode.SetWidgetToFocus(AirplanePauseMenuWidget->TakeWidget());
		InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		SetInputMode(InputMode);
	
}
