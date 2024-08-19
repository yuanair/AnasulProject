//
// Created by admin on 2024/8/16.
//

#include "Platform.hpp"

namespace Anasul
{
	const c8 *Platform::GetPlatformNameA()
	{
		#ifdef ANASUL_TARGET_WINDOWS
		return "windows";
		#elif defined(ANASUL_TARGET_IOS)
		return "ios";
		#elif defined(ANASUL_TARGET_MACOS)
		return "macos";
		#elif defined(ANASUL_TARGET_ANDROID)
		return "android";
		#elif defined(ANASUL_TARGET_LINUX)
		return "linux";
		#endif
	}
	
	const cwide *Platform::GetPlatformNameW()
	{
		#ifdef ANASUL_TARGET_WINDOWS
		return L"windows";
		#elif defined(ANASUL_TARGET_IOS)
		return L"ios";
		#elif defined(ANASUL_TARGET_MACOS)
		return L"macos";
		#elif defined(ANASUL_TARGET_ANDROID)
		return L"android";
		#elif defined(ANASUL_TARGET_LINUX)
		return L"linux";
		#endif
	}
} // Anasul