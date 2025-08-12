#include "Logger.h"

#include "Defines/Preprocessors.h"

#include "Templates/Array.h"

#include "String/String.h"
#include "Filesystem/File.h"
#include "Filesystem/FileReference.h"

#include <exception>

#include COMPILE_PLATFORM_HEADER(Logger.h)

static const CPlatformLogger GPlatformLogger;
const CLogger& GLogger = GPlatformLogger;

TArray<CString> GLogBuffer;

void CLogger::WriteLogLine(const CString& LogLine) const
{
	if (_logFile == nullptr)
	{
		GLogBuffer.Add(LogLine);

		return;
	}

	_logFile->Write(*LogLine, LogLine.Len());
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
	if (_logFile != nullptr)
	{
		Log("Trying to initialize log file when it is already initialized");

		return;
	}

	if (LogFilePath->Exists())
	{
		LogFilePath->Delete();
	}

	_logFile = CFile::CreateUnsafe(*LogFilePath->Path());

	if (GLogBuffer.Num() > 0)
	{
		for (const CString& Log : GLogBuffer)
		{
			_logFile->Write(*Log, Log.Len());
		}

		GLogBuffer = {};
	}

	_logFile->Flush();
}

void CLogger::LogException() const
{	
	try
	{
		std::rethrow_exception(std::current_exception());
	}
	catch (const std::exception& Exception)
	{
		Log("EXCEPTION: {}", Exception.what());

		Log("STACKTRACE: Stack trace is not supported on this platform.");
	}

	_Exit(255);
}