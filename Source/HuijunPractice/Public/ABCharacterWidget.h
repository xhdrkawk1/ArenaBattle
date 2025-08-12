// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HuijunPractice.h"
#include "Blueprint/UserWidget.h"
#include "ABCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class HUIJUNPRACTICE_API UABCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void BindCharacterStat(class UABCharacterStatComponent* NewCharacterStat);
protected:
	virtual void NativeConstruct() override;

private:
	TWeakObjectPtr<class UABCharacterStatComponent> CurrentCharacterStat;
};
