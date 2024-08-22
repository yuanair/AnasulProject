//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/Platform.hpp>

#include "../Window.hpp"

#ifdef ANASUL_TARGET_WINDOWS

#define GLFW_EXPOSE_NATIVE_WIN32

#endif

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include <windef.h>

namespace Anasul
{
	
	class ANASUL_API GLFWWindow : public Window
	{
	public:
		
		/// 初始化 GLFW
		static boolean InitGLFW();
	
	public:
		
		GLFWWindow();
		
		~GLFWWindow() override;
	
	public:
		
		boolean Create(const WindowCreateArgs<c8> &args) override;
		
		boolean Create(const WindowCreateArgs<cwide> &args) override;
		
		boolean Update() override;
		
		boolean Show() override;
		
		boolean Hide() override;
		
		boolean Close() override;
		
		boolean SetTitle(StringViewA title) override;
		
		boolean SetTitle(StringViewW title) override;
		
		boolean SetSize(i32 width, i32 height) override;
		
		boolean SetSize(u32 width, u32 height) override;
		
		boolean SetPosition(i32 x, i32 y) override;
		
		boolean SetInputPosition(i32 x, i32 y) override { return false; }
		
		boolean GetTitle(StringA &title) const override;
		
		boolean GetTitle(StringW &title) const override;
		
		boolean GetSize(i32 &width, i32 &height) const override;
		
		boolean GetSize(u32 &width, u32 &height) const override;
		
		boolean GetPosition(i32 &x, i32 &y) const override;
		
		boolean GetInputPosition(i32 &x, i32 &y) const override { return false; }
		
		boolean Notify(StringViewA title) override;
		
		boolean Notify(StringViewW title) override;
		
		[[nodiscard]] boolean IsOpen() const override;
		
		boolean GetKeyDown(Key key) const override;
		
		boolean GetKeyUp(Key key) const override;
		
		boolean GetKeyPress(Key key) const override;
		
		boolean GetMouseButtonDown(MouseButton button) const override;
		
		boolean GetMouseButtonUp(MouseButton button) const override;
		
		boolean GetMouseButtonPress(MouseButton button) const override;
		
		void GetMousePosition(i32 &x, i32 &y) const override;
	
	public:
		
		#ifdef ANASUL_TARGET_WINDOWS
		
		[[nodiscard]] HWND GetHWnd() const { return glfwGetWin32Window(m_window); }
		
		#endif
	
	private:
		
		static boolean PrivateInitGLFW();
	
	private:
		
		::GLFWwindow *m_window;
		
	};
	
} // Anasul
