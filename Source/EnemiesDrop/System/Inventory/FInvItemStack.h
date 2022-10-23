// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FInvItemStack.generated.h"

/**
 * @date 2022/10/23
 * @struct FInvItemStack
 * @brief 플레이어 인벤토리 내의 아이템 정보를 저장하기 위한 구조체
 */
class AItemBase;

USTRUCT(BlueprintType)
struct FInvItemStack
{
	GENERATED_BODY()

	UPROPERTY()
	AItemBase* Item;

	UPROPERTY()
	int32 MaxCount;

	UPROPERTY()
	int32 ItemCount;
	
};
