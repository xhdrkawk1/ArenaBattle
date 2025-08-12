// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h" 
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS() // 언리얼 객체임을 선언
class HUIJUNPRACTICE_API AFountain : public AActor
{
	GENERATED_BODY() // 언리얼 객체임을 선언 
	
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

	UPROPERTY(VisibleAnyWhere) // 언리얼 엔진에서 자동으로 객체 관리 언리얼 오브젝트만 가능, VisibleAnyWhere을 디테일 윈도우에서 속성 값을 편집 할 수 있음
		UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnyWhere)
		UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnyWhere)
		UPointLightComponent* Light;

	UPROPERTY(VisibleAnyWhere)
		UParticleSystemComponent* Splash;

	UPROPERTY(EditAnyWhere, Category=ID) // 언리얼 에디터에서 속성의 데이터를 변경하려면 VisibleAnywhere가 아닌 EditAnyWhere을 사용해야함 
		//Category = 분류명 규칙으로키워드를 추가하면, 지정한 분류에서 속성값을 관리
		int32 ID;
	UPROPERTY(VisibleAnyWhere)
		URotatingMovementComponent* Movement;

private:
	UPROPERTY(EditAnyWhere, Category = Stat, Meta = (AllowPrivateAccess = true))
		float RotateSpeed;

};
