//
// Created by admin on 2024/8/21.
//

#pragma once

#include <Anasul/String.hpp>
#include "../Config.hpp"

namespace Anasul
{
	
	using HResult = i32;
	
	template<typename ElemT>
	ANASUL_API BasicString<ElemT> MessageToString(HResult dwMessageId);
	
	ANASUL_API HResult LastErrorForHResult();
	
} // Anasul
