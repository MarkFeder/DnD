#include "DnDCharacterSelectionScreen.h"

#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "DnD/Core/DnDCharacterDataAsset.h"
#include "DnDListViewBase.h"
#include "DnDButtonBase.h"

#include "Engine/World.h"

void UDnDCharacterSelectionScreen::NativeConstruct()
{
    Super::NativeConstruct();

    PopulateCharacterList();

    if (PlayButton)
    {
        PlayButton->OnClicked.AddDynamic(this, &UDnDCharacterSelectionScreen::OnPlayButtonClicked);
    }
}

void UDnDCharacterSelectionScreen::PopulateCharacterList()
{
	CharacterListView->ClearListItems();

	for (auto& CharacterData : CharacterDataAssets)
	{
		UDnDButtonBase* ButtonBaseWidget = CreateWidget<UDnDButtonBase>(this, DnDButtonBaseClass);
		if (!ButtonBaseWidget)
		{
			UE_LOG(LogTemp, Warning, TEXT("Invalid ButtonBaseWidget for the following CharacterData: %s"), *(CharacterData->Name.ToString()));
			continue;
		}

        ButtonBaseWidget->SetBackgroundImage(CharacterData->Portrait);
		CharacterListView->AddItem(ButtonBaseWidget);
	}
}

void UDnDCharacterSelectionScreen::OnCharacterSelected(int32 CharacterIndex)
{
    UpdateCharacter(CharacterIndex);
}

void UDnDCharacterSelectionScreen::UpdateCharacter(int32 CharacterIndex)
{
    if (!CharacterDataAssets.IsValidIndex(CharacterIndex))
    {
        UE_LOG(LogTemp, Warning, TEXT("CharacterIndex is not valid"));
        return;
    }

    UDnDCharacterDataAsset* SelectedCharacter = CharacterDataAssets[CharacterIndex];

    CharacterPreviewImage->SetBrushFromTexture(SelectedCharacter->Preview);
    CharacterPreviewImage->SetVisibility(SelectedCharacter->Preview ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);

    CharacterName->SetText(SelectedCharacter->Name);

    CharacterRace->SetText(DnDUIUtils::ConvertRaceToText(SelectedCharacter->Race));
    CharacterClass->SetText(DnDUIUtils::ConvertClassToText(SelectedCharacter->Class));

    FText InvalidAbilityScore = FText::AsNumber(-1);

    CharacterSTR->SetText(SelectedCharacter->AbilityScores.Contains(EDnDAbilityScore::STR) ? FText::AsNumber(SelectedCharacter->AbilityScores[EDnDAbilityScore::STR]) : InvalidAbilityScore);
    CharacterINT->SetText(SelectedCharacter->AbilityScores.Contains(EDnDAbilityScore::INT) ? FText::AsNumber(SelectedCharacter->AbilityScores[EDnDAbilityScore::INT]) : InvalidAbilityScore);
    CharacterWIS->SetText(SelectedCharacter->AbilityScores.Contains(EDnDAbilityScore::WIS) ? FText::AsNumber(SelectedCharacter->AbilityScores[EDnDAbilityScore::WIS]) : InvalidAbilityScore);
    CharacterDEX->SetText(SelectedCharacter->AbilityScores.Contains(EDnDAbilityScore::DEX) ? FText::AsNumber(SelectedCharacter->AbilityScores[EDnDAbilityScore::DEX]) : InvalidAbilityScore);
    CharacterCON->SetText(SelectedCharacter->AbilityScores.Contains(EDnDAbilityScore::CON) ? FText::AsNumber(SelectedCharacter->AbilityScores[EDnDAbilityScore::CON]) : InvalidAbilityScore);
    CharacterCHA->SetText(SelectedCharacter->AbilityScores.Contains(EDnDAbilityScore::CHA) ? FText::AsNumber(SelectedCharacter->AbilityScores[EDnDAbilityScore::CHA]) : InvalidAbilityScore);
}

void UDnDCharacterSelectionScreen::OnPlayButtonClicked()
{
    // Handle play button click
}