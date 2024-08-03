#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DnDCharacterSelectionScreen.generated.h"

class UButton;
class UDnDButtonBase;
class UDnDCharacterDataAsset;
class UImage;
class UDnDListViewBase;
class UTextBlock;

UCLASS()
class DND_API UDnDCharacterSelectionScreen : public UUserWidget
{
    GENERATED_BODY()

protected:

    virtual void NativeConstruct() override;

protected:

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UDnDListViewBase* CharacterListView;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UImage* CharacterPreviewImage;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterName;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterRace;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterClass;

    ///////////////////////////////////////////////////////////////////

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterSTR;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterINT;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterWIS;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterDEX;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterCON;

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UTextBlock* CharacterCHA;

    ///////////////////////////////////////////////////////////////////

    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UButton* PlayButton;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Widgets")
    TSubclassOf<UDnDButtonBase> DnDButtonBaseClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Data")
    TArray<UDnDCharacterDataAsset*> CharacterDataAssets;

private:

    UFUNCTION(BlueprintCallable)
    void OnCharacterSelected(int32 CharacterIndex);

    UFUNCTION()
    void PopulateCharacterList();

    UFUNCTION()
    void UpdateCharacter(int32 CharacterIndex);

    UFUNCTION()
    void OnPlayButtonClicked();
};
