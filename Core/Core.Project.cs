using Shared.Platforms;
using Shared.Projects;

namespace Core.Projects;

using Modules;

public class CoreProject : ProjectDefinition
{
    public override string Name => "Core";

    public override string SourcesRoot => "..";

    protected override void Configure()
    {
        AddModule<CoreModule>();
    }
}