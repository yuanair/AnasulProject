//
// Created by admin on 2024/8/20.
//

#include "GLFWWindow.hpp"

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
	
	void GLFWWindow::Create(StringViewA title, i32 width, i32 height)
	{
		if (!glfwInit()) return;
		m_window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
		
		glfwMakeContextCurrent(m_window);
	}
	
	void GLFWWindow::Update()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
	
	void GLFWWindow::Close()
	{
		glfwDestroyWindow(m_window);
	}
	
	boolean GLFWWindow::IsOpen() const
	{
		return m_window != nullptr;
	}
	
	void GLFWWindow::SetTitle(StringViewA title)
	{
		glfwSetWindowTitle(m_window, title.data());
	}
	
	void GLFWWindow::SetSize(i32 width, i32 height)
	{
		glfwSetWindowSize(m_window, width, height);
	}
	
	void GLFWWindow::SetPosition(i32 x, i32 y)
	{
		glfwSetWindowPos(m_window, x, y);
	}
	
	void GLFWWindow::GetTitle(StringViewA &title)
	{
		title = glfwGetWindowTitle(m_window);
	}
	
	void GLFWWindow::GetSize(i32 &width, i32 &height)
	{
		glfwGetWindowSize(m_window, &width, &height);
	}
	
	void GLFWWindow::GetPosition(i32 &x, i32 &y)
	{
		glfwGetWindowPos(m_window, &x, &y);
	}
	
	boolean GLFWWindow::PrivateInitGLFW()
	{
		auto result = glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		return result == GLFW_TRUE;
	}
} // Anasul