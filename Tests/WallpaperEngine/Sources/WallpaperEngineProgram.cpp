//
// Created by admin on 2024/8/23.
//

#include "WallpaperEngineProgram.hpp"

#include "./TrayMenuWindow.hpp"
#include "./WallpaperWindow.hpp"

void WallpaperEngineProgram::EndPlay()
{
	m_windows.clear();
	m_renderer.reset();
	m_dWriteRenderer.reset();
	m_font.reset();
	m_icon.reset();
	m_iconSm.reset();
}

void WallpaperEngineProgram::Tick()
{
	for (auto &window: m_windows)
	{
		window->Tick();
	}
}

void WallpaperEngineProgram::BeginPlay()
{
	
	// 注册启动项
	Anasul::String startUpFileName =
		TEXT("\"") + (std::filesystem::current_path() / std::format(TEXT("{}.exe"), AppName)).wstring() +
		TEXT("\"");
	Anasul::String buffer;
	if (Anasul::Platform::OnlyInWindows::GetBootStartUp(AppName, buffer))
	{
		if (buffer != startUpFileName)
		{
			GetLogger().Log(Anasul::LogLevel::Error, std::format(TEXT("Error Boot start up: {}"), buffer));
			Anasul::Platform::OnlyInWindows::DeleteBootStartUp(AppName);
			Anasul::Platform::OnlyInWindows::SetBootStartUp(AppName, startUpFileName);
			GetLogger().Log(
				Anasul::LogLevel::Info, std::format(TEXT("Set Boot start up: {}"), startUpFileName));
		}
		else
		{
			GetLogger().Log(Anasul::LogLevel::Info, std::format(TEXT("Boot start up: {}"), buffer));
		}
	}
	else
	{
		Anasul::Platform::OnlyInWindows::SetBootStartUp(AppName, startUpFileName);
		GetLogger().Log(
			Anasul::LogLevel::Info, std::format(TEXT("Set Boot start up: {}"), startUpFileName));
	}
	
	std::filesystem::current_path(std::filesystem::current_path() / "Data");
	
	GetLogger().Log(Anasul::LogLevel::Info, TEXT("Current path: ") + std::filesystem::current_path().wstring());
	
	if (!Anasul::Platform::OnlyInWindows::IsAeroEnabled())
	{
		Anasul::Platform::FatalExit(GetLogger(), TEXT("Aero is not enabled"), AppName);
		return;
	}
	
	m_renderer = Anasul::RendererFactory::CreateRenderer(Anasul::RendererType::DirectX2D, GetLogger());
	m_dWriteRenderer = Anasul::RendererFactory::CreateTextRenderer(
		Anasul::TextRendererType::DirectWrite, GetLogger());
	
	m_icon.reset(Anasul::IconFactory::Create(Anasul::Default));
	m_iconSm.reset(Anasul::IconFactory::Create(Anasul::Default));
	m_icon->Reload((std::filesystem::current_path() / "Icon.ico").wstring());
	m_iconSm->Reload((std::filesystem::current_path() / "IconSm.ico").wstring());
	
	m_windows.emplace_back(std::make_unique<TrayMenuWindow>(*this, m_icon.get(), m_iconSm.get()));
	m_windows.emplace_back(std::make_unique<WallpaperWindow>(*this, m_icon.get(), m_iconSm.get()));
	
	m_font.reset(m_dWriteRenderer->CreateFont(L"Consolas", 16));
}

Anasul::Logger &WallpaperEngineProgram::GetLogger()
{
	return *m_logger;
}

WallpaperEngineProgram::WallpaperEngineProgram()
	: m_renderer(nullptr), m_dWriteRenderer(nullptr), m_font(nullptr),
	  m_icon(nullptr), m_iconSm(nullptr), m_windows(), m_logger()
{
	m_logFileA.open("AnasulWallpaperEngine.log", std::ios::out | std::ios::app);
	m_logFileW.open("AnasulWallpaperEngine.log", std::ios::out | std::ios::app);
	m_formatter = std::make_unique<Anasul::LoggerFormatterSimple>();
	m_logger = std::make_unique<Anasul::LoggerToStream>(*m_formatter, m_logFileA, m_logFileW);
}
