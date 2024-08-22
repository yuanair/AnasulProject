//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"

namespace Anasul
{
	
	class ANASUL_API Program
	{
	public:
		
		Program() = default;
		
		virtual ~Program() = default;
	
	public:
		
		/// 日志（如果AnasulMain中返回的Program中配置了日志，则所有日志信息会输出到该日志）
		virtual class Logger &GetLogger() = 0;
		
		/// 启动
		virtual void BeginPlay() = 0;
		
		/// 每帧
		virtual void Tick() = 0;
		
		/// 结束
		virtual void EndPlay() = 0;
		
	};
	
} // Anasul
