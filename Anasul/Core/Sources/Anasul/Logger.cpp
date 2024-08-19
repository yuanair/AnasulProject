//
// Created by admin on 2024/8/16.
//

#include "Logger.hpp"

#include <iostream>

namespace Anasul
{
	StringA ToStringA(const LogLevel &level)
	{
		switch (level)
		{
			case LogLevel::Trace:
				return "Trace";
			case LogLevel::Debug:
				return "Debug";
			case LogLevel::Info:
				return "Info";
			case LogLevel::Warning:
				return "Warning";
			case LogLevel::Error:
				return "Error";
			case LogLevel::Fatal:
				return "Fatal";
			default:
				return std::format("<unknown LogLevel: {}>", static_cast<int>(level));
		}
	}
	
	StringW ToStringW(const LogLevel &level)
	{
		switch (level)
		{
			case LogLevel::Trace:
				return L"Trace";
			case LogLevel::Debug:
				return L"Debug";
			case LogLevel::Info:
				return L"Info";
			case LogLevel::Warning:
				return L"Warning";
			case LogLevel::Error:
				return L"Error";
			case LogLevel::Fatal:
				return L"Fatal";
			default:
				return std::format(L"<unknown LogLevel: {}>", static_cast<int>(level));
		}
	}
} // Anasul