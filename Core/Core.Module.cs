using Shared.Platforms;
using Shared.Projects;

namespace Core.Modules;

public class CoreModule : ModuleDefinition
{
    public override string Name => "Core";
    public override EModuleBinaryType BinaryType => EModuleBinaryType.DynamicLibrary;

    public override string SourcesRoot => "Sources";

    protected override void Configure(ProjectDefinition InOwnerProject)
    {
        AddHeaderSearchPaths(
            ETargetPlatform.macOS,
            "External/Apple-Cpp"
        );
    }
}