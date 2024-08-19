//
// Created by admin on 2024/8/17.
//

#include "LoggerToStream.hpp"

#include <iostream>
#include <format>

namespace Anasul
{
	void LoggerToStream::Log(LogLevel level, StringViewA message, std::source_location sourceLocation)
	{
		m_out << m_formatter.Format(
			{.locale=m_locale, .level=level, .time=SystemClock::now(), .threadId=std::this_thread::get_id(), .sourceLocation=sourceLocation},
			message
		) << '\n';
		if (level >= LogLevel::Warning)
		{
			m_out.flush();
		}
	}
	
	void LoggerToStream::Log(LogLevel level, StringViewW message, std::source_location sourceLocation)
	{
		m_wout << m_formatter.Format(
			{.locale=m_locale, .level=level, .time=SystemClock::now(), .threadId=std::this_thread::get_id(), .sourceLocation=sourceLocation},
			message
		) << '\n';
		if (level >= LogLevel::Warning)
		{
			m_wout.flush();
		}
	}
	
	void LoggerToStream::Flush()
	{
		m_out.flush();
		m_wout.flush();
	}
	
	std::locale &LoggerToStream::GetLocale()
	{
		return m_locale;
	}
	
	void LoggerToStream::SetLocale(const std::locale &locale)
	{
		m_locale = locale;
	}
	
	const std::locale &LoggerToStream::GetLocale() const
	{
		return m_locale;
	}
	
	LoggerFormatter &LoggerToStream::GetFormatter()
	{
		return m_formatter;
	}
	
	const LoggerFormatter &LoggerToStream::GetFormatter() const
	{
		return m_formatter;
	}
} // Anasul