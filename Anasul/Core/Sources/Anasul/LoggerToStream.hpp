//
// Created by admin on 2024/8/17.
//

#pragma once

#include "Config.hpp"
#include "Logger.hpp"
#include "LoggerFormatter.hpp"

namespace Anasul
{
	
	class ANASUL_API LoggerToStream : public Logger
	{
	public:
		
		LoggerToStream(LoggerFormatter &formatter, std::ostream &out, std::wostream &wout)
			: m_locale(), m_formatter(formatter), m_out(out), m_wout(wout) {}
		
		LoggerToStream(const std::locale &locale, LoggerFormatter &formatter, std::ostream &out, std::wostream &wout)
			: m_locale(locale), m_formatter(formatter), m_out(out), m_wout(wout) {}
	
	public:
		
		void Log(LogLevel level, StringViewA message,
		         std::source_location sourceLocation) override;
		
		void Log(LogLevel level, StringViewW message,
		         std::source_location sourceLocation) override;
		
		void Flush() override;
	
	public:
		
		std::locale &GetLocale() override;
		
		void SetLocale(const std::locale &locale) override;
		
		[[nodiscard]] const std::locale &GetLocale() const override;
		
		LoggerFormatter &GetFormatter() override;
		
		[[nodiscard]] const LoggerFormatter &GetFormatter() const override;
	
	private:
		
		std::locale m_locale;
		
		LoggerFormatter &m_formatter;
		
		std::ostream &m_out;
		
		std::wostream &m_wout;
		
	};
	
} // Anasul
