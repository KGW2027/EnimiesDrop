#pragma once

#include "EItemStatus.generated.h"

/**
 * @date 2022/10/23
 * @brief 아이템의 상태를 설정하는 Enum
 */
UENUM(BlueprintType)
enum class EItemStatus : uint8
{
	/** 땅에 떨어진 상태 */
	Dropped,

	/** 인벤토리에 저장된 상태 */
	ItemStack,

	/** 아이템을 손에 든 상태 */
	Using
};
