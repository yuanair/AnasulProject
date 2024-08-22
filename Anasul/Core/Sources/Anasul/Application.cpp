//
// Created by admin on 2024/8/16.
//

#include "Application.hpp"
#include "Windows/Windows.hpp"
#include "Main.hpp"
#include "Version.hpp"
#include "Logger.hpp"

#include <format>

namespace Anasul
{
	
	#ifdef _WIN32
	
	i32 Application::Run()
	{
		::MSG msg;
		Program &program = AnasulMain();
		program.GetLogger().Log(
			Anasul::LogLevel::Info, std::format("{} {}", Anasul::GetNameA(), Anasul::GetVersionA()));
		program.GetLogger().Log(Anasul::LogLevel::Info, "BeginPlay()");
		program.BeginPlay();
		do
		{
			if (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				program.Tick();
			}
		}
		while (msg.message != WM_QUIT);
		program.GetLogger().Log(Anasul::LogLevel::Info, "EndPlay()");
		program.EndPlay();
		program.GetLogger().Log(Anasul::LogLevel::Info, "End of Application::Run()");
		program.GetLogger().Flush();
		return 0;
	}
	
	void Application::Exit()
	{
		::PostQuitMessage(0);
	}
	
	#else
	
	boolean _isRunning = false;
	
	i32 Application::Run(Program &program)
	{
		_isRunning = true;
		program.BeginPlay();
		while (_isRunning)
		{
			program.Tick();
		}
		program.EndPlay();
		
		return 0;
	}
	
	void Application::Exit()
	{
		_isRunning = false;
	}
	
	#endif
	
} // Anasul