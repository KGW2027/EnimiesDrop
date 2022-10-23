// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundMobParent.h"



/**
 * @date 2022/10/23
 * @brief Ground 몬스터에 대한 클래스이다.
 */

FVector AGroundMobParent::PathFind()
{
	FVector TargetLoc;
	const float PatrolDistance = MobInfoData.AISettings.PatrolDistance;
	const float HalfDistance = PatrolDistance / 2;
	
	float MoveX = FMath::RandRange(.0f, PatrolDistance) - HalfDistance;
	float MoveY = FMath::RandRange(.0f, PatrolDistance-MoveX) - HalfDistance + MoveX / 2;
	
	FVector ActorLoc = GetActorLocation();
	TargetLoc = FVector(ActorLoc.X+MoveX, ActorLoc.Y+MoveY, ActorLoc.Z);

	
	return TargetLoc;
}

void AGroundMobParent::BeginPlay()
{
	MercunaComponent = Cast<UMercunaGroundNavigationComponent>(InitNavComponent());
	
	Super::BeginPlay();
}
