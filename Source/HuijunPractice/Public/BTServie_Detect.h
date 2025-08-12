// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HuijunPractice.h"
#include "BehaviorTree/BTService.h"
#include "BTServie_Detect.generated.h"

/**
 * 
 */
UCLASS()
class HUIJUNPRACTICE_API UBTServie_Detect : public UBTService
{
	GENERATED_BODY()

public:
	UBTServie_Detect();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	
};
