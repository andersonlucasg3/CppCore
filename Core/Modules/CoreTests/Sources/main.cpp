#include "TestSuit.h"

#include "Process/Process.h"

static void CustomMain(int argc, char* argv[])
{
    GProcess.SetCommandLine(argc, argv);
}

DEFINE_TEST_RUNNER(CustomMain(argc, argv));

// do not remove, faking pthread_atfork
int pthread_atfork(void (* _Nullable)(), void (* _Nullable)(), void (* _Nullable)()) {}