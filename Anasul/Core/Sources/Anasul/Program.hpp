//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "String.hpp"

namespace Anasul
{
	
	class Logger;
	
	class Renderer;
	
	class TextRenderer;
	
	class ANASUL_API Program
	{
	public:
		
		Program() = default;
		
		virtual ~Program() = default;
	
	public:
		
		/// 获取程序名称
		[[nodiscard]] virtual String GetProgramName() const = 0;
		
		/// 日志（如果AnasulMain中返回的Program中配置了日志，则所有日志信息会输出到该日志）
		virtual Logger &GetLogger() = 0;
		
		/// 获取渲染器
		virtual Renderer *GetRenderer() = 0;
		
		/// 获取文字渲染器
		virtual TextRenderer *GetTextRenderer() = 0;
		
		/// 启动
		virtual void BeginPlay() = 0;
		
		/// 每帧
		virtual void Tick() = 0;
		
		/// 结束
		virtual void EndPlay() = 0;
		
	};
	
} // Anasul
