// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FlyingMobParent.generated.h"

UCLASS()
class ENEMIESDROP_API AFlyingMobParent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFlyingMobParent();

	FVector BeforeMoveVector;
	bool IsSetBeforeMoveVector;

	UPROPERTY(BlueprintReadWrite, meta = (Category = "Pathfinding"))
	float PathfinderTraceLength;

	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "Moveable Min Z", Category = "Pathfinding"))
	float MoveableMinZ;

	UPROPERTY(BlueprintReadWrite, meta = (DisplayName = "Moveable Max Z", Category = "Pathfinding"))
	float MoveableMaxZ;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PathFind"))
	FVector PathFind();
	
	UFUNCTION(BlueprintImplementableEvent)
	bool IsNavigatable(FVector Vector);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
