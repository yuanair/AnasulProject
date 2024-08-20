//
// Created by admin on 2024/8/20.
//

#include "RendererFactory.hpp"

#include "DirectX/DirectX3D12Renderer.hpp"
#include "OpenGL/OpenGLRenderer.hpp"
#include "Vulkan/VulkanRenderer.hpp"

namespace Anasul
{
	std::unique_ptr<Renderer> RendererFactory::Create(RendererType type)
	{
		switch (type)
		{
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
} // Anasul