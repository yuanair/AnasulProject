//
// Created by admin on 2024/8/23.
//

#include "WallpaperWindow.hpp"

#include "WallpaperEngineProgram.hpp"

void WallpaperWindow::Tick()
{
	m_renderTarget->BeginDraw();
	m_renderTarget->Clear(Anasul::Color4f(0.0f, 0.0f, 0.0f, 1.0f));
	Anasul::Point2i mousePos;
	m_window->GetMousePosition(mousePos.x, mousePos.y);
	m_renderTarget->FillCircle(Anasul::Point2f(mousePos.x, mousePos.y), 50.0f, Anasul::Color4f(1.0f, 0.0f, 0.0f, 0.2f));
	m_renderTarget->EndDraw();
	m_window->Update();
}

WallpaperWindow::WallpaperWindow(WallpaperEngineProgram &program, Anasul::Icon *icon, Anasul::Icon *iconSm)
	: WindowBase(program, {TEXT("Wallpaper Engine"), 0, 0, 0, 0, icon, iconSm, nullptr, true})
{
	Anasul::Platform::OnlyInWindows::RenderToDesktop(m_window.get());
	m_renderTarget.reset(program.GetRenderer()->CreateWindowRenderTarget(*m_window));
	m_window->Show();
	
	m_window->m_onResize = [this](Anasul::i32 width, Anasul::i32 height)
	{
		m_renderTarget->Resize(Anasul::Size2u(width, height));
	};
}
