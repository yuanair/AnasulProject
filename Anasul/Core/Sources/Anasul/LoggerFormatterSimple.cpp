//
// Created by admin on 2024/8/16.
//

#include "LoggerFormatterSimple.hpp"
#include "Conv.hpp"

#include <format>

namespace Anasul
{
	StringA LoggerFormatterSimple::Format(const LoggerFormatterArg &arg, StringViewA message)
	{
		return std::format(
			arg.locale, "[{:7}][{:}][0x{:08X}][{}({}, {})][{}]: {}",
			ToStringA(arg.level), arg.time,
			*reinterpret_cast<const u32 *>(reinterpret_cast<const void *>(&arg.threadId)),
			arg.sourceLocation.file_name(), arg.sourceLocation.line(), arg.sourceLocation.column(),
			arg.sourceLocation.function_name(),
			message
		);
	}
	
	StringW LoggerFormatterSimple::Format(const LoggerFormatterArg &arg, StringViewW message)
	{
		return std::format(
			arg.locale, L"[{:7}][{:}][0x{:08X}][{}({}, {})][{}]: {}",
			ToStringW(arg.level), arg.time,
			*reinterpret_cast<const u32 *>(reinterpret_cast<const void *>(&arg.threadId)),
			Conv::AToW(arg.sourceLocation.file_name()), arg.sourceLocation.line(), arg.sourceLocation.column(),
			Conv::AToW(arg.sourceLocation.function_name()),
			message
		);
	}
} // Anasul