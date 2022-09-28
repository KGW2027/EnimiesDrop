#pragma once

#include "FMobDropTable.h"
#include "Mercuna/Public/Components/MercunaNavigationComponent.h"
#include "FMobInfoData.generated.h"

/*
 * 몬스터의 BehaviorTree 내 수치조정을 위한 구조체
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
	UMercunaNavigationComponent* NavigationComponent;
};

/*
 *	몬스터의 체력, 방어력 등 스텟을 설정하기 위한 구조체
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

/*
 * 몬스터의 정보를 저장하기 위한 구조체
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

