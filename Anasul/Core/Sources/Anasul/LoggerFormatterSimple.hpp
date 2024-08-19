//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "LoggerFormatter.hpp"
#include "Logger.hpp"

namespace Anasul
{
	
	/// 简单日志格式化器
	class ANASUL_API LoggerFormatterSimple : public LoggerFormatter
	{
	public:
		
		StringA Format(const LoggerFormatterArg &arg, StringViewA message) override;
		
		StringW Format(const LoggerFormatterArg &arg, StringViewW message) override;
		
	};
	
} // Anasul
