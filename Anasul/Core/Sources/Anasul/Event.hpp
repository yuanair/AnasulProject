//
// Created by admin on 2024/8/23.
//

#pragma once

#include "Config.hpp"

#include <functional>

namespace Anasul
{
	
	template<class T>
	using Event = std::function<T>;
	
} // Anasul
