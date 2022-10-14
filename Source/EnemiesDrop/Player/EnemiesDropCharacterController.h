// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnemiesDropCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class ENEMIESDROP_API AEnemiesDropCharacterController : public APlayerController
{
	GENERATED_BODY()

	AEnemiesDropCharacterController();

protected:
	UPROPERTY(BlueprintReadWrite)
	float CameraTurnRate;

	UPROPERTY(BlueprintReadOnly)
	bool bIsJumping;

	UPROPERTY(BlueprintReadOnly)
	bool bIsRunning;
	
	UPROPERTY(BlueprintReadWrite)
	bool bIsControlAtUI;

public:
	virtual void SetupInputComponent() override;

	void Jump();
	void Run();
	void MoveFB(float Axis);
	void MoveLR(float Axis);
	void InputYaw(float Axis);
	void InputPitch(float Axis);
	
};
