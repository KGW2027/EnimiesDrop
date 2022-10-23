// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacter.h"

#include "Item/ItemBase.h"


ARPGCharacter::ARPGCharacter()
{
	// Set default status values
	Level = 0;
	LevelUp();

	bPressingAttack = false;
	
}

/**
 * @date 2022/10/23
 * @brief 플레이어가 레벨업 할 때 실행되는 함수,
 *   캐릭터의 체력은 100 + (Level * sqrt(Level))
 *   캐릭터의 마나는 100 + (Level * 30)
 *   캐릭터의 최대 경험치는 ( 100 * Level^2 )
 *  의 식으로 결정된다.
 */
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

/**
 * @date 2022/10/23
 * @brief 플레이어의 체력과 마나를 일정 퍼센트 회복하는 함수
 *   100% 이상 충전은 100%로 맞춰진다.
 *
 * @param[in] Percentage 회복할 퍼센티지
 */
void ARPGCharacter::Heal(float Percentage)
{
	int ResultHealth = CurrentHealth + MaxHealth * (Percentage/100);
	int ResultMana = CurrentMana + MaxMana * (Percentage/100);
	CurrentHealth = ResultHealth >= MaxHealth ? MaxHealth : ResultHealth;
	CurrentMana = ResultMana >= MaxMana ? MaxMana : ResultMana;
}

/**
 * @date 2022/10/23
 * @brief 플레이어에게 경험치를 주기위한 함수
 *  만약 레벨업 후에도 경험치가 최대 경험치를 오버한다면 한 번에 레벨 n업도 가능하다.
 *
 * @param[in] Exp 경험치 값
 */
void ARPGCharacter::ExpUp(int32 Exp)
{
	CurrentExp += Exp;
	while(CurrentExp >= MaxExp) LevelUp();
}


/**
 * @date 2022/10/23
 * @brief 플레이어의 인벤토리에 아이템을 넣기 위한 함수
 *
 * @param[in] ItemInfo 주운 아이템의 정보
 */
bool ARPGCharacter::PickupItem(const FInvItemStack ItemInfo)
{
	int32 LostQty = ItemInfo.ItemCount;

	// 1. 이미 인벤토리에 있는 아이템에 겹칠 수 있는가?
	for(int slot = 0 ; slot < FMath::Min(Inventory.Inventories.Num(), 12) ; slot++)
	{
		FInvItemStack InvItem = Inventory.Inventories[slot];
		
		if(InvItem.Item->GetClass() == ItemInfo.Item->GetClass())
		{
			int ItemMaxCount = ItemInfo.MaxCount;
			if(InvItem.ItemCount < ItemMaxCount) // Max Count
			{
				if(ItemMaxCount - InvItem.ItemCount > LostQty) // 남은 스택 개수가 먹은 아이템 수 보다 적을 때
				{
					InvItem.ItemCount = ItemMaxCount;
					LostQty -= (ItemMaxCount - InvItem.ItemCount);
					Inventory.Inventories[slot] = InvItem;
				}
				else // 남은 스택 개수가 먹은 아이템 수 보다 많을 때
				{
					InvItem.ItemCount += LostQty;
					Inventory.Inventories[slot] = InvItem;
					return true; // 모두 지급하므로 완료
				}
			}
		}
	}

	// 2. 인벤토리에 빈 칸이 존재하는가?
	if(Inventory.Inventories.Num() >= 12) return false;

	FInvItemStack GiveItem = FInvItemStack();
	GiveItem.Item = ItemInfo.Item;
	GiveItem.ItemCount = LostQty;
	Inventory.Inventories[Inventory.Inventories.Num()] = GiveItem;
	return true;
	
}
