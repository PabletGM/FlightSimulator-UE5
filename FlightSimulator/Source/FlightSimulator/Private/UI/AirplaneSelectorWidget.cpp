// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AirplaneSelectorWidget.h"

#include "PlaneSelector_PlayerController.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Components/HorizontalBoxSlot.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBoxSlot.h"
#include "Kismet/GameplayStatics.h"




void UAirplaneSelectorWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (AirplaneTitleText)
    {
        AirplaneTitleText->SetText(FText::FromString(TEXT("Airplane Selector")));
        FSlateFontInfo FontInfo = AirplaneTitleText->Font;
        // FontInfo.Size = 120;
        AirplaneTitleText->SetFont(FontInfo);
    }
    InitializeButton(RightOptionButton, RightOptionButtonText, TEXT("Next"));
    InitializeButton(LeftOptionButton, LeftOptionButtonText, TEXT("Prev"));
    InitializeButton(PlayButton, PlayButtonText, TEXT("Play"));
    // ConfigureMargins();
}

void UAirplaneSelectorWidget::InitializeButton(UButton* Button, UTextBlock* ButtonText, const FString& ButtonTextString)
{
    if (Button && ButtonText)
    {
        ButtonText->SetText(FText::FromString(ButtonTextString));

        Button->OnHovered.AddDynamic(this, &UAirplaneSelectorWidget::OnButtonHovered);
        Button->OnUnhovered.AddDynamic(this, &UAirplaneSelectorWidget::OnButtonUnhovered);

        if (Button == RightOptionButton)
        {
            Button->OnClicked.AddDynamic(this, &UAirplaneSelectorWidget::RightOptionMethod);
        }
        else if (Button == LeftOptionButton)
        {
            Button->OnClicked.AddDynamic(this, &UAirplaneSelectorWidget::LeftOptionMethod);
        }
        else if (Button == PlayButton)
        {
            Button->OnClicked.AddDynamic(this, &UAirplaneSelectorWidget::PlayMethod);
        }
    }
}

void UAirplaneSelectorWidget::ConfigureMargins()
{
    if (ButtonContainerVerticalBox)
    {
        //Create the 2 slots of HorizontalBox for 2 buttons of -> and <-
        UHorizontalBoxSlot* RightOptionButtonSlot = Cast<UHorizontalBoxSlot>(RightOptionButton->Slot);
        if (RightOptionButtonSlot)
        {
            RightOptionButtonSlot->SetPadding(FMargin(0, 0, 0, 20));
        }
        UHorizontalBoxSlot* LeftOptionButtonSlot = Cast<UHorizontalBoxSlot>(LeftOptionButton->Slot);
        if (LeftOptionButtonSlot)
        {
            RightOptionButtonSlot->SetPadding(FMargin(0, 0, 0, 20));
        }

        
        //Create VerticalBox for HorizontalBoxSlot  and the selected button slot
        UVerticalBoxSlot* HorizontalBoxSlot = Cast<UVerticalBoxSlot>(ButtonContainerHorizontalBox->Slot);
        if (HorizontalBoxSlot)
        {
            HorizontalBoxSlot->SetPadding(FMargin(0, 0, 0, 20));
        }
    }
}

//TO DO
void UAirplaneSelectorWidget::RightOptionMethod()
{
    if (APlaneSelector_PlayerController* PC = Cast<APlaneSelector_PlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
    {
        PC->ChangeAirplaneRightChoice();

        // Actualiza el texto del widget
        if (AirplaneTitleText)
        {
            AirplaneTitleText->SetText(FText::FromString(PC->CurrentAirplaneName));
        }
    }
}

//TO DO
void UAirplaneSelectorWidget::LeftOptionMethod()
{
    if (APlaneSelector_PlayerController* PC = Cast<APlaneSelector_PlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
    {
        PC->ChangeAirplaneLeftChoice();

        // Actualiza el texto del widget
        if (AirplaneTitleText)
        {
            AirplaneTitleText->SetText(FText::FromString(PC->CurrentAirplaneName));
        }
    }
}

//TO DO
void UAirplaneSelectorWidget::PlayMethod()
{
    if (APlaneSelector_PlayerController* PC = Cast<APlaneSelector_PlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
    {
        PC->EnterLevelGameplay();
    }
}

void UAirplaneSelectorWidget::OnButtonHovered()
{
    if (RightOptionButton->IsHovered())
    {
        RightOptionButtonText->SetColorAndOpacity(FLinearColor(0.715693f, 0.964686f, 0.0f, 1.0f));
    }
    else if (LeftOptionButton->IsHovered())
    {
        LeftOptionButtonText->SetColorAndOpacity(FLinearColor(0.715693f, 0.964686f, 0.0f, 1.0f));
    }
    else if (PlayButton->IsHovered())
    {
        PlayButtonText->SetColorAndOpacity(FLinearColor(0.715693f, 0.964686f, 0.0f, 1.0f));
    }
}

void UAirplaneSelectorWidget::OnButtonUnhovered()
{
    RightOptionButtonText->SetColorAndOpacity(FLinearColor::White);
    LeftOptionButtonText->SetColorAndOpacity(FLinearColor::White);
    PlayButtonText->SetColorAndOpacity(FLinearColor::White);
}
