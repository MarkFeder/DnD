#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "DnDButtonBase.generated.h"

class UBorder;
class UImage;
class UTexture2D;

UCLASS(Blueprintable)
class DND_API UDnDButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetBackgroundImage(UTexture2D* InBackgroundImageTexture);

protected:

	virtual void NativeOnSelected(bool bBroadcast) override;
	virtual void NativeOnDeselected(bool bBroadcast) override;

protected:
	
    UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
    UImage* BackgroundImage;

	UPROPERTY(BlueprintReadOnly, Category="Widgets", meta=(BindWidget))
	UBorder* PortraitBorder;

	UPROPERTY(BlueprintReadOnly, Category="Border")
    FLinearColor DefaultBorderColor = FLinearColor::White;

	UPROPERTY(BlueprintReadOnly, Category="Border")
	FLinearColor SelectedBorderColor = FLinearColor::Red;
};