using Shared.Projects;
using Shared.Platforms;
using TestSuit.Projects;
using AppleFrameworks.Projects;

namespace Core.Projects;

using Modules;

public class CoreProject : AProjectDefinition
{
    public override string Name => "Core";

    protected override void Configure()
    {
        AddProjectDependencyToGroup<AppleFrameworksProject>(ETargetPlatformGroup.Apple);
        
        AddProjectDependency<TestSuitProject>();

        AddModule<CoreModule>();
        AddModule<CoreTestsModule>();
    }
}