//
// Created by admin on 2024/8/20.
//

#include "RendererFactory.hpp"

#include "DirectX2D/DirectX2DRenderer.hpp"
#include "DirectX3D/DirectX3D12Renderer.hpp"
#include "DirectXWrite/DirectXWriteTextRenderer.hpp"
#include "OpenGL/OpenGLRenderer.hpp"
#include "Vulkan/VulkanRenderer.hpp"

namespace Anasul
{
	std::unique_ptr<Renderer> RendererFactory::CreateRenderer(RendererType type, Logger &logger)
	{
		logger.Log(LogLevel::Info, "Creating renderer of type: " + std::to_string(static_cast<int>(type)));
		switch (type)
		{
			case RendererType::DirectX2D:
				return std::make_unique<DirectX2DRenderer>();
			case RendererType::DirectX3D12:
				return std::make_unique<DirectX3D12Renderer>();
			case RendererType::OpenGL:
				return std::make_unique<OpenGLRenderer>();
			case RendererType::Vulkan:
				return std::make_unique<VulkanRenderer>();
			default:
				return {};
		}
	}
	
	std::unique_ptr<TextRenderer> RendererFactory::CreateTextRenderer(TextRendererType type, Logger &logger)
	{
		logger.Log(LogLevel::Info, "Creating text renderer of type: " + std::to_string(static_cast<int>(type)));
		switch (type)
		{
			case TextRendererType::DirectWrite:
				return std::make_unique<DirectXWriteTextRenderer>();
			default:
				return {};
		}
	}
} // Anasul