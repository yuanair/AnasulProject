//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>

namespace Anasul
{
	
	enum class RendererType
	{
		DirectX3D12,
		OpenGL,
		Vulkan
	};
	
	/// 渲染器
	class ANASUL_API Renderer
	{
	public:
		
		virtual ~Renderer() = default;
	
	public:
		
		/// 初始化渲染器
		virtual void Init() = 0;
		
	};
	
} // Anasul
