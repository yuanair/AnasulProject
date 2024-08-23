//
// Created by admin on 2024/8/23.
//

#include "WindowBase.hpp"

#include "WallpaperEngineProgram.hpp"

WindowBase::WindowBase(WallpaperEngineProgram &program, Anasul::StringView windowName, Anasul::Icon *icon,
                       Anasul::Icon *iconSm, Anasul::Window *parent, Anasul::boolean isFrameless)
	: program(program)
{
	m_window = std::move(Anasul::WindowFactory::CreateWindow(Anasul::WindowType::Default, program.GetLogger()));
	if (!m_window->Create(
		Anasul::WindowCreateArgs<Anasul::chararcter>{
			windowName, 0, 0, INT_MIN, INT_MIN, icon, iconSm, parent, isFrameless
		}
	))
	{
		Anasul::Platform::FatalExit(program.GetLogger(), TEXT("cannot create window"), windowName);
		return;
	}
}
