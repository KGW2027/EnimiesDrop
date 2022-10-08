// Fill out your copyright notice in the Description page of Project Settings.


#include "MobParent.h"

#include "EnemiesDrop/RPGCharacter.h"

// Sets default values
AMobParent::AMobParent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMobParent::Hit_Implementation(APawn* Victim, float Damage)
{

	Health -= Damage;
	if(Health <= 0) MobDead(Victim);
}

void AMobParent::MobDead_Implementation(APawn* Victim)
{
	ARPGCharacter* Player;
	if((Player = Cast<ARPGCharacter>(Victim)) != nullptr)
	{
		Player->ExpUp(MobInfoData.DropTable.ExpDrop);
		CoinDrop(GetActorLocation(), MobInfoData.DropTable.MinCoinDrop, MobInfoData.DropTable.MaxCoinDrop);
		ItemDrop(GetActorLocation(), MobInfoData.DropTable.DropItems);
	}
	
	Destroy(true);
}


bool AMobParent::Attack_Implementation(APawn* Target)
{
	bIsAttackCooldown = true;
	FTimerHandle AtkCoolHandle;
	float Time = GetMobData().AISettings.AttackCooldown;
	GetWorld()->GetTimerManager().SetTimer(AtkCoolHandle, FTimerDelegate::CreateLambda([&]()
	{
		bIsAttackCooldown = false;
	}), Time, false);
	
	return true;
}

// Called when the game starts or when spawned
void AMobParent::BeginPlay()
{
	MobInfoData = GetMobData();
	Health = MobInfoData.MobStats.MaxHealth;
	bIsAttackCooldown = false;
	
	Super::BeginPlay();
	
}

void AMobParent::CoinDrop(FVector Location, float Min, float Max)
{
}

void AMobParent::ItemDrop(FVector Location, TArray<FDropItem> Drops)
{
}

// Called every frame
void AMobParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMobParent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector AMobParent::PathFind()
{
	return FVector(-1,-1, -1);
}

