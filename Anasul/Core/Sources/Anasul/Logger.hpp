//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "String.hpp"

#include <format>
#include <source_location>

namespace Anasul
{
	
	/// 日志级别
	enum class LogLevel
	{
		Trace,
		Debug,
		Info,
		Warning,
		Error,
		Fatal
	};
	
	ANASUL_API StringA ToStringA(const LogLevel &level);
	
	ANASUL_API StringW ToStringW(const LogLevel &level);
	
	/// 日志器
	class ANASUL_API Logger
	{
	public:
		
		virtual ~Logger() = default;
	
	public:
		
		/// 消息
		virtual void Log(LogLevel level, StringViewA message,
		                 std::source_location sourceLocation = std::source_location::current()) = 0;
		
		/// 消息
		virtual void Log(LogLevel level, StringViewW message,
		                 std::source_location sourceLocation = std::source_location::current()) = 0;
		
		/// 格式化消息
		virtual void LogFormat(LogLevel level, StringViewA fmt, std::format_args args,
		                       std::source_location sourceLocation = std::source_location::current())
		{
			return Log(level, std::vformat(fmt, args), sourceLocation);
		}
		
		/// 格式化消息
		virtual void LogFormat(LogLevel level, StringViewW fmt, std::wformat_args args,
		                       std::source_location sourceLocation = std::source_location::current())
		{
			return Log(level, std::vformat(fmt, args), sourceLocation);
		}
		
		/// 刷新缓存
		virtual void Flush() = 0;
		
		/// 获取本地化
		virtual std::locale &GetLocale() = 0;
		
		/// 设置本地化
		virtual void SetLocale(const std::locale &locale) = 0;
		
		/// 获取本地化
		[[nodiscard]] virtual const std::locale &GetLocale() const = 0;
		
		/// 获取格式化器
		virtual class LoggerFormatter &GetFormatter() = 0;
		
		/// 获取格式化器
		[[nodiscard]] virtual const class LoggerFormatter &GetFormatter() const = 0;
		
	};
	
} // Anasul
