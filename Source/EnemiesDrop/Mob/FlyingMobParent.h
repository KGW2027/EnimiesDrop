// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MobParent.h"
#include "Components/Mercuna3DNavigationComponent.h"
#include "FlyingMobParent.generated.h"

UCLASS()
class ENEMIESDROP_API AFlyingMobParent : public AMobParent
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFlyingMobParent();

	FVector BeforeMoveVector;
	bool IsSetBeforeMoveVector;
	
	bool PathValidate(FVector Vector) const;


protected:
	UMercuna3DNavigationComponent* MercunaComponent;
	
public:
	virtual FVector PathFind() override final;

	virtual void BeginPlay() override;
};
