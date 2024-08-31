// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h" 
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS() // �𸮾� ��ü���� ����
class HUIJUNPRACTICE_API AFountain : public AActor
{
	GENERATED_BODY() // �𸮾� ��ü���� ���� 
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; // Postinitialize -> Begin -> End
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnyWhere) // �𸮾� �������� �ڵ����� ��ü ���� �𸮾� ������Ʈ�� ����, VisibleAnyWhere�� ������ �����쿡�� �Ӽ� ���� ���� �� �� ����
		UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnyWhere)
		UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnyWhere)
		UPointLightComponent* Light;

	UPROPERTY(VisibleAnyWhere)
		UParticleSystemComponent* Splash;

	UPROPERTY(EditAnyWhere, Category=ID) // �𸮾� �����Ϳ��� �Ӽ��� �����͸� �����Ϸ��� VisibleAnywhere�� �ƴ� EditAnyWhere�� ����ؾ��� 
		//Category = �з��� ��Ģ����Ű���带 �߰��ϸ�, ������ �з����� �Ӽ����� ����
		int32 ID;
	UPROPERTY(VisibleAnyWhere)
		URotatingMovementComponent* Movement;

private:
	UPROPERTY(EditAnyWhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float RotateSpeed;

};
