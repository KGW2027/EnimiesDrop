// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemiesDropCharacter.h"
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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	float CurrentHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	float CurrentMana;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	int64 CurrentExp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Character)
	float MaxHealth;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Character)
	float MaxMana;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Character)
	int64 MaxExp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	int Level;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	bool bUnlockSpecialOne;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	bool bUsableSpecialOne;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	bool bUnlockSpecialTwo;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category=Character)
	bool bUsableSpecialTwo;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	bool bPressingAttack;

	UFUNCTION(BlueprintCallable)
	void LevelUp();

	UFUNCTION(BlueprintCallable)
	void Heal(float Percentage);

	UFUNCTION(BlueprintCallable)
	void ExpUp(int32 exp);
};
