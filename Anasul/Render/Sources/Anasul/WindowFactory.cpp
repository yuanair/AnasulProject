//
// Created by admin on 2024/8/20.
//

#include "WindowFactory.hpp"
#include "GLFW/GLFWWindow.hpp"

namespace Anasul
{
	std::unique_ptr<Window> WindowFactory::CreateWindow(WindowType type)
	{
		switch (type)
		{
			case WindowType::GLFW:
				return std::make_unique<GLFWWindow>();
			default:
				return {};
		}
	}
} // Anasul