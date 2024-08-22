//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Main.hpp"

#ifdef _WIN32

#include <Windows.h>
#include <tchar.h>

#include "Program.hpp"
#include "Application.hpp"

int main(int argc, char *argv[])
{
	return Anasul::Application::Run();
}

int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	return Anasul::Application::Run();
}

#else

#include "Program.hpp"
#include "Application.hpp"

int main(int argc, char *argv[])
{
	return Anasul::Application::Run();
}

#endif
