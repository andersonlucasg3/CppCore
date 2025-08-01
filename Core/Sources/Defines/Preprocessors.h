#pragma once

#include "PlatformInfo.h"

#define LITERAL_TOSTR(x) #x
#define TOSTR(x) LITERAL_TOSTR(x)
#define CONCAT_LITERAL(x, y) x##y
#define CONCAT(x, y) CONCAT_LITERAL(x, y)

#define COMPILE_PLATFORM_HEADER_FEATURE(x, y) TOSTR(x/PLATFORM_NAME/CONCAT(PLATFORM_NAME,y))
#define COMPILE_PLATFORM_HEADER(x) TOSTR(PLATFORM_NAME/CONCAT(PLATFORM_NAME,x))

#define GET_LAST_ARG(...) GET_LAST_ARG_IMPL(__VA_ARGS__, dummy)
#define GET_LAST_ARG_IMPL(first, ...) GET_LAST_ARG_IMPL_(__VA_ARGS__)
#define GET_LAST_ARG_IMPL_(last, ...) last