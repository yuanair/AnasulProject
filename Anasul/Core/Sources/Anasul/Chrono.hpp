//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"

#include <chrono>

namespace Anasul
{
	
	using SystemClock = std::chrono::system_clock;
	using SteadyClock = std::chrono::steady_clock;
	using HighResolutionClock = std::chrono::high_resolution_clock;
	using FileClock = std::chrono::file_clock;
	
	using SystemTime = std::chrono::time_point<std::chrono::system_clock>;
	using SteadyTime = std::chrono::time_point<std::chrono::steady_clock>;
	using HighResolutionTime = std::chrono::time_point<std::chrono::high_resolution_clock>;
	using FileTime = std::chrono::time_point<std::chrono::file_clock>;
	
} // Anasul
