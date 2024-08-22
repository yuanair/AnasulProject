//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/Logger.hpp>

#include "Window.hpp"
#include <memory>

namespace Anasul
{
	
	enum class WindowType
	{
		Default,
		Windows,
		GLFW,
	};
	
	class ANASUL_API WindowFactory
	{
	public:
		
		/// 创建窗口
		static std::unique_ptr<Window> CreateWindow(WindowType type, Logger &logger);
		
	};
	
} // Anasul
