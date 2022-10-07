// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacter.h"


ARPGCharacter::ARPGCharacter()
{
	// Set default status values
	Level = 0;
	LevelUp();

	// Special skills are default unlocked.
	bUnlockSpecialOne = false;
	bUsableSpecialOne = false;
	bUnlockSpecialTwo = false;
	bUsableSpecialTwo = false;

	bPressingAttack = false;
	
}

void ARPGCharacter::LevelUp()
{
	Level += 1;
	if(Level == 1) CurrentExp = 0;
	else CurrentExp -= MaxExp;

	const int32 BaseHealth = 100;
	const int32 HealthMultiplier = 500;
	const int32 BaseMana = 100;
	const int32 ManaMultiplier = 30;
	const int64 BaseExp = 0;
	const int64 ExpMultiplier = 100;
	
	MaxHealth = BaseHealth + HealthMultiplier * FMath::Sqrt(Level);
	MaxMana = BaseMana + ManaMultiplier * Level;
	MaxExp = BaseExp + ExpMultiplier * FMath::Pow(Level, 2);
	
	CurrentHealth = MaxHealth;
	CurrentMana = MaxMana;
}

void ARPGCharacter::Heal(float Percentage)
{
	int ResultHealth = CurrentHealth + MaxHealth * (Percentage/100);
	int ResultMana = CurrentMana + MaxMana * (Percentage/100);
	CurrentHealth = ResultHealth >= MaxHealth ? MaxHealth : ResultHealth;
	CurrentMana = ResultMana >= MaxMana ? MaxMana : ResultMana;
}

void ARPGCharacter::ExpUp(int32 exp)
{
	CurrentExp += exp;
	while(CurrentExp >= MaxExp) LevelUp();
}
