using Shared.Platforms;
using Shared.Projects;

namespace Core.Modules;

public class CoreModule : AModuleDefinition
{
    public override string Name => "Core";
    public override EModuleBinaryType BinaryType => EModuleBinaryType.DynamicLibrary;

    public override string SourcesRoot => "Sources";

    protected override void Configure()
    {
        AddDependencyModuleNames(
            ETargetPlatform.macOS,
            "Foundation"
        );

        AddLinkWithLibrary(
            ETargetPlatform.Windows,
            "shell32.lib",
            "ole32.lib"
        );
    }
}