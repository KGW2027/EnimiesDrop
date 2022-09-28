// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MobParent.h"
#include "Components/MercunaGroundNavigationComponent.h"
#include "GroundMobParent.generated.h"

UCLASS()
class ENEMIESDROP_API AGroundMobParent : public AMobParent
{
	GENERATED_BODY()

public:
	AGroundMobParent();

protected:
	UMercunaGroundNavigationComponent* MercunaComponent;

public:
	virtual FVector PathFind() override final;
};
