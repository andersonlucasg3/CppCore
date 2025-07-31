#pragma once

#include "CoreDefinitions.h"

#include <format>

class CFile;

class CLogger
{
	CORE_API inline static void WriteLogLineInternal(const std::string& LogLine);

protected:
	CORE_API inline virtual void WriteLogLine(const std::string& LogLine) const;

public:
	CORE_API virtual ~CLogger();

	CORE_API static void InitializeLogFile(const char* LogFilePath);

	CORE_API static void LogException();

	template<typename ... TArgs>
	inline static void Log(const char* Format, TArgs ... Arguments)
	{
		std::string Formatted = std::vformat(Format, std::make_format_args(Arguments...));

		WriteLogLineInternal(Formatted);
	}

	template<typename ... TArgs>
	inline static void Error(const char* Format, TArgs ... Arguments)
	{
		std::string Formatted = std::vformat(Format, std::make_format_args(Arguments...));

		Formatted = "ERROR: " + Formatted;

		WriteLogLineInternal(Formatted);
	}

	template<typename ... TArgs>
	inline static void Fatal(const char* Format, TArgs ... Arguments)
	{
		std::string Formatted = std::vformat(Format, std::make_format_args(Arguments...));

		WriteLogLineInternal(Formatted);

		throw std::runtime_error(Formatted);
	}
};

CORE_API extern const CLogger& GLogger;