//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/Math.hpp>
#include "Anasul/String.hpp"
#include "Font.hpp"

namespace Anasul
{
	
	/// 渲染目标类
	class ANASUL_API RenderTarget
	{
	public:
		
		virtual ~RenderTarget() = default;
	
	public:
		
		/// 开始绘制
		virtual void BeginDraw() = 0;
		
		/// 清空屏幕
		virtual void Clear(const Color4f &color) = 0;
		
		/// 绘制文字
		virtual void DrawText(const Font &font,
		                      const StringA &text, const Rect4f &rect, const Color4f &color) = 0;
		
		/// 绘制文字
		virtual void DrawText(const Font &font,
		                      const StringW &text, const Rect4f &rect, const Color4f &color) = 0;
		
		/// 结束绘制
		virtual void EndDraw() = 0;
		
	};
	
} // Anasul
