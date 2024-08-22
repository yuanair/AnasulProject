//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>

namespace Anasul
{
	
	class Window;
	
	class WindowRenderTarget;
	
	/// 渲染器
	class ANASUL_API Renderer
	{
	public:
		
		virtual ~Renderer() = default;
	
	public:
		
		/// 创建窗口渲染目标
		virtual WindowRenderTarget *CreateWindowRenderTarget(const Window &window) = 0;
		
	};
	
} // Anasul
