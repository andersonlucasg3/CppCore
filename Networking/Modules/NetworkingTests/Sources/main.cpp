#include "TestSuit.h"

#include "Process/Process.h"

static void CustomMain(int argc, char* argv[])
{
    GProcess.SetCommandLine(argc, argv);
}

DEFINE_TEST_RUNNER(CustomMain(argc, argv));