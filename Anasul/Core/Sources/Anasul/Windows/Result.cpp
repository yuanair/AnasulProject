//
// Created by admin on 2024/8/21.
//

#include "Result.hpp"

#include "Windows.hpp"
#include "Anasul/Conv.hpp"

namespace Anasul
{
	
	template<>
	ANASUL_API StringA MessageToString(HResult dwMessageId)
	{
		auto strBufferError = new c8[256];
		::FormatMessageA
			(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr, dwMessageId, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				strBufferError, 256, nullptr
			);
		StringA buffer = strBufferError;
		delete[] strBufferError;
		return buffer;
	}
	
	template<>
	ANASUL_API StringW MessageToString(HResult dwMessageId)
	{
		auto strBufferError = new cwide[256];
		::FormatMessageW
			(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr, dwMessageId, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				strBufferError, 256, nullptr
			);
		StringW buffer = strBufferError;
		delete[] strBufferError;
		return buffer;
	}
	
	HResult LastErrorForHResult()
	{
		return HRESULT_FROM_WIN32(::GetLastError());
	}
	
	FResult::~FResult()
	{
		if (m_isThrowIfFailedAtDestructTime) ThrowIfFailed("Error");
	}
	
	bool FResult::IsFailed() const
	{
		return m_hr < 0;
	}
	
	bool FResult::IsSucceeded() const
	{
		return m_hr >= 0;
	}
	
	StringA FResult::ToString(const StringA &message) const
	{
		return std::format("{}: (0x{:08X}): {}", message, m_hr, MessageToString<c8>(m_hr));
	}
	
	StringW FResult::ToString(const StringW &message) const
	{
		return std::format(L"{}: (0x{:08X}): {}", message, m_hr, MessageToString<cwide>(m_hr));
	}
	
	void FResult::Log(Logger &logger, const StringA &message, const std::source_location &sourceLocation)
	{
		m_isThrowIfFailedAtDestructTime = false;
		StringA buffer = ToString(message);
		logger.Log(LogLevel::Error, buffer, sourceLocation);
	}
	
	void FResult::Log(Logger &logger, const StringW &message, const std::source_location &sourceLocation)
	{
		m_isThrowIfFailedAtDestructTime = false;
		StringW buffer = ToString(message);
		logger.Log(LogLevel::Error, buffer, sourceLocation);
	}
	
	void FResult::Throw(const StringA &message, const std::source_location &sourceLocation)
	{
		m_isThrowIfFailedAtDestructTime = false;
		StringA buffer = ToString(message);
		throw FResultException(Conv::AToW(buffer));
	}
	
	void FResult::Throw(const StringW &message, const std::source_location &sourceLocation)
	{
		m_isThrowIfFailedAtDestructTime = false;
		StringW buffer = ToString(message);
		throw FResultException(buffer);
	}
	
	
	void FResult::ThrowIfFailed(const StringA &message, const std::source_location &sourceLocation)
	{
		if (IsFailed()) Throw(message, sourceLocation);
	}
	
	void FResult::ThrowIfFailed(const StringW &message, const std::source_location &sourceLocation)
	{
		if (IsFailed()) Throw(message, sourceLocation);
	}
	
	void FResult::LogIfFailed(Logger &logger, const StringA &message, const std::source_location &sourceLocation)
	{
		if (IsFailed()) Log(logger, message, sourceLocation);
	}
	
	void FResult::LogIfFailed(Logger &logger, const StringW &message, const std::source_location &sourceLocation)
	{
		if (IsFailed()) Log(logger, message, sourceLocation);
	}
	
} // Anasul