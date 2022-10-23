// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FCraftIngredients.h"
#include "FCraftRecipe.generated.h"

/**
 * @date 2022/10/23
 * @struct FCraftRecipe
 * @brief 크래프팅 제작 레시피에 관한 구조체로 재료 목록, 결과, 결과물 개수, 성공확률이 저장된다.
 */
USTRUCT(BlueprintType)
struct FCraftRecipe
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FCraftIngredients> Ingredients;

	UPROPERTY()
	int32 ResultAmount;

	UPROPERTY()
	AItemBase* ResultItem;

	UPROPERTY()
	float SuccessChance;
	
};
