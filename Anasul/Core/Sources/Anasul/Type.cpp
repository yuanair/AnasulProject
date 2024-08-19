//
// Created by admin on 2024/8/19.
//

#include "Type.hpp"

#include <cstdio>

namespace Anasul
{
	boolean IsEOF(i32 ch)
	{
		return ch == EOF || ch == WEOF;
	}
} // Anasul