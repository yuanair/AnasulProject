//
// Created by admin on 2024/8/21.
//

#pragma once

#include <Windows.h>
#include <dwmapi.h>
#include <imm.h>
#include <ShlObj.h>

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif


#ifdef GetCommandLine
#undef GetCommandLine
#endif

#ifdef GetModuleHandle
#undef GetModuleHandle
#endif

