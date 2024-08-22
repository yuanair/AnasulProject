//
// Created by admin on 2024/8/22.
//

#include "Platform.hpp"

#include "Windows/WindowsPlatform.hpp"

namespace Anasul
{
	Platform &Platform::Get()
	{
		return WindowsPlatform::Get();
	}
	
} // Anasul