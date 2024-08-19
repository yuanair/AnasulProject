//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "Program.hpp"

namespace Anasul
{
	
	/// 关于应用的实用功能
	class ANASUL_API Application
	{
	public:
		
		/// 运行程序
		static i32 Run(Program &program);
		
		/// 退出
		static void Exit();
		
	};
	
} // Anasul
