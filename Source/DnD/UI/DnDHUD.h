#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DnDHUD.generated.h"

class UUserWidget;
class UDnDCharacterSelectionScreen;

UCLASS()
class DND_API ADnDHUD : public AHUD
{
	GENERATED_BODY()
	
protected:

    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    void ShowMainWidget();

private:

    UPROPERTY(EditAnywhere, Category="Widgets")
    TSubclassOf<UUserWidget> MainWidgetClass;

    UPROPERTY()
    UUserWidget* MainWidget;
};
