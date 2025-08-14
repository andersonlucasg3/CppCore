#pragma once

#include "Resources/Resources.h"

class CMacResources : public CResources
{
public:
    CORE_API ~CMacResources() override = default;

    CORE_API SFileRef GetResource(const CString& InResourceName) const override;
};

typedef CMacResources CPlatformResources;