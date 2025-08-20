using Shared.Projects;
using Core.Projects;

namespace Networking.Projects;

using Modules;

public class NetworkingProject : AProjectDefinition
{
    public override string Name => "Networking";

    protected override void Configure()
    {
        AddModule<HttpModule>();
        AddModule<NetworkingTests>();

        AddProjectDependency<CoreProject>();
    }
}