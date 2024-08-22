//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/Platform.hpp>

#include "../Window.hpp"

#include <GLFW/glfw3.h>

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
		
		boolean Create(StringViewA title, i32 width, i32 height) override;
		
		boolean Create(StringViewW title, i32 width, i32 height) override;
		
		boolean Update() override;
		
		boolean Show() override;
		
		boolean Hide() override;
		
		boolean Close() override;
		
		[[nodiscard]] boolean IsOpen() const override;
		
		boolean SetTitle(StringViewA title) override;
		
		boolean SetTitle(StringViewW title) override;
		
		boolean SetSize(i32 width, i32 height) override;
		
		boolean SetPosition(i32 x, i32 y) override;
		
		boolean SetInputPosition(i32 x, i32 y) override { return false; }
		
		boolean GetTitle(StringA &title) const override;
		
		boolean GetTitle(StringW &title) const override;
		
		boolean GetSize(i32 &width, i32 &height) const override;
		
		boolean GetPosition(i32 &x, i32 &y) const override;
		
		boolean GetInputPosition(i32 &x, i32 &y) const override { return false; }
		
		boolean Notify(StringViewA title) override;
		
		boolean Notify(StringViewW title) override;
	
	private:
		
		static boolean PrivateInitGLFW();
	
	private:
		
		::GLFWwindow *m_window;
		
	};
	
} // Anasul
