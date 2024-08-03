#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DnDCharacterDataAsset.generated.h"

UENUM(BlueprintType)
enum class EDnDAbilityScore : uint8
{
    STR         UMETA(DisplayName = "Strength"),
    INT         UMETA(DisplayName = "Intelligence"),
    WIS         UMETA(DisplayName = "Wisdom"),
    DEX         UMETA(DisplayName = "Dexterity"),
    CON         UMETA(DisplayName = "Constitution"),
    CHA         UMETA(DisplayName = "Charisma")
};

UENUM(BlueprintType)
enum class EDnDCharacterRace : uint8
{
    Dwarf       UMETA(DisplayName = "Dwarf"),
    Elf         UMETA(DisplayName = "Elf"),
    Gnome       UMETA(DisplayName = "Gnome"),
    Halfling    UMETA(DisplayName = "Halfling"),
    Human       UMETA(DisplayName = "Human")
};

UENUM(BlueprintType)
enum class EDnDCharacterClass : uint8
{
    Bard        UMETA(DisplayName = "Bard"),
    Cleric      UMETA(DisplayName = "Cleric"),
    Druid       UMETA(DisplayName = "Druid"),
    Fighter     UMETA(DisplayName = "Fighter"),
    Ranger      UMETA(DisplayName = "Ranger"),
    Thief       UMETA(DisplayName = "Thief"),
    Wizard      UMETA(DisplayName = "Wizard")
};

UCLASS(BlueprintType)
class DND_API UDnDCharacterDataAsset : public UDataAsset
{
    GENERATED_BODY()
   
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    FString CharacterName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    UTexture2D* CharacterImage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    EDnDCharacterRace CharacterRace;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    EDnDCharacterClass CharacterClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character")
    TMap<EDnDAbilityScore, int32> CharacterAbilityScores;
};