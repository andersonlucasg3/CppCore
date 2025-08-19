using Shared.Projects;

namespace Networking.Modules;

public class HttpModule : AModuleDefinition
{
    public override EModuleBinaryType BinaryType => EModuleBinaryType.DynamicLibrary;

    public override string Name => "Http";

    protected override void Configure()
    {
        AddDependencyModuleNames(
            "Core"
        );
    }
}