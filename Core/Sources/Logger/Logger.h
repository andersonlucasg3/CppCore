#pragma once

#include "String/String.h"

#include <stdexcept>

struct SFileRef;
class CFile;

class CLogger
{
	CFile* _logFile = nullptr;

protected:
	CORE_API inline virtual void WriteLogLine(const CString& LogLine) const;

public:
	CORE_API virtual ~CLogger();

	CORE_API void InitializeLogFile(const SFileRef& LogFilePath);

	CORE_API virtual void LogException() const;

	template<typename ... TArgs>
	inline void Log(const char* Format, TArgs ... Arguments) const
	{
		CString Formatted(Format, Arguments);
		
		Formatted = "LOG: " + Formatted;

		WriteLogLine(Formatted);
	}

	template<typename ... TArgs>
	inline void Error(const char* Format, TArgs ... Arguments) const
	{
		CString Formatted(Format, Arguments);
		
		Formatted = "ERROR: " + Formatted;

		WriteLogLine(Formatted);
	}

	template<typename ... TArgs>
	inline void Fatal(const char* Format, TArgs ... Arguments) const
	{
		CString Formatted(Format, Arguments);
		
		Formatted = "FATAL: " + Formatted;

		WriteLogLine(Formatted);

		throw std::runtime_error(*Formatted);
	}
};

CORE_API extern const CLogger& GLogger;