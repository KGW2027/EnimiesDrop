

#pragma once

#include "CoreMinimal.h"
#include "EAILevel.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EAILevel : uint8
{
	LEVEL_1 UMETA(DisplayName="Stupid"),
	LEVEL_2 UMETA(DisplayName="Basic"),
	LEVEL_3 UMETA(DisplayName="PRO"),
};
