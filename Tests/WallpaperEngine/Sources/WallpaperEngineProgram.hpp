//
// Created by admin on 2024/8/23.
//

#pragma once

#include <Anasul/Program.hpp>
#include <Anasul/Application.hpp>
#include <Anasul/LoggerToStream.hpp>
#include <Anasul/LoggerFormatterSimple.hpp>

#include <Anasul/WindowFactory.hpp>
#include <Anasul/RendererFactory.hpp>
#include <Anasul/WindowRenderTarget.hpp>
#include <Anasul/IconFactory.hpp>
#include <Anasul/Platform.hpp>
#include "WindowBase.hpp"

#include <thread>
#include <format>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cassert>

class WallpaperEngineProgram : public Anasul::Program
{
public:
	
	static constexpr Anasul::chararcter AppName[] = TEXT("AnasulWallpaperEngine");

public:
	
	WallpaperEngineProgram();

public:
	
	inline Anasul::String GetProgramName() const override
	{
		return AppName;
	}
	
	Anasul::Logger &GetLogger() override;
	
	inline Anasul::Renderer *GetRenderer() override
	{
		return m_renderer.get();
	}
	
	inline Anasul::TextRenderer *GetTextRenderer() override
	{
		return m_dWriteRenderer.get();
	}
	
	void BeginPlay() override;
	
	void Tick() override;
	
	void EndPlay() override;
	
	
	[[nodiscard]] auto &GetFont() { return m_font; }
	
	[[nodiscard]] auto &GetFont() const { return m_font; }

private:
	
	std::vector<std::unique_ptr<WindowBase>> m_windows;
	
	std::unique_ptr<Anasul::Renderer> m_renderer;
	std::unique_ptr<Anasul::TextRenderer> m_dWriteRenderer;
	std::unique_ptr<Anasul::Font> m_font;
	
	std::unique_ptr<Anasul::Icon> m_icon;
	std::unique_ptr<Anasul::Icon> m_iconSm;
	
	std::ofstream m_logFileA;
	std::wofstream m_logFileW;
	std::unique_ptr<Anasul::LoggerToStream> m_logger;
	std::unique_ptr<Anasul::LoggerFormatterSimple> m_formatter;
	
};
