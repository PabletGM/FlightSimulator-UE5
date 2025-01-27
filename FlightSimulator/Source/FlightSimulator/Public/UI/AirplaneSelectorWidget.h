// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AirplaneSelectorWidget.generated.h"

/**
 * 
 */

class UButton;
class UTextBlock;
class UVerticalBoxSlot;
class UHorizontalBoxSlot;

UCLASS()
class FLIGHTSIMULATOR_API UAirplaneSelectorWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	void ConfigureMargins();

	void InitializeButton(UButton* Button, UTextBlock* ButtonText, const FString& ButtonTextString);

	UFUNCTION()
	void OnButtonHovered();

	UFUNCTION()
	void OnButtonUnhovered();

	//Fuctions click button
	UFUNCTION()
	void RightOptionMethod();
	UFUNCTION()
	void LeftOptionMethod();
	UFUNCTION()
	void PlayMethod();

private:

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* AirplaneTitleText = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ButtonContainerVerticalBox = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UHorizontalBox* ButtonContainerHorizontalBox = nullptr;

	//Buttons
	UPROPERTY(meta = (BindWidget))
	class UButton* RightOptionButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* LeftOptionButton = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UButton* PlayButton = nullptr;
	

	//Text Buttons
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* RightOptionButtonText = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* LeftOptionButtonText = nullptr;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayButtonText = nullptr;
	
};
