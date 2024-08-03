#include "DnDHUD.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void ADnDHUD::BeginPlay()
{
    Super::BeginPlay();
    ShowMainWidget();
}

void ADnDHUD::ShowMainWidget()
{
    if (!MainWidgetClass)
    {
        UE_LOG(LogTemp, Error, TEXT("There's not MainWidgetClass configured for our HUD."));
        return;
    }

    if (!MainWidget)
    {
        MainWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);
    }

    UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(GetOwningPlayerController(), MainWidget);
    MainWidget->AddToViewport();
}
