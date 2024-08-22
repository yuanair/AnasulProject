//
// Created by admin on 2024/8/21.
//

#pragma once

#include "Config.hpp"
#include "String.hpp"

namespace Anasul
{
	/// 转换
	class ANASUL_API Conv
	{
	public:
		
		static StringW AToW(StringViewA c);
		
		static StringA WToA(StringViewW wp);
		
	};
	
} // Anasul
