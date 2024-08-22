//
// Created by admin on 2024/8/22.
//

#include "Platform.hpp"

#ifdef ANASUL_TARGET_WINDOWS

#include "Windows/Platform.impl"

#else

#error "Platform not supported!"

#endif

