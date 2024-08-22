//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/String.hpp>

namespace Anasul
{
	/// 平台类
	class ANASUL_API Platform
	{
	public:
		
		Platform() = default;
		
		virtual ~Platform() = default;
	
	public:
		
		Platform(const Platform &) = delete;
		
		Platform &operator=(const Platform &) = delete;
	
	public:
		
		static Platform &Get();
	
	public:
		
		[[nodiscard]] virtual StringA GetPlatformNameA() const = 0;
		
		[[nodiscard]] virtual StringW GetPlatformNameW() const = 0;
		
		/// 获取当前黑暗模式
		[[nodiscard]] virtual i32 DarkMode() const = 0;
		
	};
	
} // Anasul
