// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EnemiesDrop : ModuleRules
{
	public EnemiesDrop(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
