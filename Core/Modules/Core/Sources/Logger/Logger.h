#pragma once

#include "String/String.h"

#include <stdexcept>

struct SFileRef;
class CFile;

class CLogger
{
	CFile* _logFile = nullptr;

protected:
	CORE_API virtual void WriteLogLine(const CString& LogLine) const;

public:
	CORE_API virtual ~CLogger();

	CORE_API void InitializeLogFile(const SFileRef& LogFilePath);

	CORE_API virtual void LogException() const;

	template<typename ... TArgs>
	void Log(const char* Format, TArgs ... Args) const
	{
		CString Formatted(Format, Args ...);
		
		Formatted = "LOG: " + Formatted;

		WriteLogLine(Formatted);
	}

	template<typename ... TArgs>
	void Error(const char* Format, TArgs ... Args) const
	{
		CString Formatted(Format, Args ...);
		
		Formatted = "ERROR: " + Formatted;

		WriteLogLine(Formatted);
	}

	template<typename ... TArgs>
	void Fatal(const char* Format, TArgs ... Args) const
	{
		CString Formatted(Format, Args ...);
		
		Formatted = "FATAL: " + Formatted;

		WriteLogLine(Formatted);

		throw std::runtime_error(*Formatted);
	}
};

CORE_API extern const CLogger& GLogger;