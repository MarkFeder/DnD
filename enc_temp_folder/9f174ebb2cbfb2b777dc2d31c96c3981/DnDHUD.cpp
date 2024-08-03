#include "DnDHUD.h"
#include "Blueprint/UserWidget.h"

void ADnDHUD::BeginPlay()
{
    Super::BeginPlay();
    ShowMainWidget();
}

void ADnDHUD::ShowMainWidget()
{
    if (!MainWidgetClass)
    {
        return;
    }

    if (!MainWidget)
    {
        MainWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);
    }

    MainWidget->AddToViewport();
}
