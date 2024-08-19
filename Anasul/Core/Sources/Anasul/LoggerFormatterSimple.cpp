//
// Created by admin on 2024/8/16.
//

#include "LoggerFormatterSimple.hpp"

#include <format>

namespace Anasul
{
	StringA LoggerFormatterSimple::Format(const LoggerFormatterArg &arg, StringViewA message)
	{
		return std::format(
			arg.locale, "[{}][{}][{}][{}({}, {})][{}]: {}",
			ToStringA(arg.level), arg.time, (std::stringstream{} << arg.threadId).str(),
			arg.sourceLocation.file_name(), arg.sourceLocation.line(), arg.sourceLocation.column(),
			arg.sourceLocation.function_name(),
			message
		);
	}
	
	StringW LoggerFormatterSimple::Format(const LoggerFormatterArg &arg, StringViewW message)
	{
		return std::format(
			arg.locale, L"[{}][{}][{}][{}({}, {})][{}]: {}",
			ToStringW(arg.level), arg.time, (std::wstringstream{} << arg.threadId).str(),
			(void *) (arg.sourceLocation.file_name()), arg.sourceLocation.line(), arg.sourceLocation.column(),
			(void *) (arg.sourceLocation.function_name()),
			message
		);
	}
} // Anasul