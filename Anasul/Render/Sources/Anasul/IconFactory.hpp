//
// Created by admin on 2024/8/23.
//

#pragma once

#include <Anasul/Config.hpp>
#include "Icon.hpp"

namespace Anasul
{
	
	enum IconType
	{
		Default,
		Windows,
	};
	
	/// 图标工厂
	class ANASUL_API IconFactory
	{
	public:
		
		static Icon *Create(IconType type);
		
	};
	
} // Anasul
