#pragma once

#include "EAILevel.h"
#include "FMobDropTable.h"
#include "FMobInfoData.generated.h"

/**
 * @date 2022/10/23
 * @struct FMobAISettings
 * @brief 몬스터의 Behavior Tree에서 AI와 관련된 수치들을 조정할 때 사용될 구조체
 */
USTRUCT(BlueprintType)
struct FMobAISettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float PatrolMovementSpeed;

	UPROPERTY(BlueprintReadWrite)
	float TraceMovementSpeed;

	UPROPERTY(BlueprintReadWrite)
	float PatrolDistance;

	UPROPERTY(BlueprintReadWrite)
	float PlayerPerceptionDistance;

	UPROPERTY(BlueprintReadWrite)
	float MovablePerceptionDistance;

	UPROPERTY(BlueprintReadWrite)
	float SoundPerceptionDistance;

	UPROPERTY(BlueprintReadWrite)
	float SenseVolatility;

	UPROPERTY(BlueprintReadWrite)
	EAILevel AILevel;

	UPROPERTY(BlueprintReadWrite)
	float AttackRange;

	UPROPERTY(BlueprintReadWrite)
	float AttackCooldown;
	
};

/**
 * @date 2022/10/23
 * @struct FMobStats
 * @brief 몬스터의 메타데이터를 설정하는 구조체
 */
USTRUCT(BlueprintType)
struct FMobStats
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FString MobName;
	
	UPROPERTY(BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(BlueprintReadWrite)
	float HealthRegen;

	UPROPERTY(BlueprintReadWrite)
	float PhysicsDefence;
};

/**
 * @date 2022/10/23
 * @struct FMobInfoData
 * @brief 몬스터의 메타데이터, 드랍테이블, AI수치 등을 저장하는 래퍼 구조체
 */
USTRUCT(BlueprintType)
struct FMobInfoData
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite)
	FMobDropTable DropTable;

	UPROPERTY(BlueprintReadWrite)
	FMobStats MobStats;

	UPROPERTY(BlueprintReadWrite)
	FMobAISettings AISettings;
};

