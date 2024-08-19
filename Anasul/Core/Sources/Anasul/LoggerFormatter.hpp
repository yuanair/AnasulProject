//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "Chrono.hpp"
#include "Logger.hpp"

#include <format>
#include <source_location>
#include <thread>

namespace Anasul
{
	
	/// 参数
	struct ANASUL_API LoggerFormatterArg
	{
		std::locale locale;
		LogLevel level;
		SystemTime time;
		std::thread::id threadId;
		std::source_location sourceLocation;
	};
	
	/// 日志格式化器
	class ANASUL_API LoggerFormatter
	{
	public:
		
		virtual ~LoggerFormatter() = default;
	
	public:
		
		virtual StringA Format(const LoggerFormatterArg &arg, StringViewA message) = 0;
		
		virtual StringW Format(const LoggerFormatterArg &arg, StringViewW message) = 0;
		
	};
	
	
} // Anasul
