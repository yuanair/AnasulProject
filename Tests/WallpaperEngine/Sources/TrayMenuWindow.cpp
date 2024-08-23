//
// Created by admin on 2024/8/23.
//

#include "TrayMenuWindow.hpp"

#include "WallpaperEngineProgram.hpp"

void TrayMenuWindow::Tick()
{
	m_renderTarget->BeginDraw();
	m_renderTarget->Clear(Anasul::Color4f(0.0f, 0.0f, 0.0f, 1.0f));
	Anasul::Point2i mousePos;
	m_window->GetMousePosition(mousePos.x, mousePos.y);
	m_renderTarget->FillCircle(Anasul::Point2f(mousePos.x, mousePos.y), 50.0f, Anasul::Color4f(1.0f, 0.0f, 0.0f, 0.2f));
	m_renderTarget->EndDraw();
	m_window->Update();
}

TrayMenuWindow::TrayMenuWindow(WallpaperEngineProgram &program, Anasul::Icon *icon, Anasul::Icon *iconSm)
	: WindowBase(program, {TEXT("TrayMenuWindow"), 0, 0, 400, 300, icon, iconSm, nullptr, false})
{
	m_window->Notify(program.GetProgramName(), iconSm);
	m_renderTarget.reset(program.GetRenderer()->CreateWindowRenderTarget(*m_window));
	m_window->m_onMouseDown = [this](Anasul::i32 x, Anasul::i32 y, Anasul::MouseButton button)
	{
		if (button == Anasul::MouseButtonRight)
		{
			m_window->SetPosition(x, y);
			m_window->Show();
		}
	};
	m_window->m_onInactive = [this]()
	{
		m_window->Hide();
	};
	m_window->m_onResize = [this](Anasul::i32 width, Anasul::i32 height)
	{
		m_renderTarget->Resize(Anasul::Size2u(width, height));
	};
}
