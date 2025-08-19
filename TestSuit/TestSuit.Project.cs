using Shared.Projects;

namespace TestSuit.Projects;

using Modules;

public class TestSuitProject : AProjectDefinition
{
    public override string Name => "TestSuit";

    protected override void Configure()
    {
        AddModule<TestSuitLibModule>();
    }
}