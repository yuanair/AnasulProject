//
// Created by admin on 2024/8/19.
//

#pragma once

#include "Config.hpp"

#include <cstdio>
#include <cwchar>

namespace Anasul
{
	
	/// 类型
	class ANASUL_API Type
	{
	public:
		
		// EOF
		static const i32 eof;
		
		// WEOF
		static const i32 weof;
	
	public:
		
		/// 是否为EOF
		static inline boolean IsEOF(i32 ch) { return ch == Type::eof || ch == Type::weof; }
		
		/// 是否为CR或LF
		static inline boolean IsCRLF(i32 ch) { return ch == '\n' || ch == '\r'; }
		
		/// 是否为可打印字符
		static inline boolean IsControl(i32 ch) { return ch >= '\x00' && ch <= '\x1F'; }
		
		/// 是否为可打印字符
		static inline boolean IsPrint(i32 ch) { return ch >= '\x20' && ch <= '\x7E'; }
		
		/// 是否为空格
		static inline boolean IsSpace(i32 ch) { return ch >= '\x09' && ch <= '\x0D' || ch == '\x20'; }
		
		/// 是否为空格
		static inline boolean IsGraph(i32 ch) { return ch >= '!' && ch <= '~'; }
		
		/// 是否为数字
		static inline boolean IsDigit(i32 ch) { return ch >= '0' && ch <= '9'; }
		
		/// 是否为大写字母
		static inline boolean IsUpper(i32 ch) { return ch >= 'A' && ch <= 'Z'; }
		
		/// 是否为小写字母
		static inline boolean IsLower(i32 ch) { return ch >= 'a' && ch <= 'z'; }
		
		/// 是否为字母
		static inline boolean IsAlpha(i32 ch) { return ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'; }
		
		/// 是否为空格
		static inline boolean IsPunctuation(i32 ch) { return IsGraph(ch) && !IsDigit(ch) && !IsAlpha(ch); }
		
	};
	
	const i32 Type::eof = EOF;
	
	const i32 Type::weof = WEOF;
	
	
} // Anasul
