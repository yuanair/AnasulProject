//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "Program.hpp"
#include "Application.hpp"

#ifdef _WIN32

//	#ifdef _WINDOWS
//		#ifdef UNICODE
//			#pragma comment(linker, "/entry:wWinMainCRTStartup")
//		#else
//			#pragma comment(linker, "/entry:WinMainCRTStartup")
//		#endif
//	#elif defined(_CONSOLE)
//		#ifdef UNICODE
//			#pragma comment(linker, "/entry:wmainCRTStartup")
//		#else
//			#pragma comment(linker, "/entry:mainCRTStartup")
//		#endif
//	#elif defined(_DLL)
//		#pragma comment(linker, "/entry:DllMainCRTStartup")
//	#endif

#include <Windows.h>

/// 入口函数
Anasul::Program &AnasulMain(); // NOLINT(*-redundant-declaration)

int _tmain(int argc, TCHAR *argv[])
{
	return Anasul::Application::Run(AnasulMain());
}

int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	return Anasul::Application::Run(AnasulMain());
}

#else

int main(int argc, char *argv[])
{
	return Anasul::Application::Run(AnasulMain());
}

#endif

