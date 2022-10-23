

#pragma once

#include "CoreMinimal.h"
#include "EAILevel.generated.h"

/**
 * @date 2022/10/23
 * @brief 몬스터의 AI수준을 설정하기 위한 열거형
 */
UENUM(BlueprintType)
enum class EAILevel : uint8
{
	/** 가장 멍청한 수준, 플레이어 추격에서 직진 */
	LEVEL_1 UMETA(DisplayName="Stupid"),

	/** 일반적인 수준, 좌우로 흔들면서 온다. */
	LEVEL_2 UMETA(DisplayName="Basic"),

	/** 똑똑한 수준, 거리가 멀 때 플레이어가 자신을 바라보면 시야에서 벗어나기 위해 움직인다. */
	LEVEL_3 UMETA(DisplayName="PRO"),
};
