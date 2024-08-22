//
// Created by admin on 2024/8/21.
//

#pragma once

#include "../Config.hpp"
#include "../String.hpp"
#include "../Logger.hpp"
#include "../Exception.hpp"

namespace Anasul
{
	
	using HResult = i32;
	
	template<typename ElemT>
	ANASUL_API BasicString<ElemT> MessageToString(HResult dwMessageId);
	
	ANASUL_API HResult LastErrorForHResult();
	
	
	class FResultException : public Exception
	{
	public:
		
		using Exception::Exception;
		
	};
	
	class ANASUL_API FResult
	{
	public:
		
		FResult() noexcept
			: m_hr(0), m_isThrowIfFailedAtDestructTime(false) {}
		
		FResult(HResult hr) noexcept// NOLINT(*-explicit-constructor)
			: m_hr(hr), m_isThrowIfFailedAtDestructTime(true) {}
		
		FResult(const FResult &other) noexcept
			: m_hr(other.m_hr), m_isThrowIfFailedAtDestructTime(other.m_isThrowIfFailedAtDestructTime) {}
		
		FResult(FResult &&other) noexcept
			: FResult() { Swap(other); }
		
		~FResult();
	
	public:
	
	public:
		
		FResult &operator=(const FResult &other) noexcept
		{
			FResult(other).Swap(*this);
			return *this;
		}
		
		FResult &operator=(FResult &&other) noexcept
		{
			FResult(std::move(other)).Swap(*this);
			return *this;
		}
		
		FResult &operator=(HResult hr) noexcept
		{
			this->m_hr = hr;
			return *this;
		}
	
	public:
		
		///
		/// \param message
		/// \return 字符串
		[[nodiscard]]
		StringA ToString(const StringA &message) const;
		
		[[nodiscard]]
		StringW ToString(const StringW &message) const;
		
		///
		/// 输出到日志
		void Log(Logger &logger, const StringA &message,
		         const std::source_location &sourceLocation = std::source_location::current());
		
		void Log(Logger &logger, const StringW &message,
		         const std::source_location &sourceLocation = std::source_location::current());
		
		///
		/// 输出到日志并抛异常
		void
		Throw(const StringA &message, const std::source_location &sourceLocation = std::source_location::current());
		
		void
		Throw(const StringW &message, const std::source_location &sourceLocation = std::source_location::current());
		
		///
		/// \return 是否是失败值
		[[nodiscard]]
		boolean IsFailed() const;
		
		///
		/// \return 是否是成功值
		[[nodiscard]]
		boolean IsSucceeded() const;
		
		///
		/// 如果失败则调用Throw()
		void ThrowIfFailed(const StringA &message,
		                   const std::source_location &sourceLocation = std::source_location::current());
		
		void ThrowIfFailed(const StringW &message,
		                   const std::source_location &sourceLocation = std::source_location::current());
		
		///
		/// 如果失败则调用Log()
		void LogIfFailed(Logger &logger, const StringA &message,
		                 const std::source_location &sourceLocation = std::source_location::current());
		
		void LogIfFailed(Logger &logger, const StringW &message,
		                 const std::source_location &sourceLocation = std::source_location::current());
	
	public:
		
		void Swap(FResult &other) noexcept
		{
			using std::swap;
			swap(m_hr, other.m_hr);
			swap(m_isThrowIfFailedAtDestructTime, other.m_isThrowIfFailedAtDestructTime);
		}
	
	public:
		
		[[nodiscard]]HResult GetHr() const noexcept { return this->m_hr; }
		
		[[nodiscard]]boolean
		IsThrowIfFailedAtDestructTime() const noexcept { return this->m_isThrowIfFailedAtDestructTime; }
		
		void SetIsThrowIfFailedAtDestructTime(boolean arg) noexcept
		{
			this->m_isThrowIfFailedAtDestructTime = arg;
		}
	
	private:
		
		HResult m_hr;
		
		boolean m_isThrowIfFailedAtDestructTime;
		
	};
	
} // Anasul
