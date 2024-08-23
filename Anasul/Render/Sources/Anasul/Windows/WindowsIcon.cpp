//
// Created by admin on 2024/8/23.
//

#include "WindowsIcon.hpp"
#include <Anasul/Platform.hpp>

namespace Anasul
{
	WindowsIcon::~WindowsIcon()
	{
		if (m_hIcon)
		{
			Platform::OnlyInWindows::DestroyIcon(m_hIcon);
			m_hIcon = nullptr;
		}
	}
	
	boolean WindowsIcon::Reload(const StringViewA &filename)
	{
		m_hIcon = (HICON) Platform::OnlyInWindows::LoadIcon(filename);
		return m_hIcon != nullptr;
	}
	
	boolean WindowsIcon::Reload(const StringViewW &filename)
	{
		m_hIcon = (HICON) Platform::OnlyInWindows::LoadIcon(filename);
		return m_hIcon != nullptr;
	}
} // Anasul