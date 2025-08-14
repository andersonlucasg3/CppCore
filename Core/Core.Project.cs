using Shared.Projects;
using TestSuit.Projects;

namespace Core.Projects;

using Modules;

public class CoreProject : AProjectDefinition
{
    public override string Name => "Core";

    public override string SourcesRoot => "Modules";

    protected override void Configure()
    {
        AddModule<CoreModule>();
        AddModule<CoreTestsModule>();

        AddProjectDependency<TestSuitProject>();
    }
}