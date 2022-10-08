// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingMobParent.h"

#include "Components/Mercuna3DNavigationComponent.h"
#include "Actors/MercunaNavOctree.h"
#include "EnemiesDrop/Lib/QuaternionLib.h"

// Sets default values
AFlyingMobParent::AFlyingMobParent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	IsSetBeforeMoveVector = false;
	
}

bool AFlyingMobParent::PathValidate(FVector Vector) const
{
	bool Validity = false;
	MercunaComponent->GetNavOctree()->IsNavigable(Vector, MobInfoData.AISettings.PatrolDistance, Validity);
	return Validity;
}

FVector AFlyingMobParent::PathFind()
{
	UWorld* World = GetWorld();
	FVector PawnLocation = GetActorLocation();
	FVector AxisVector = GetMesh()->GetForwardVector();
	const float PathfinderTraceLength = MobInfoData.AISettings.PatrolDistance;
		
	TArray<FVector> TraceTargets = {};

	// Step 1. Register Trace Channels to 'TraceTargets'
	// 8 Rotate Trace Channels
	for(int i = 0 ; i < 24 ; i++)
	{
		int Pitch = (i/8-1)*30;
		int Yaw = 45 * (i%8);
		FQuat TraceQuat = UQuaternionLib::Euler_To_Quaternion(FRotator(Pitch, Yaw, 0));
		FVector RotatedVector = TraceQuat.RotateVector(AxisVector);
		TraceTargets.Add(RotatedVector * PathfinderTraceLength);
	}

	// Up and Down Trace Channels
	FQuat UpQuat = UQuaternionLib::Euler_To_Quaternion(FRotator(90, 0, 0));
	FQuat DownQuat = UQuaternionLib::Euler_To_Quaternion(FRotator(-90, 0, 0));
	TraceTargets.Add(UpQuat.RotateVector(AxisVector) * PathfinderTraceLength);
	TraceTargets.Add(DownQuat.RotateVector(AxisVector) * PathfinderTraceLength);

	// Step 2. Find best path to patrol
	FVector MoveToVector = FVector(0, 0, 0);
	float MvDistance = 1;
	float MvWeight = 999;

	
	// Line Trace 26 Paths
	for (uint32 i = 0 ; i < TraceTargets.GetTypeSize() ; i++)
	{
		FHitResult HitResult = FHitResult();
		FVector TargetVector = PawnLocation + TraceTargets[i];
		World->LineTraceSingleByChannel(
			HitResult,
			PawnLocation,
			TargetVector,
			ECC_Visibility
		);

		
		FVector Axis = TraceTargets[i];
		Axis.Normalize();
		
		// The longer distance is higher priority. If distances are same, choose weight close to zero.
		float Weight = FVector::Dist2D(Axis,AxisVector);
		if( Axis.Z == 0 ) Weight *= 0.9;
		FVector TestVector = HitResult.bBlockingHit ? HitResult.Location : TargetVector;
		FVector FinalVector = FMath::Lerp(PawnLocation, TestVector, 0.6);
		
		bool bValid = PathValidate(FinalVector);
		if(!bValid) continue;
		
		float Dist = FVector::Distance(PawnLocation, FinalVector);
		
		// Refrain from Repeating move,
		if(IsSetBeforeMoveVector)
			Weight *= 1 - FVector::Distance(FinalVector, BeforeMoveVector) / (PathfinderTraceLength*2);
		
		if ( (MvDistance < Dist) || (MvDistance == Dist && MvWeight > Weight) || (MvDistance == Dist && MvWeight == Weight && FMath::RandRange(0, 100) < 50))
		{
			MoveToVector = FinalVector;
			MvDistance = Dist;
			MvWeight = Weight;
		}
	}

	BeforeMoveVector = MoveToVector;
	IsSetBeforeMoveVector = true;
	
	return MoveToVector;
}

void AFlyingMobParent::BeginPlay()
{
	MercunaComponent = Cast<UMercuna3DNavigationComponent>(InitNavComponent());
	
	Super::BeginPlay();
}
