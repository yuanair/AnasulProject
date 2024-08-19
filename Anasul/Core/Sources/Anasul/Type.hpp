//
// Created by admin on 2024/8/19.
//

#pragma once

#include "Config.hpp"

namespace Anasul
{
	
	extern "C"
	{
	
	/// 是否为EOF
	ANASUL_API boolean IsEOF(i32 ch);
	
	/// 是否为CR或LF
	ANASUL_API inline boolean IsCRLF(i32 ch) { return ch == '\n' || ch == '\r'; }
	
	/// 是否为可打印字符
	ANASUL_API inline boolean IsControl(i32 ch) { return ch >= '\x00' && ch <= '\x1F'; }
	
	/// 是否为可打印字符
	ANASUL_API inline boolean IsPrint(i32 ch) { return ch >= '\x20' && ch <= '\x7E'; }
	
	/// 是否为空格
	ANASUL_API inline boolean IsSpace(i32 ch) { return ch >= '\x09' && ch <= '\x0D' || ch == '\x20'; }
	
	/// 是否为空格
	ANASUL_API inline boolean IsGraph(i32 ch) { return ch >= '!' && ch <= '~'; }
	
	/// 是否为数字
	ANASUL_API inline boolean IsDigit(i32 ch) { return ch >= '0' && ch <= '9'; }
	
	/// 是否为大写字母
	ANASUL_API inline boolean IsUpper(i32 ch) { return ch >= 'A' && ch <= 'Z'; }
	
	/// 是否为小写字母
	ANASUL_API inline boolean IsLower(i32 ch) { return ch >= 'a' && ch <= 'z'; }
	
	/// 是否为字母
	ANASUL_API inline boolean IsAlpha(i32 ch) { return ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'; }
	
	/// 是否为空格
	ANASUL_API inline boolean IsPunctuation(i32 ch) { return IsGraph(ch) && !IsDigit(ch) && !IsAlpha(ch); }
		
	}
	
	
} // Anasul
