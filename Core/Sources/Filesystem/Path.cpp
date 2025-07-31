#include "Path.h"

#include "Defines/Preprocessors.h"
#include "Filesystem/Apple/ApplePath.h"

#include COMPILE_PLATFORM_HEADER(Path.h)

static const CPlatformPath GPlatformPath;
const CPath& GPath = GPlatformPath;