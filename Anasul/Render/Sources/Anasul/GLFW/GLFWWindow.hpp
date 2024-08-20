//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>

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
		
		void Create(StringViewA title, i32 width, i32 height) override;
		
		void Update() override;
		
		void Close() override;
		
		[[nodiscard]] boolean IsOpen() const override;
		
		void SetTitle(StringViewA title) override;
		
		void SetSize(i32 width, i32 height) override;
		
		void SetPosition(i32 x, i32 y) override;
		
		void GetTitle(StringViewA &title) override;
		
		void GetSize(i32 &width, i32 &height) override;
		
		void GetPosition(i32 &x, i32 &y) override;
	
	private:
		
		static boolean PrivateInitGLFW();
	
	private:
		
		::GLFWwindow *m_window;
		
	};
	
} // Anasul
