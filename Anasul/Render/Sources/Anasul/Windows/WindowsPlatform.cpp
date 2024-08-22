//
// Created by admin on 2024/8/22.
//

#include "WindowsPlatform.hpp"

#include <Anasul/Windows/Windows.hpp>

namespace Anasul
{
	Platform &WindowsPlatform::Get()
	{
		static WindowsPlatform platform;
		return platform;
	}
	
	StringA WindowsPlatform::GetPlatformNameA() const
	{
		return "Windows";
	}
	
	StringW WindowsPlatform::GetPlatformNameW() const
	{
		return L"Windows";
	}
	
	i32 WindowsPlatform::DarkMode() const
	{
		HKEY hKey;
		const TCHAR *subKey = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize");
		const TCHAR *valueName = _T("AppsUseLightTheme");
		DWORD value = -1;
		DWORD valueSize = sizeof(DWORD);
		if (::RegOpenKeyEx(HKEY_CURRENT_USER, subKey, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
		{
			HRESULT hr = ::RegGetValue(hKey, nullptr, valueName, RRF_RT_REG_DWORD, nullptr, &value, &valueSize);
			if (hr != S_OK)
			{
				value = -1;    // 不要假定该键必须存在，如果找不到将返回默认值
			}
			RegCloseKey(hKey);
		}
		
		if (value == 0)
		{
			return 1;
		}
		else if (value == 1)
		{
			return 0;
		}
		else
		{
			return -1;
		}
		
	}
} // Anasul