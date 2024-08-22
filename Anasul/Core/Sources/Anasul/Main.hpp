//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "Program.hpp"
#include "Application.hpp"

#ifdef _WIN32

#include <Windows.h>

int main(int argc, char *argv[]);

int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int);

#else

int main(int argc, char *argv[]);

#endif

/// 入口函数
extern Anasul::Program &AnasulMain(); // NOLINT(*-redundant-declaration)
