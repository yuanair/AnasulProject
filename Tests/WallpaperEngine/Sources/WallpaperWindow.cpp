//
// Created by admin on 2024/8/23.
//

#include "WallpaperWindow.hpp"

#include "WallpaperEngineProgram.hpp"

void WallpaperWindow::Tick()
{
	m_renderTarget->BeginDraw();
	m_renderTarget->Clear(Anasul::Color4f(0.0f, 0.0f, 0.5f, 1.0f));
	Anasul::Point2i mousePos;
	m_window->GetMousePosition(mousePos.x, mousePos.y);
	m_renderTarget->DrawText(
		program.GetFont().get(),
		"Hello Anasul", Anasul::Rect4f(mousePos.x, mousePos.y, 100.0f, 100.0f),
		Anasul::Color4f(1.0f, 1.0f, 1.0f, 1.0f));
	m_renderTarget->EndDraw();
	m_window->Update();
}

WallpaperWindow::WallpaperWindow(WallpaperEngineProgram &program, Anasul::Icon *icon, Anasul::Icon *iconSm)
	: WindowBase(program, TEXT("Wallpaper Engine"), icon, iconSm, nullptr, true)
{
	Anasul::Platform::OnlyInWindows::RenderToDesktop(m_window.get());
	m_renderTarget.reset(program.GetRenderer()->CreateWindowRenderTarget(*m_window));
	m_window->Show();
}
