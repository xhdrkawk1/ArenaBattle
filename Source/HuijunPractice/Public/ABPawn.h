// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HuijunPractice.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

UCLASS()
class HUIJUNPRACTICE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Collision)
		UCapsuleComponent* Capsule; // 충돌체
	
	UPROPERTY(VisibleAnywhere, Category = Visual)
		USkeletalMeshComponent* Mesh; // 매쉬

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UFloatingPawnMovement* Movement; // 움직임

	UPROPERTY(VisibleAnywhere, Category = Camera)
		USpringArmComponent* SpringArm; // 카메라 부착위치

	UPROPERTY(VisibleAnywhere, Category = Camera)
		UCameraComponent* Camera; // 카메라

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue); // 
};
