//
// Created by admin on 2024/8/20.
//

#pragma once

#include "../Renderer.hpp"

namespace Anasul
{
	/// Vulkan渲染器
	class ANASUL_API VulkanRenderer : public Renderer
	{
	public:
		void Init() override;
	};
	
} // Anasul
