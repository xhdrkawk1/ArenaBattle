// Fill out your copyright notice in the Description page of Project Settings.


#include "ABCharacterStatComponent.h"
#include "ABGameInstance.h"

// Sets default values for this component's properties
UABCharacterStatComponent::UABCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;

	Level = 1;

	// ...
}


// Called when the game starts
void UABCharacterStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UABCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent(); 
	SetNewLevel(Level);
}

void UABCharacterStatComponent::SetNewLevel(int32 NewLevel)
{
	auto ABGameInstance = Cast<UABGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	ABCHECK(nullptr != ABGameInstance);
	CurrentStatData = ABGameInstance->GetABCharcterData(NewLevel);
	if (nullptr != CurrentStatData)
	{
		Level = NewLevel;
		SetHp(CurrentStatData->MaxHP);
	}
	else
	{
		ABLOG_S(Warning);
	}
}

void UABCharacterStatComponent::SetDamage(float NewDamage)
{
	ABCHECK(nullptr != CurrentStatData);
	SetHp(FMath::Clamp<float>(CurrentHP - NewDamage, 0.f, CurrentStatData->MaxHP));

}

void UABCharacterStatComponent::SetHp(float NewHP)
{
	CurrentHP = NewHP;
	OnChangedHP.Broadcast();

	if (CurrentHP <= 0.f)
	{
		OnHPIsZero.Broadcast();
	}
}

float UABCharacterStatComponent::GetHPRatio()
{
	return (CurrentStatData->MaxHP <= 0 ? 0.f : CurrentHP / CurrentStatData->MaxHP);
}

float UABCharacterStatComponent::GetAttack()
{
	ABCHECK(nullptr != CurrentStatData, 0.f);
	return CurrentStatData->Attack;
}


// Called every frame
void UABCharacterStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

