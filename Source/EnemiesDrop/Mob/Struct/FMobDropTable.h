#pragma once


#include "EnemiesDrop/Item/ItemBase.h"
#include "FMobDropTable.generated.h"


/**
 * 몬스터의 드랍테이블 내 각 아이템들의 확률을 설정하기 위한 구조체
 */
USTRUCT(BlueprintType)
struct FDropItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AItemBase* Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Chance;
	
};

/*
 * 몬스터가 죽었을 때 보상처리를 위한 구조체
 */
USTRUCT(BlueprintType)
struct FMobDropTable
{
	GENERATED_BODY();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FDropItem> DropItems;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ExpDrop;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinCoinDrop;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxCoinDrop;
};

