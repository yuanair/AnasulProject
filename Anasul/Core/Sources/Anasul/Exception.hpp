//
// Created by admin on 2024/8/18.
//

#pragma once

#include "Config.hpp"
#include "String.hpp"

#include <exception>
#include <string_view>

namespace Anasul
{
	
	/// 异常
	class ANASUL_API Exception : public std::runtime_error
	{
	public:
		
		explicit Exception(StringView what) : std::runtime_error(reinterpret_cast<const char *>(what.data())) {}
	
	public:
		
		/// 获取异常信息
		inline StringView What()
		{
			return reinterpret_cast<const chararcter *>(what());
		}
		
	};
	
	/// 空指针异常
	class ANASUL_API NullPointerException : public Exception
	{
	public:
		
		using Exception::Exception;
		
	};
	
	/// 无效参数异常
	class ANASUL_API InvalidArgumentException : public Exception
	{
	public:
		
		using Exception::Exception;
		
	};
	
} // Anasul
