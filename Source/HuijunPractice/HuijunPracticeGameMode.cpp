// Copyright Epic Games, Inc. All Rights Reserved.

#include "HuijunPracticeGameMode.h"
#include "HuijunPracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHuijunPracticeGameMode::AHuijunPracticeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
