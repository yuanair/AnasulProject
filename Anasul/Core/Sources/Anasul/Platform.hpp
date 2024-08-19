//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"

extern "C" namespace Anasul::Platform
{
	
	/// 平台名
	ANASUL_API const c8* GetPlatformNameA();
	ANASUL_API const cwide* GetPlatformNameW();
	
}

// Anasul
