// Fill out your copyright notice in the Description page of Project Settings.


#include "MobParent.h"

#include "EnemiesDrop/RPGCharacter.h"

/**
 * @date 2022/10/23
 * @brief Flyable, Ground 몬스터의 부모 클래스
 *
 * @var Health 몬스터의 현재 체력
 * @var MobInfoData 몬스터의 데이터가 저장된 구조체
 * @var bIsAttackCooldown 몬스터의 공격이 쿨타임중인지 여부
 */
AMobParent::AMobParent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

/**
 * @date 2022/10/23
 * @brief 몬스터가 맞았을 때의 동작, 하위 몬스터 BP에서 상속받아 피격 소리나 이펙트를 재생한다.
 *
 * @param[in] Victim 몬스터를 공격한 폰
 * @param[in] Damage 입은 데미지
 */
void AMobParent::Hit_Implementation(APawn* Victim, float Damage)
{
	Health -= Damage;
	if(Health <= 0) MobDead(Victim);
}

/**
 * @date 2022/10/23
 * @brief 몬스터가 죽었을 때의 동작, 하위 몬스터 BP에서 상속받아 사망 소리나 이펙트를 재생한다.
 *  몬스터를 죽인 폰이 플레이어일 경우 드랍시퀀스와 경험치 지급을 실행한다.
 *
 * @param[in] Victim 몬스터를 죽인 폰
 */
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

/**
 * @date 2022/10/23
 * @brief 몬스터가 공격할 때의 동작, 하위 몬스터 BP에서 상속받아 공격 소리나 이펙트를 재생한다.
 *
 * @param[in] Target 공격하고자 하는 타겟 폰
 */
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

/**
 * @date 2022/10/23
 * @brief 몬스터가 죽었을 때 코인(화폐)를 떨어트린다.
 *
 * @param[in] Location 몬스터가 죽은 위치
 * @param[in] Min 최소 코인 드랍 개수
 * @param[in] Max 최대 코인 드랍 개수
 */
void AMobParent::CoinDrop(FVector Location, float Min, float Max)
{
}

/**
 * @date 2022/10/23
 * @brief 몬스터가 죽었을 때 아이템을 떨어트린다.
 *
 * @param[in] Location 몬스터가 죽은 위치
 * @param[in] Drops 몬스터의 드랍테이블
 */
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

