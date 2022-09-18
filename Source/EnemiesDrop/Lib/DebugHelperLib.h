// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DebugHelperLib.generated.h"

/**
 * 
 */
UCLASS()
class ENEMIESDROP_API UDebugHelperLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Debug Vector", Category = "Debug Helper"))
	static void DebugVector(FVector Vector);
};
