// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItemBase::PickupThis(ARPGCharacter* User)
{
	FInvItemStack ItemStack;
	ItemStack.Item = this;
	ItemStack.ItemCount = DroppedCount;
	ItemStack.MaxCount = MaxStackSize;
	
	if(User->PickupItem(ItemStack))
		Destroy();
}

void AItemBase::BeginPlay()
{
	InitializeItemData(ItemName, MaxStackSize, ItemReal, ItemThumbnail);
	
	Super::BeginPlay();
	
}

void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

