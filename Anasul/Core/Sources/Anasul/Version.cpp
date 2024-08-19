//
// Created by admin on 2024/8/16.
//

#include "Version.hpp"

#include "Platform.hpp"

#include <format>

namespace Anasul
{
	const c8 *GetNameA()
	{
		return "Anasul";
	}
	
	const cwide *GetNameW()
	{
		return L"Anasul";
	}
	
	i32 GetMajor()
	{
		return 0;
	}
	
	i32 GetMinor()
	{
		return 1;
	}
	
	i32 GetPatch()
	{
		return 1;
	}
	
	const c8 *GetBuildDataA()
	{
		return __DATE__;
	}
	
	const cwide *GetBuildDataW()
	{
		return _CRT_WIDE(__DATE__);
	}
	
	const c8 *GetBuildTimeA()
	{
		return __TIME__;
	}
	
	const cwide *GetBuildTimeW()
	{
		return _CRT_WIDE(__TIME__);
	}
	
	const c8 *GetGreekAlphabetA()
	{
		return "alpha";
	}
	
	const cwide *GetGreekAlphabetW()
	{
		return L"alpha";
	}
	
	StringA GetVersionA()
	{
		return std::format(
			"{}_v{}.{}.{}_{}", Platform::GetPlatformNameA(), GetMajor(), GetMinor(), GetPatch(), GetGreekAlphabetA());
	}
	
	StringW GetVersionW()
	{
		return std::format(
			L"{}_v{}.{}.{}_{}", Platform::GetPlatformNameW(), GetMajor(), GetMinor(), GetPatch(), GetGreekAlphabetW());
	}
} // Anasul