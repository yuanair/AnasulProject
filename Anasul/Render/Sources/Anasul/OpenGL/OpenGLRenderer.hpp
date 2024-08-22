//
// Created by admin on 2024/8/20.
//

#pragma once

#include "../Renderer.hpp"

namespace Anasul
{
	/// OpenGL渲染器
	class ANASUL_API OpenGLRenderer : public Renderer
	{
	public:
		
		WindowRenderTarget *CreateWindowRenderTarget(const Window &window) override;
		
	};
	
} // Anasul
