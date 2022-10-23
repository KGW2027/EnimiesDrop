// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EItemStatus.h"
#include "EnemiesDrop/RPGCharacter.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

/**
 * @date 2022/10/23
 * @brief 아이템의 기본적인 정보를 저장하는 클래스
 */
UCLASS()
class ENEMIESDROP_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	/** 아이템의 이름 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemInfo")
	FString ItemName;

	/** 아이템의 상태 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemInfo")
	EItemStatus ItemStatus;

	/** 아이템의 최대 스택사이즈 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemInfo")
	int32 MaxStackSize;

	/** 인벤토리, 제작대에서 표시될 아이템의 이미지 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemInfo")
	UTexture* ItemThumbnail;

	/** 아이템의 Static Mesh가 포함된 실제 액터 클래스 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemInfo|Real")
	TSubclassOf<AItemBase> ItemReal;

	/** 떨어져있는 아이템의 스택 사이즈 */
	UPROPERTY(BlueprintReadWrite, Category = "ItemInfo|Real")
	int32 DroppedCount;

	/**
	 * @date 2022/10/23
	 * @brief 초기실행 단계에서 아이템의 정보를 불러오기 위한 함수
	 *
	 * @param[out] Name 아이템의 이름
	 * @param[out] MaxStack 아이템의 최대 스택 사이즈
	 * @param[out] RealBP 아이템의 SM이 포함된 액터BP
	 * @param[out] Thumbnail 인벤토리 등에서 보여질 아이템 이미지
	 */
	UFUNCTION(BlueprintImplementableEvent, Category="ItemInfo")
	void InitializeItemData(FString &Name,
		int32& MaxStack,
		TSubclassOf<AItemBase>& RealBP,
		UTexture*& Thumbnail);

	/**
	 * @date 2022/10/23
	 * @brief 아이템을 주웠을 때 실행될 함수로 RealBP를 위한 함수이다. 자기자신 삭제, 폰 인벤토리에 추가 등을 수행
	 *
	 * @param[in] User 아이템을 주운 플레이어
	 */
	UFUNCTION(BlueprintCallable, Category="ItemInfo|Real")
	void PickupThis(ARPGCharacter* User);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
