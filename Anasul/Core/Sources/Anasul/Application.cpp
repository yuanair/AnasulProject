//
// Created by admin on 2024/8/16.
//

#include "Application.hpp"

namespace Anasul
{
	
	boolean isRunning = false;
	
	i32 Application::Run(Program &program)
	{
		isRunning = true;
		program.BeginPlay();
		while (isRunning)
		{
			program.Tick();
		}
		program.EndPlay();
		
		return 0;
	}
	
	void Application::Exit()
	{
		isRunning = false;
	}
} // Anasul