//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/Logger.hpp>
#include "Renderer.hpp"


#include <memory>

namespace Anasul
{
	/// 渲染器工厂
	class ANASUL_API RendererFactory
	{
	public:
		
		/// 创建渲染器
		static std::unique_ptr<Renderer> Create(RendererType type, Logger &logger);
		
	};
	
} // Anasul
