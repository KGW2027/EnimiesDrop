// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemiesDropCharacterController.h"

#include "EnemiesDrop/RPGCharacter.h"


AEnemiesDropCharacterController::AEnemiesDropCharacterController()
{
	CameraTurnRate = 50.0f;
	bIsJumping = false;
	bIsRunning = false;
	bIsControlAtUI = false;
}


void AEnemiesDropCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", IE_Pressed, this, &AEnemiesDropCharacterController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AEnemiesDropCharacterController::Jump);

	InputComponent->BindAction("Run", IE_Pressed, this, &AEnemiesDropCharacterController::Run);
	InputComponent->BindAction("Run", IE_Released, this, &AEnemiesDropCharacterController::Run);

	InputComponent->BindAxis("Move Forward / Backward", this, &AEnemiesDropCharacterController::MoveFB);
	InputComponent->BindAxis("Move Right / Left", this, &AEnemiesDropCharacterController::MoveLR);

	InputComponent->BindAxis("Turn Right / Left Mouse", this, &AEnemiesDropCharacterController::InputYaw);
	InputComponent->BindAxis("Look Up / Down Mouse", this, &AEnemiesDropCharacterController::InputPitch);
	
}

void AEnemiesDropCharacterController::Jump()
{
	if(!bIsJumping)
		Cast<ACharacter>(GetPawn())->Jump();
	else
		Cast<ACharacter>(GetPawn())->StopJumping();
	
	bIsJumping = !bIsJumping;
}

void AEnemiesDropCharacterController::Run()
{
	if(!bIsRunning)
		Cast<ARPGCharacter>(GetPawn())->ToggleSprint();
	else
		Cast<ARPGCharacter>(GetPawn())->ToggleSprint();

	bIsRunning = !bIsRunning;
}

void AEnemiesDropCharacterController::MoveFB(float Axis)
{
	if (Axis != .0f && !bIsControlAtUI)
	{
		// find out which way is forward
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		GetPawn()->AddMovementInput(Direction, Axis);
		// AddMovementInput(Direction, Value);
	}
}

void AEnemiesDropCharacterController::MoveLR(float Axis)
{
	if(Axis != .0f && !bIsControlAtUI)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		GetPawn()->AddMovementInput(Direction, Axis);
	}
}

void AEnemiesDropCharacterController::InputYaw(float Axis)
{
	if(!bIsControlAtUI)
		AddYawInput(Axis * CameraTurnRate * GetWorld()->GetDeltaSeconds());
}

void AEnemiesDropCharacterController::InputPitch(float Axis)
{
	if(!bIsControlAtUI)
		AddPitchInput(Axis * CameraTurnRate * GetWorld()->GetDeltaSeconds());
}

