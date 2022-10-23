// Copyright Epic Games, Inc. All Rights Reserved.

#include "EnemiesDropGameMode.h"

/**
 * @date 2022/10/23
 * @brief 게임모드 클래스로, 시작 초기에 상속받는 BP로부터 아이템배열을 전달받아 소환하고 그 Dictionary를 저장한다.
 *
 * @var ItemDictionary 게임 내 존재하는 모든 아이템과 그 오브젝트를 연결한 사전 변수
 * @var CraftRecipes 게임 내 조합법을 모두 보관하는 배열 변수
 */

AEnemiesDropGameMode::AEnemiesDropGameMode()
{
	ItemDictionary = TMap<TSubclassOf<AItemBase>, AItemBase*>();
	CraftRecipes = TArray<FCraftRecipe>();
}


/**
 * @date 2022/10/23
 * @brief 사전 내의 아이템 오브젝트를 얻기 위한 함수
 *
 * @param[in] Key 얻고자 하는 아이템의 클래스
 * @return AItemBase* 입력한 Key값에 대응하는 아이템 오브젝트
 */
AItemBase* AEnemiesDropGameMode::GetItemDictionary(TSubclassOf<AItemBase> Key)
{
	return ItemDictionary.Contains(Key) ? ItemDictionary[Key] : nullptr;
}


/**
 * @date 2022/10/23
 * @brief 게임에 레시피를 등록하기 위한 함수
 *
 * @param[in] Recipe 등록하고자 하는 레시피
 */
void AEnemiesDropGameMode::RegisterItemRecipe(FCraftRecipe Recipe)
{
	CraftRecipes.Add(Recipe);
}

/**
 * @date 2022/10/23
 * @brief 게임의 모든 레시피를 출력하는 함수
 *
 * @return TArray<FCraftRecipe> 레시피 배열
 */
TArray<FCraftRecipe> AEnemiesDropGameMode::GetAllRecipe()
{
	return CraftRecipes;
}

/**
 * @date 2022/10/23
 * @brief 게임모드 액터가 소환되는 (게임 시작) 시간에 발동하는 함수로,
 *  입력받은 아이템 클래스들을 모두 소환한 뒤 사전에 보관한다.
 */
void AEnemiesDropGameMode::BeginPlay()
{
	TArray<TSubclassOf<AItemBase>> ItemClasses = RegisterItems();
	
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	for(TSubclassOf<AItemBase> ItemClass : ItemClasses) {
		AItemBase* Spawned = GetWorld()->SpawnActor<AItemBase>(ItemClass, FVector(0, 0, -20000), FRotator(0, 0, 0), SpawnParameters);
		Spawned->SetFolderPath("/ItemDummies");
		ItemDictionary.Add(ItemClass, Spawned);
	}
}

