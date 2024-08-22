//
// Created by admin on 2024/8/20.
//

#include "WindowFactory.hpp"
#include "GLFW/GLFWWindow.hpp"
#include "Windows/WindowsWindow.hpp"

#undef CreateWindow

namespace Anasul
{
	std::unique_ptr<Window> WindowFactory::CreateWindow(WindowType type, Logger &logger)
	{
		logger.Log(LogLevel::Info, "Creating window of type: " + std::to_string(static_cast<int>(type)));
		switch (type)
		{
			case WindowType::Default:
				#ifdef _WIN32
				return std::make_unique<WindowsWindow>(logger);
				#else
				return std::make_unique<GLFWWindow>();
				#endif
			case WindowType::Windows:
				return std::make_unique<WindowsWindow>(logger);
			case WindowType::GLFW:
				return std::make_unique<GLFWWindow>();
			default:
				return {};
		}
	}
} // Anasul