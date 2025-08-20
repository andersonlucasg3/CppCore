using Shared.Projects;

namespace Networking.Modules;

public class NetworkingTests : AModuleDefinition
{
    public override EModuleBinaryType BinaryType => EModuleBinaryType.Application;

    public override string Name => "NetworkingTests";

    protected override void Configure()
    {
        AddDependencyModuleNames(
            "Http",
            "TestSuitLib"
        );
    }
}