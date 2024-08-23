//
// Created by admin on 2024/8/23.
//

#include "WindowBase.hpp"

#include "WallpaperEngineProgram.hpp"

WindowBase::WindowBase(WallpaperEngineProgram &program, const Anasul::WindowCreateArgs<Anasul::chararcter> &args)
	: program(program)
{
	m_window = std::move(Anasul::WindowFactory::CreateWindow(Anasul::WindowType::Default, program.GetLogger()));
	if (!m_window->Create(args))
	{
		Anasul::Platform::FatalExit(program.GetLogger(), TEXT("cannot create window"), args.m_title);
		return;
	}
}
