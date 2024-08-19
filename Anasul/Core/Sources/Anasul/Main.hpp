//
// Created by admin on 2024/8/16.
//

#pragma once

/// 入口函数
Anasul::Program &AnasulMain(); // NOLINT(*-redundant-declaration)

#ifdef _WIN32

#include <Windows.h>
#include <tchar.h>

#include "Config.hpp"
#include "Program.hpp"
#include "Application.hpp"

int main(int argc, char *argv[])
{
	return Anasul::Application::Run(AnasulMain());
}

int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	return Anasul::Application::Run(AnasulMain());
}

#else

#include "Config.hpp"
#include "Program.hpp"
#include "Application.hpp"

int main(int argc, char *argv[])
{
	return Anasul::Application::Run(AnasulMain());
}

#endif
