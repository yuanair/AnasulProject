//
// Created by admin on 2024/8/17.
//

#pragma once

#include <Anasul/Config.hpp>
#include "Token.hpp"

namespace Anasul
{
	/// 词法分析器
	template<class ElemT>
	class ANASUL_API Lexer
	{
	public:
		
		virtual ~Lexer() = default;
	
	public:
		
		/// 分析下一个
		virtual Token<ElemT> *AnalysisNext() = 0;
		
		/// 是否结束了
		virtual boolean IsEnd() = 0;
		
	};
	
} // Anasul
