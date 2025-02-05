// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AirplanePauseMenuWidget.generated.h"

/**
 * 
 */

class AGameplay_PlayerController;
class UButton;
class UTextBlock;
class UVerticalBoxSlot;
class AAudioManager;
UCLASS()
class FLIGHTSIMULATOR_API UAirplanePauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void InitializeButton(UButton* Button, UTextBlock* ButtonText, const FString& ButtonTextString);

	UFUNCTION()
	void OnButtonHovered();

	UFUNCTION()
	void OnButtonUnhovered();

	//Fuctions click button
	UFUNCTION()
	void BackToSelectorMethod();
	UFUNCTION()
	void ResumeMethod();

	UFUNCTION()
	void DelayMethod();

private:

	AAudioManager* AudioManager = nullptr;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PauseMenuText = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ButtonContainerVerticalBox = nullptr;

	//Buttons
	UPROPERTY(meta = (BindWidget))
	class UButton* BackToSelectorButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* ResumeButton = nullptr;

	//Text Buttons
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* BackToSelectorButtonText = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResumeButtonText = nullptr;
	
	//GameplayController
	AGameplay_PlayerController* GameplayController;

};
