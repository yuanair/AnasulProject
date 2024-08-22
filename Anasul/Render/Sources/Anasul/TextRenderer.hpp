//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/String.hpp>
#include <Anasul/Math.hpp>
#include "RenderTarget.hpp"

namespace Anasul
{
	
	/// 文字渲染器
	class ANASUL_API TextRenderer
	{
	public:
		
		virtual ~TextRenderer() = default;
	
	public:
		
		/// 创建字体
		virtual Font *CreateFont(const StringA &fontName, float size) = 0;
		
		/// 创建字体
		virtual Font *CreateFont(const StringW &fontName, float size) = 0;
		
	};
	
} // Anasul
