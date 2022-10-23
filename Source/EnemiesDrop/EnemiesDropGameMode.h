// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Item/ItemBase.h"
#include "System/Crafting/FCraftRecipe.h"
#include "EnemiesDropGameMode.generated.h"

UCLASS(minimalapi)
class AEnemiesDropGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEnemiesDropGameMode();

	UPROPERTY(BlueprintReadOnly, Category = "StageManage/Item")
	TMap<TSubclassOf<AItemBase>, AItemBase*> ItemDictionary;

	UPROPERTY(BlueprintReadOnly, Category = "StageManage/Craft")
	TArray<FCraftRecipe> CraftRecipes;

	UFUNCTION(BlueprintImplementableEvent, Category = "StageManage/Item")
	TArray<TSubclassOf<AItemBase>> RegisterItems();

	UFUNCTION(BlueprintCallable, Category = "StageManage/Item")
	AItemBase* GetItemDictionary(TSubclassOf<AItemBase> Key);

	UFUNCTION(BlueprintCallable, Category = "StageManage/Craft")
	void RegisterItemRecipe(FCraftRecipe Recipe);

	UFUNCTION(BlueprintCallable, Category = "StageManage/Craft")
	TArray<FCraftRecipe> GetAllRecipe();
	
	virtual void BeginPlay() override;
};



