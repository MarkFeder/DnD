#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DnDCharacterSelectionScreen.generated.h"

class UButton;
class UDnDButtonBase;
class UDnDCharacterDataAsset;
class UImage;
class UDnDListViewBase;

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
    void UpdateCharacterPreview(int32 CharacterIndex);

    UFUNCTION()
    void OnPlayButtonClicked();
};
