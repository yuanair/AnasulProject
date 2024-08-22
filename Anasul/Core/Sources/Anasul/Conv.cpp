//
// Created by admin on 2024/8/21.
//

#include "Conv.hpp"

#include "Windows/Windows.hpp"
#include "Windows/Result.hpp"

namespace Anasul
{
	StringW Conv::AToW(StringViewA c)
	{
		StringW str;
		auto len = ::MultiByteToWideChar(
			CP_ACP, 0, c.data(), static_cast<int>(c.size()), nullptr, 0
		);
		auto m_wchar = new cwide[len + 1];
		::MultiByteToWideChar(CP_ACP, 0, c.data(), static_cast<int>(c.size()), m_wchar, len);
		m_wchar[len] = '\0';
		str = m_wchar;
		delete[] m_wchar;
		return str;
	}
	
	StringA Conv::WToA(StringViewW wp)
	{
		StringA str;
		auto len = ::WideCharToMultiByte(
			CP_ACP, 0, wp.data(), static_cast<int>(wp.size()), nullptr, 0, nullptr, nullptr
		);
		auto m_char = new c8[len + 1];
		::WideCharToMultiByte(
			CP_ACP, 0, wp.data(), static_cast<int>(wp.size()), m_char, len, nullptr, nullptr
		);
		m_char[len] = '\0';
		str = m_char;
		delete[] m_char;
		return str;
	}
} // Anasul