// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HuijunPractice.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "ABGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FABCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FABCharacterData(): Level(1), MaxHP(100.f), Attack(10.f), DropExp(10.f),NextExp(30) {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 DropExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 NextExp;
};

/**
 * 
 */
UCLASS()
class HUIJUNPRACTICE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UABGameInstance();
	FABCharacterData* GetABCharcterData(int32 Level);

	virtual void Init() override;

	FStreamableManager StreamableManager;

private:
	UPROPERTY()
		class UDataTable* ABCharacterTable;
};
