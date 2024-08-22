//
// Created by admin on 2024/8/21.
//

#pragma once

#include <Anasul/Windows/Windows.hpp>
#include <Anasul/Config.hpp>
#include <Anasul/Logger.hpp>
#include "../Window.hpp"

namespace Anasul
{
	
	
	class ANASUL_API WindowsWindow : public Window, public Logable
	{
	public:
		
		explicit WindowsWindow(Logger &logger);
		
		~WindowsWindow() override;
	
	public:
		
		static LPSTR GetDefaultWindowClassA();
		
		static LPWSTR GetDefaultWindowClassW();
		
		static ATOM RegisterWindowClass(StringViewA className, WNDPROC wndProc, HICON icon, HCURSOR cursor);
		
		static ATOM RegisterWindowClass(StringViewW className, WNDPROC wndProc, HICON icon, HCURSOR cursor);
	
	public:
		
		boolean Create(StringViewA title, i32 width, i32 height) override;
		
		boolean Create(StringViewW title, i32 width, i32 height) override;
		
		boolean Update() override;
		
		boolean Show() override;
		
		boolean Hide() override;
		
		boolean Notify(StringViewA tip) override;
		
		boolean Notify(StringViewW tip) override;
		
		boolean Close() override;
		
		[[nodiscard]] boolean IsOpen() const override;
		
		boolean SetTitle(StringViewA title) override;
		
		boolean SetTitle(StringViewW title) override;
		
		boolean SetSize(i32 width, i32 height) override;
		
		boolean SetPosition(i32 x, i32 y) override;
		
		boolean SetInputPosition(i32 x, i32 y) override;
		
		boolean GetTitle(StringA &title) const override;
		
		boolean GetTitle(StringW &title) const override;
		
		boolean GetSize(i32 &width, i32 &height) const override;
		
		boolean GetPosition(i32 &x, i32 &y) const override;
		
		boolean GetInputPosition(i32 &x, i32 &y) const override;
	
	private:
		
		static LRESULT CALLBACK WndProcA(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		static LRESULT CALLBACK WndProcW(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	
	private:
		
		LRESULT OnMessageA(UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		LRESULT OnMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam);
		
		LRESULT OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, WNDPROC wndProc);
		
		boolean SetDarkMode(BOOL darkMode);
	
	private:
		
		HWND m_hWnd;
		
		ATOM m_classAtom;
		
		POINT m_inputBoxPos;
		
	};
	
	
}
