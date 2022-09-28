// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EnemiesDrop : ModuleRules
{
	public EnemiesDrop(ReadOnlyTargetRules Target) : base(Target)
	{
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"Mercuna3DNavigation/Private",
			}
		);
		
		PrivateDependencyModuleNames.AddRange(new string[] {"Mercuna"});
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
