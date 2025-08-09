#include "Logger.h"

#include "Defines/Preprocessors.h"
#include "Defines/Types.h"
#include "Filesystem/FileReference.h"
#include "String/String.h"

#include <exception>
#include <vector>

#if PLATFORM_GROUP_APPLE
#include <execinfo.h>
#include <cxxabi.h>
#endif

#include COMPILE_PLATFORM_HEADER(Logger.h)
#include COMPILE_PLATFORM_HEADER_FEATURE(Filesystem,File.h)

static const CPlatformLogger GPlatformLogger;
const CLogger& GLogger = GPlatformLogger;

std::vector<CString> GLogBuffer;

void CLogger::WriteLogLine(const std::string& LogLine) const
{
	if (_logFile == nullptr)
	{
		GLogBuffer.push_back(LogLine);

		return;
	}

	_logFile->Write((const int8_t*)LogLine.c_str(), LogLine.size());
	_logFile->Flush();
}

CLogger::~CLogger()
{
	if (_logFile != nullptr)
	{
		delete _logFile;
		_logFile = nullptr;
	}
}

void CLogger::InitializeLogFile(const SFileRef& LogFilePath)
{
	if (GLogger._logFile != nullptr)
	{
		GLogger.Log("Trying to initialize log file when it is already initialized");

		return;
	}

	if (LogFilePath->Exists())
	{
		LogFilePath->Delete(LogFilePath);
	}

	GLogger._logFile = CFile::CreateUnsafe(LogFilePath);

	if (GLogBuffer.size() > 0)
	{
		for (const std::string& Log : GLogBuffer)
		{
			_logFile->Write((const int8_t*)Log.c_str(), Log.size());
		}

		GLogBuffer.clear();
	}

	_logFile->Flush();
}

void CLogger::LogException()
{	
	try
	{
		std::rethrow_exception(std::current_exception());
	}
	catch (const std::exception& Exception)
	{
		Log("EXCEPTION: {}", Exception.what());

#if PLATFORM_GROUP_APPLE
		CString StackString = "STACKTRACE:\n";

		void* CallstackArray[128];
		int Frames = backtrace(CallstackArray, 128);
		char** Symbols = backtrace_symbols(CallstackArray, Frames);

		for (int Index = 0; Index < Frames; ++Index)
		{
			CString Frame = Symbols[Index];
			do
			{
				Frame = Frame.Replace("  ", " ");
			}
			while (Frame.Contains("  "));
			
			CString Component = Frame.Split(' ')[3];
			
			SInt32 Status;			
			char* RealName = abi::__cxa_demangle(*Component, nullptr, nullptr, &Status);

			if (Status == 0 && RealName)
			{
				CString DemangledString = CString(Symbols[Index]).Replace(*Component, RealName);

				if (Index == 6)
				{
					StackString += CString("{} <--- Crash\n", *DemangledString);
				}
				else
				{
					StackString += CString("{}\n", *DemangledString);
				}
				
				free(RealName);
			}
			else
			{
				StackString += CString("{}\n", Symbols[Index]);
			}
		}
		free(Symbols);

		Log(*StackString);
#else
		Log("STACKTRACE: Stack trace is not supported on this platform.");
#endif
	}

	_Exit(255);
}