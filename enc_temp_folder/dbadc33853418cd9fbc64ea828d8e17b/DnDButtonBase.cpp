#include "DnDButtonBase.h"
#include "Components/Image.h"
#include "Components/Border.h"
#include "Engine/Texture2D.h"

void UDnDButtonBase::SetBackgroundImage(UTexture2D* InBackgroundImageTexture)
{
	if (!InBackgroundImageTexture)
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid BackgroundImageTexture"));
		return;
	}

	BackgroundImage->SetBrushFromTexture(InBackgroundImageTexture);
	BackgroundImage->SetVisibility(InBackgroundImageTexture ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
}

void UDnDButtonBase::NativeOnSelected(bool bBroadcast)
{
	Super::NativeOnSelected(bBroadcast);
	PortraitBorder->SetBrushColor(SelectedBorderColor);
}

void UDnDButtonBase::NativeOnDeselected(bool bBroadcast)
{
	Super::NativeOnDeselected(bBroadcast);
	PortraitBorder->SetBrushColor(DefaultBorderColor);
}