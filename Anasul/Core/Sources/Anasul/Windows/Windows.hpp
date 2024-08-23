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

#undef CreateWindow
#undef GetCommandLine
#undef GetModuleHandle
#undef FindWindow
#undef SendMessage
#undef PostMessage
#undef MessageBox
#undef LoadLibrary
#undef LoadIcon
#undef LoadCursor
#undef LoadImage
