//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include "../WindowRenderTarget.hpp"
#include "../Window.hpp"

namespace Anasul
{
	
	class ANASUL_API OpenGLWindowRenderTarget : public WindowRenderTarget
	{
	public:
		
		explicit OpenGLWindowRenderTarget(Window &window);
		
		~OpenGLWindowRenderTarget() override;
	
	private:
		
		Window &m_window;
		
	};
	
} // Anasul
