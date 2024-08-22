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
		
		boolean Create(const WindowCreateArgs<c8> &args) override;
		
		boolean Create(const WindowCreateArgs<cwide> &args) override;
		
		boolean Update() override;
		
		boolean Show() override;
		
		boolean Hide() override;
		
		boolean Notify(StringViewA tip) override;
		
		boolean Notify(StringViewW tip) override;
		
		boolean Close() override;
		
		boolean SetTitle(StringViewA title) override;
		
		boolean SetTitle(StringViewW title) override;
		
		boolean SetSize(i32 width, i32 height) override;
		
		boolean SetSize(u32 width, u32 height) override;
		
		boolean SetPosition(i32 x, i32 y) override;
		
		boolean SetInputPosition(i32 x, i32 y) override;
		
		boolean GetTitle(StringA &title) const override;
		
		boolean GetTitle(StringW &title) const override;
		
		boolean GetSize(i32 &width, i32 &height) const override;
		
		boolean GetSize(u32 &width, u32 &height) const override;
		
		boolean GetPosition(i32 &x, i32 &y) const override;
		
		boolean GetInputPosition(i32 &x, i32 &y) const override;
		
		[[nodiscard]] boolean IsOpen() const override;
		
		[[nodiscard]] boolean GetKeyDown(Key key) const override;
		
		[[nodiscard]] boolean GetKeyUp(Key key) const override;
		
		[[nodiscard]] boolean GetKeyPress(Key key) const override;
		
		[[nodiscard]] boolean GetMouseButtonDown(MouseButton button) const override;
		
		[[nodiscard]] boolean GetMouseButtonUp(MouseButton button) const override;
		
		[[nodiscard]] boolean GetMouseButtonPress(MouseButton button) const override;
		
		void GetMousePosition(i32 &x, i32 &y) const override;
	
	public:
		
		[[nodiscard]] HWND GetHWnd() const { return m_hWnd; }
		
		void SetHWnd(HWND hWnd)
		{
			Close();
			m_hWnd = hWnd;
		}
		
		[[nodiscard]] ATOM GetClassAtom() const { return m_classAtom; }
	
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
