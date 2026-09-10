// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShooterSamTarget : TargetRules
{
    public ShooterSamTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
        ExtraModuleNames.Add("ShooterSam");
    }
}
