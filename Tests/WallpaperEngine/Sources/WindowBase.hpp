//
// Created by admin on 2024/8/23.
//

#pragma once

#include <Anasul/Application.hpp>
#include <Anasul/Logger.hpp>

#include <Anasul/WindowFactory.hpp>
#include <Anasul/RendererFactory.hpp>
#include <Anasul/WindowRenderTarget.hpp>
#include <Anasul/IconFactory.hpp>
#include <Anasul/Platform.hpp>

class WallpaperEngineProgram;

class WindowBase
{
public:
	explicit WindowBase(WallpaperEngineProgram &program, const Anasul::WindowCreateArgs<Anasul::chararcter> &args);
	
	
	virtual ~WindowBase() = default;

public:
	
	virtual void Tick() = 0;

protected:
	
	WallpaperEngineProgram &program;
	
	std::unique_ptr<Anasul::Window> m_window;
	
	std::unique_ptr<Anasul::WindowRenderTarget> m_renderTarget;
	
};
