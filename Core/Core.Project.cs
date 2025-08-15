using Shared.Projects;
using TestSuit.Projects;
using AppleFrameworks.Projects;

namespace Core.Projects;

using Modules;

public class CoreProject : AProjectDefinition
{
    public override string Name => "Core";

    public override string SourcesRoot => "Modules";

    protected override void Configure()
    {
        AddProjectDependency<TestSuitProject>();
        AddProjectDependency<AppleFrameworksProject>();

        AddModule<CoreModule>();
        AddModule<CoreTestsModule>();
    }
}