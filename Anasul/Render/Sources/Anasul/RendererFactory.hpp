//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/Logger.hpp>
#include "Renderer.hpp"
#include "TextRenderer.hpp"


#include <memory>

namespace Anasul
{
	enum class RendererType
	{
		DirectX2D,
		DirectX3D12,
		OpenGL,
		Vulkan
	};
	
	enum class TextRendererType
	{
		DirectWrite
	};
	
	/// 渲染器工厂
	class ANASUL_API RendererFactory
	{
	public:
		
		/// 创建渲染器
		static std::unique_ptr<Renderer> CreateRenderer(RendererType type, Logger &logger);
		
		/// 创建文字渲染器
		static std::unique_ptr<TextRenderer> CreateTextRenderer(TextRendererType type, Logger &logger);
		
	};
	
} // Anasul
