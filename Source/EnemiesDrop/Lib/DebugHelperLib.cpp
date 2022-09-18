// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugHelperLib.h"

void UDebugHelperLib::DebugVector(FVector Vector)
{
	UE_LOG(LogTemp, Log, TEXT("Vector { %f, %f, %f }"), Vector.X, Vector.Y, Vector.Z);
}
