#include "AndroidProcess.h"

#include "Templates/Array.h"

void CAndroidProcess::SetCommandLine(int argc, const char* argv[])
{
    // TODO: implement commandline support
}

const TArray<CString>& CAndroidProcess::GetCommandLineArgs() const
{
    static TArray<CString> Temp;

    return Temp;
}