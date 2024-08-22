//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>
#include "../Platform.hpp"

namespace Anasul
{
	
	class ANASUL_API WindowsPlatform : public Platform
	{
	public:
		
		static Platform &Get();
	
	public:
		
		[[nodiscard]] StringA GetPlatformNameA() const override;
		
		[[nodiscard]] StringW GetPlatformNameW() const override;
		
		[[nodiscard]] i32 DarkMode() const override;
	
	private:
		
		WindowsPlatform() = default;
		
	};
	
} // Anasul
