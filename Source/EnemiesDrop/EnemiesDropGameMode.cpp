// Copyright Epic Games, Inc. All Rights Reserved.

#include "EnemiesDropGameMode.h"
#include "EnemiesDropCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEnemiesDropGameMode::AEnemiesDropGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_BaseCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
