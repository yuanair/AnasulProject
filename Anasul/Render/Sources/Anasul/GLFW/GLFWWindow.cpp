//
// Created by admin on 2024/8/20.
//

#include "GLFWWindow.hpp"

#include <Anasul/Conv.hpp>

namespace Anasul
{
	boolean GLFWWindow::InitGLFW()
	{
		static const boolean result = PrivateInitGLFW();
		return result;
	}
	
	GLFWWindow::GLFWWindow()
		: m_window(nullptr)
	{
	}
	
	GLFWWindow::~GLFWWindow()
	{
		GLFWWindow::Close();
		glfwTerminate();
	}
	
	boolean GLFWWindow::Create(StringViewA title, i32 width, i32 height)
	{
		if (!glfwInit()) return false;
		m_window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
		
		glfwMakeContextCurrent(m_window);
		return IsOpen();
	}
	
	boolean GLFWWindow::Create(StringViewW title, i32 width, i32 height)
	{
		if (!glfwInit()) return false;
		m_window = glfwCreateWindow(width, height, Conv::WToA(title).data(), nullptr, nullptr);
		
		glfwMakeContextCurrent(m_window);
		return IsOpen();
	}
	
	boolean GLFWWindow::Show()
	{
		glfwShowWindow(m_window);
		return true;
	}
	
	boolean GLFWWindow::Hide()
	{
		glfwHideWindow(m_window);
		return true;
	}
	
	boolean GLFWWindow::Update()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
		return IsOpen();
	}
	
	boolean GLFWWindow::Close()
	{
		glfwDestroyWindow(m_window);
		m_window = nullptr;
		return true;
	}
	
	boolean GLFWWindow::IsOpen() const
	{
		return m_window != nullptr;
	}
	
	boolean GLFWWindow::SetTitle(StringViewA title)
	{
		glfwSetWindowTitle(m_window, title.data());
		return true;
	}
	
	boolean GLFWWindow::SetTitle(StringViewW title)
	{
		glfwSetWindowTitle(m_window, Conv::WToA(title).data());
		return true;
	}
	
	boolean GLFWWindow::SetSize(i32 width, i32 height)
	{
		glfwSetWindowSize(m_window, width, height);
		return true;
	}
	
	boolean GLFWWindow::SetPosition(i32 x, i32 y)
	{
		glfwSetWindowPos(m_window, x, y);
		return true;
	}
	
	boolean GLFWWindow::GetTitle(StringA &title) const
	{
		title = glfwGetWindowTitle(m_window);
		return true;
	}
	
	boolean GLFWWindow::GetTitle(StringW &title) const
	{
		title = Conv::AToW(glfwGetWindowTitle(m_window));
		return true;
	}
	
	boolean GLFWWindow::GetSize(i32 &width, i32 &height) const
	{
		glfwGetWindowSize(m_window, &width, &height);
		return true;
	}
	
	boolean GLFWWindow::GetPosition(i32 &x, i32 &y) const
	{
		glfwGetWindowPos(m_window, &x, &y);
		return true;
	}
	
	boolean GLFWWindow::PrivateInitGLFW()
	{
		auto result = glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		return result == GLFW_TRUE;
	}
	
	boolean GLFWWindow::Notify(StringViewA title)
	{
		return false;
	}
	
	boolean GLFWWindow::Notify(StringViewW title)
	{
		return false;
	}
} // Anasul