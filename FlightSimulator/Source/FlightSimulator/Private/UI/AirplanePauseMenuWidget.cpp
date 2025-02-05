// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AirplanePauseMenuWidget.h"
#include "Music/AudioManager.h"
#include "Gameplay_PlayerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBoxSlot.h"
#include "Kismet/GameplayStatics.h"

void UAirplanePauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (PauseMenuText)
	{
		PauseMenuText->SetText(FText::FromString(TEXT("Pause Menu")));
		FSlateFontInfo FontInfo = PauseMenuText->Font;
		// FontInfo.Size = 120;
		PauseMenuText->SetFont(FontInfo);
	}
	
	InitializeButton(BackToSelectorButton, BackToSelectorButtonText, TEXT("Back to Selector"));
	InitializeButton(ResumeButton, ResumeButtonText, TEXT("Resume"));


	// Obtener el Gameplay_PlayerController
	GameplayController = Cast<AGameplay_PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (!GameplayController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gameplay_PlayerController not found!"));
	}

	AudioManager = Cast<AAudioManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AAudioManager::StaticClass()));
}

void UAirplanePauseMenuWidget::InitializeButton(UButton* Button, UTextBlock* ButtonText,
	const FString& ButtonTextString)
{
	if (Button && ButtonText)
	{
		ButtonText->SetText(FText::FromString(ButtonTextString));

		Button->OnHovered.AddDynamic(this, &UAirplanePauseMenuWidget::OnButtonHovered);
		Button->OnUnhovered.AddDynamic(this, &UAirplanePauseMenuWidget::OnButtonUnhovered);

		if (Button == BackToSelectorButton)
		{
			Button->OnClicked.AddDynamic(this, &UAirplanePauseMenuWidget::BackToSelectorMethod);
		}
		else if (Button == ResumeButton)
		{
			Button->OnClicked.AddDynamic(this, &UAirplanePauseMenuWidget::ResumeMethod);
		}
	}
}

void UAirplanePauseMenuWidget::OnButtonHovered()
{
	if (BackToSelectorButton->IsHovered())
	{
		BackToSelectorButtonText->SetColorAndOpacity(FLinearColor(0.715693f, 0.964686f, 0.0f, 1.0f));
	}
	else if (ResumeButton->IsHovered())
	{
		ResumeButtonText->SetColorAndOpacity(FLinearColor(0.715693f, 0.964686f, 0.0f, 1.0f));
	}
}

void UAirplanePauseMenuWidget::OnButtonUnhovered()
{
	BackToSelectorButtonText->SetColorAndOpacity(FLinearColor::White);
	ResumeButtonText->SetColorAndOpacity(FLinearColor::White);
}

void UAirplanePauseMenuWidget::BackToSelectorMethod()
{
	DelayMethod();
}

void UAirplanePauseMenuWidget::ResumeMethod()
{
	if (AudioManager)
	{
		AudioManager->PlaySFX2(FText::FromString("clickButton"));
	}
	// Ocultar el menú y reanudar el juego
	SetVisibility(ESlateVisibility::Hidden);
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	// Desactivar el cursor del ratón y restaurar el input de juego
	GameplayController->bShowMouseCursor = false;
	GameplayController->SetInputMode(FInputModeGameOnly());

	UE_LOG(LogTemp, Log, TEXT("Game resumed"));
}

void UAirplanePauseMenuWidget::DelayMethod()
{
	const FName LevelName = TEXT("AirplaneSelector");

	if (GetWorld())
	{
		UE_LOG(LogTemp, Log, TEXT("Loading level: %s"), *LevelName.ToString());
		UGameplayStatics::OpenLevel(GetWorld(), LevelName);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load level: %s. World is null!"), *LevelName.ToString());
	}
}
