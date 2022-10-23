// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemiesDrop/Item/ItemBase.h"
#include "FCraftIngredients.generated.h"

/**
 * @date 2022/10/23
 * @struct FCraftIngredients
 * @brief 크래프팅 제작 재료 설정을 위한 구조체
 */
USTRUCT(BlueprintType)
struct FCraftIngredients
{
	GENERATED_BODY()

	UPROPERTY()
	AItemBase* IngredientItem;

	UPROPERTY()
	int IngredientCount;
};
