using TestSuit.Modules;

namespace Core.Modules;

public class CoreTestsModule : TestSuitRunnerModule
{
    public override string Name => "CoreTests";
    
    protected override void Configure()
    {
        base.Configure();

        AddDependencyModuleNames(
            "Core"
        );
    }
}