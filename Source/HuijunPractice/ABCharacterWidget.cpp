// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacterWidget.h"
#include "ABCharacterStatComponent.h"
#include "Components/ProgressBar.h"

void UABCharacterWidget::BindCharacterStat(UABCharacterStatComponent* NewCharacterStat)
{
	ABCHECK(nullptr != NewCharacterStat);

	CurrentCharacterStat = NewCharacterStat;
	NewCharacterStat->OnChangedHP.AddLambda([this]() -> void {

		if (CurrentCharacterStat.IsValid())
		{
			ABLOG(Warning, TEXT("HPRatio: %f"), CurrentCharacterStat->GetHPRatio());
			auto HPbar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBAR")));
			HPbar->SetPercent(CurrentCharacterStat->GetHPRatio());
		}

		});
}

void UABCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
	auto HPbar = Cast<UProgressBar>(GetWidgetFromName(TEXT("PB_HPBAR")));
	HPbar->SetPercent(CurrentCharacterStat->GetHPRatio());
}
