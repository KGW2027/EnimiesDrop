// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FInvItemStack.h"
#include "FInventory.generated.h"

/**
 * @date 2022/10/23
 * @struct FInventory
 * @brief 플레이어의 인벤토리 기능 구현을 위한 구조체
 */
class AItemBase;

USTRUCT(BlueprintType)
struct FInventory
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<FInvItemStack> Inventories;

	UPROPERTY()
	FInvItemStack HeldItem;

	UPROPERTY()
	FInvItemStack ThrowItem;

	UPROPERTY()
	FInvItemStack HeadItem;

	UPROPERTY()
	TArray<FInvItemStack> ConsumeItem;
	
};
