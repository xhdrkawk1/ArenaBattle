// Fill out your copyright notice in the Description page of Project Settings.


#include "BTServie_Detect.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

UBTServie_Detect::UBTServie_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTServie_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(AABAIController::TargetKey, nullptr);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector Center = ControllingPawn->GetActorLocation();
	float DetactRadius = 600.f;

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParams(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel12,
		FCollisionShape::MakeSphere(DetactRadius),
		CollisionQueryParams
	);

	if (bResult)
	{
		for (auto const& OvelapResult : OverlapResults)
		{
			AABCharacter* ABCharacter = Cast<AABCharacter>(OvelapResult.GetActor());

			if (ABCharacter && ABCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AABAIController::TargetKey, ABCharacter);
				DrawDebugSphere(World, Center, DetactRadius, 16, FColor::Green, false, 0.2f);

				DrawDebugPoint(World, ABCharacter->GetActorLocation(), 10.f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), ABCharacter->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}

		}
	}

}
