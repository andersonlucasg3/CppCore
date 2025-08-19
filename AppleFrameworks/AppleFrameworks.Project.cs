using AppleFrameworks.Foundation;
using AppleFrameworks.Metal;
using Shared.Platforms;
using Shared.Projects;

namespace AppleFrameworks.Projects;

public class AppleFrameworksProject : AProjectDefinition
{
    public override string Name => "AppleFrameworks";
    
    protected override void Configure()
    {
        AddModuleToGroup<FoundationModule>(ETargetPlatformGroup.Apple);
        // AddModule<MetalModule>();
    }
}