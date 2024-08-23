//
// Created by admin on 2024/8/23.
//

#include "TrayMenuWindow.hpp"

#include "WallpaperEngineProgram.hpp"

void TrayMenuWindow::Tick()
{
	m_window->Update();
}

TrayMenuWindow::TrayMenuWindow(WallpaperEngineProgram &program, Anasul::Icon *icon, Anasul::Icon *iconSm)
	: WindowBase(program, TEXT("TrayMenuWindow"), icon, iconSm, nullptr, true)
{
	m_window->Notify(program.GetProgramName(), iconSm);
	m_renderTarget.reset(program.GetRenderer()->CreateWindowRenderTarget(*m_window));
}
