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
		
		virtual ~Program() = default;
	
	public:
		
		virtual class Logger &GetLogger() = 0;
		
		virtual void BeginPlay() = 0;
		
		virtual void Tick() = 0;
		
		virtual void EndPlay() = 0;
		
	};
	
} // Anasul
