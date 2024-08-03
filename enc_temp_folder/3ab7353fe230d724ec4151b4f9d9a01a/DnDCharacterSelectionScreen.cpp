#include "DnDCharacterSelectionScreen.h"

#include "Components/Image.h"
#include "Components/Button.h"

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
    if (CharacterListView)
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
}

void UDnDCharacterSelectionScreen::OnCharacterSelected(int32 CharacterIndex)
{
    UpdateCharacterPreview(CharacterIndex);
}

void UDnDCharacterSelectionScreen::UpdateCharacterPreview(int32 CharacterIndex)
{
    if (CharacterDataAssets.IsValidIndex(CharacterIndex) && CharacterPreviewImage)
    {
        UDnDCharacterDataAsset* SelectedCharacter = CharacterDataAssets[CharacterIndex];

        CharacterPreviewImage->SetBrushFromTexture(SelectedCharacter->Preview);
        CharacterPreviewImage->SetVisibility(SelectedCharacter->Preview ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
    }
}

void UDnDCharacterSelectionScreen::OnPlayButtonClicked()
{
    // Handle play button click
}