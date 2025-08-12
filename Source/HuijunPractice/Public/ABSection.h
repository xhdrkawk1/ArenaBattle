// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HuijunPractice.h"
#include "GameFramework/Actor.h"
#include "ABSection.generated.h"

UCLASS()
class HUIJUNPRACTICE_API AABSection : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABSection();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	enum class ESectionState : uint8
	{
		READY = 0,
		BATTLE,
		COMPLETE
	};

	void SetState(ESectionState NewState);
	ESectionState CurrentState = ESectionState::READY;

	void OperateGates(bool bOpen = true);

	void OnNPCSpawn();

private:
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UBoxComponent* Trigger;


	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		TArray<UStaticMeshComponent*> GateMeshes;

	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		TArray<UBoxComponent*> GateTriggers;

	UPROPERTY(EditAnywhere, Category = State, Meta = (AllowPrivateAccess = true))
		bool bNoBattle;

	UFUNCTION()
		void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OhterBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnGateTriggerBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OhterBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
		float EnemySpawnTime;

	UPROPERTY(EditAnywhere, Category = Spawn, Meta = (AllowPrivateAccess = true))
		float ItemBoxSpawnTime;

	FTimerHandle SPawnNPCTimerHandle = {};
	FTimerHandle SpawnItemBoxTimerHandle = {};
};
