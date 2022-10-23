// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System/Inventory/FInvItemStack.h"
#include "EnemiesDropCharacter.h"
#include "System/Inventory/FInventory.h"
#include "RPGCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ENEMIESDROP_API ARPGCharacter : public AEnemiesDropCharacter
{
	GENERATED_BODY()
	
public:
	ARPGCharacter();
	
	// RPG Character Status
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character|Status")
	float CurrentHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character|Status")
	float CurrentMana;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character|Status")
	int64 CurrentExp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character|Status")
	float MaxHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character|Status")
	float MaxMana;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character|Status")
	int64 MaxExp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character|Status")
	int Level;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Character|Action")
	bool bPressingAttack;

	UPROPERTY(BlueprintReadWrite, Category="Character|Status")
	FInventory Inventory;

	UFUNCTION(BlueprintCallable, Category="Character|Status")
	void LevelUp();

	UFUNCTION(BlueprintCallable, Category="Character|Status")
	void Heal(float Percentage);

	UFUNCTION(BlueprintCallable, Category="Character|Status")
	void ExpUp(int32 Exp);

	UFUNCTION(Category="Character|Action")
	bool PickupItem(FInvItemStack ItemInfo);
};
