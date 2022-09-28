// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Struct/FMobDropTable.h"
#include "Struct/FMobInfoData.h"
#include "GameFramework/Character.h"
#include "MobParent.generated.h"


/*
 * 1. 몬스터의 피격 및 사망
 * 몬스터가 맞으면 Hit가 실행되며, Hit 과정에서 Health가 0 이하로 떨어질 경우 자동으로 MobDead가 실행된다.
 * MobDead에서는 코인과 아이템 드랍에 대한 함수가 실행된다.
 *
 * 2. 몬스터의 공격
 * 몬스터의 공격은 자식 클래스에서 상속되어 구현되며, 공격이 진행되는 동안 BT의 실행을 스킵할 수 있는 BypassBehaviorTree함수를 실행할 수 있다.
 *
 * 3. 몬스터의 정보
 * 각 몬스터의 최대체력, 현재체력, 드랍테이블등은 모두 여기서 상속되어 설정한다.
 */

UCLASS()
class ENEMIESDROP_API AMobParent : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AMobParent();

	// 몬스터의 정보
	UPROPERTY(BlueprintReadWrite)
	float Health;

	UPROPERTY(BlueprintReadOnly)
	FMobInfoData MobInfoData;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FMobInfoData GetMobData();

	// 몬스터의 액션
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Hit(APawn* Victim, float Damage);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool Attack();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 몬스터의 액션(사망)
	UFUNCTION(BlueprintNativeEvent)
	void MobDead(APawn* Victim);

	void CoinDrop(FVector Location, float Min, float Max);

	void ItemDrop(FVector Location, TArray<FDropItem> Drops);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// GroundMobParent or FlyingMobParent에서 상속받아 구현할 내용
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PathFind"))
	virtual FVector PathFind();
};
