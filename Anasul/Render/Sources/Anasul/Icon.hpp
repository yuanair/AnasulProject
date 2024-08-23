//
// Created by admin on 2024/8/23.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/String.hpp>

namespace Anasul
{
	
	/// 图标
	class ANASUL_API Icon
	{
	public:
		
		virtual ~Icon() = default;
	
	public:
		
		virtual boolean Reload(const StringViewA &filename) = 0;
		
		virtual boolean Reload(const StringViewW &filename) = 0;
		
	};
	
} // Anasul
