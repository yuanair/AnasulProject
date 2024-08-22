//
// Created by admin on 2024/8/21.
//



#include "WindowsWindow.hpp"
#include <Anasul/Main.hpp>
#include <Anasul/Logger.hpp>
#include <Anasul/String.hpp>
#include <Anasul/Windows/Windows.hpp>
#include "WindowsPlatform.hpp"

#include <format>

namespace Anasul
{
	
	WindowsWindow::WindowsWindow(Logger &logger)
		: Logable(logger), m_hWnd(nullptr), m_classAtom(), m_inputBoxPos(0, 0)
	{
	
	}
	
	WindowsWindow::~WindowsWindow()
	{
		WindowsWindow::Close();
	}
	
	LPSTR WindowsWindow::GetDefaultWindowClassA()
	{
		static auto atom = (LPSTR) MAKEINTATOM(RegisterWindowClass("DefaultWindowClassA", WndProcA, nullptr, nullptr));
		return atom;
	}
	
	LPWSTR WindowsWindow::GetDefaultWindowClassW()
	{
		static auto atom = (LPWSTR) MAKEINTATOM(
			RegisterWindowClass(TEXT("DefaultWindowClassW"), WndProcW, nullptr, nullptr));
		return atom;
	}
	
	ATOM WindowsWindow::RegisterWindowClass(StringViewA className, WNDPROC wndProc, HICON icon, HCURSOR cursor)
	{
		WNDCLASSEXA wc{};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = wndProc;
		wc.hInstance = ::GetModuleHandleA(nullptr);
		wc.hCursor = ::LoadCursorA(nullptr, MAKEINTRESOURCEA(IDC_ARROW));
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(WindowsWindow *);
		wc.lpszClassName = className.data();
		
		return ::RegisterClassExA(&wc);
	}
	
	ATOM WindowsWindow::RegisterWindowClass(StringViewW className, WNDPROC wndProc, HICON icon, HCURSOR cursor)
	{
		WNDCLASSEXW wc{};
		wc.cbSize = sizeof(wc);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = wndProc;
		wc.hInstance = ::GetModuleHandleW(nullptr);
		wc.hCursor = ::LoadCursorW(nullptr, MAKEINTRESOURCEW(IDC_ARROW));
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = sizeof(WindowsWindow *);
		wc.lpszClassName = className.data();
		
		return ::RegisterClassExW(&wc);
	}
	
	i32 WindowsWindow::IsDarkMode() const
	{
		return WindowsPlatform::Get().DarkMode();
	}
	
	boolean WindowsWindow::Create(StringViewA title, i32 width, i32 height)
	{
		m_hWnd = ::CreateWindowExA(
			0,
			GetDefaultWindowClassA(), title.data(), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, width, height,
			nullptr, nullptr,
			::GetModuleHandleA(nullptr),
			this
		);
		if (IsDarkMode() == 1)
			SetDarkMode(TRUE);
		else if (IsDarkMode() == 0)
			SetDarkMode(FALSE);
		return IsOpen();
	}
	
	boolean WindowsWindow::Create(StringViewW title, i32 width, i32 height)
	{
		m_hWnd = ::CreateWindowExW(
			0,
			GetDefaultWindowClassW(), title.data(), WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, width, height,
			nullptr, nullptr,
			::GetModuleHandleW(nullptr),
			this
		);
		if (IsDarkMode() == 1)
			SetDarkMode(TRUE);
		else if (IsDarkMode() == 0)
			SetDarkMode(FALSE);
		return IsOpen();
	}
	
	boolean WindowsWindow::Update()
	{
		return true;
	}
	
	boolean WindowsWindow::Show()
	{
		return ::ShowWindow(m_hWnd, SW_SHOW);
	}
	
	boolean WindowsWindow::Hide()
	{
		return ::ShowWindow(m_hWnd, SW_HIDE);
	}
	
	boolean WindowsWindow::Notify(StringViewA title)
	{
		//声明变量并初始化
		NOTIFYICONDATAA nID = {
			.cbSize = sizeof(nID),
			.hWnd = m_hWnd,
			.uID = 1,
			.uFlags = NIF_INFO | NIF_ICON | NIF_MESSAGE | NIF_TIP,
			.uCallbackMessage = WM_NOTIFY,
			.hIcon = (HICON) ::LoadImageA(nullptr, "notify.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE),
			.szTip = {},
			.dwState = NIS_HIDDEN,
			.dwStateMask = NIS_HIDDEN,
			.szInfo = "This is a notification",
			.uVersion = NOTIFYICON_VERSION_4,
			.szInfoTitle = "Notification Title",
			.dwInfoFlags = NIIF_INFO,
			.guidItem = GUID_NULL,
			.hBalloonIcon = nullptr,
		};
		::lstrcpynA(nID.szTip, title.data(), static_cast<int>(sizeof(title.size())));
		//通知windows添加一个托盘图标，看参数就知道啦
		return ::Shell_NotifyIconA(NIM_ADD, &nID);
	}
	
	boolean WindowsWindow::Notify(StringViewW title)
	{
		//声明变量并初始化
		NOTIFYICONDATAW nID = {
			.cbSize = sizeof(nID),
			.hWnd = m_hWnd,
			.uID = 1,
			.uFlags = NIF_INFO | NIF_ICON | NIF_MESSAGE | NIF_TIP,
			.uCallbackMessage = WM_NOTIFY,
			.hIcon = (HICON) ::LoadImageW(nullptr, TEXT("notify.ico"), IMAGE_ICON, 0, 0, LR_LOADFROMFILE),
			.szTip = {},
			.dwState = NIS_HIDDEN,
			.dwStateMask = NIS_HIDDEN,
			.szInfo = TEXT("This is a notification"),
			.uVersion = NOTIFYICON_VERSION_4,
			.szInfoTitle = TEXT("Notification Title"),
			.dwInfoFlags = NIIF_INFO,
			.guidItem = GUID_NULL,
			.hBalloonIcon = nullptr,
		};
		::lstrcpynW(nID.szTip, title.data(), static_cast<int>(sizeof(title.size())));
		//通知windows添加一个托盘图标，看参数就知道啦
		return ::Shell_NotifyIconW(NIM_ADD, &nID);
	}
	
	boolean WindowsWindow::Close()
	{
		if (this->m_hWnd == nullptr) return true;
		boolean result = ::DestroyWindow((HWND) this->m_hWnd);
		// this->m_hWnd = nullptr; // 在WM_DESTROY事件中重置
		return result;
	}
	
	boolean WindowsWindow::IsOpen() const
	{
		return ::IsWindow(m_hWnd);
	}
	
	boolean WindowsWindow::SetTitle(StringViewA title)
	{
		return ::SetWindowTextA(m_hWnd, title.data());
	}
	
	boolean WindowsWindow::SetTitle(StringViewW title)
	{
		return ::SetWindowTextW(m_hWnd, title.data());
	}
	
	boolean WindowsWindow::SetSize(i32 width, i32 height)
	{
		return ::SetWindowPos(m_hWnd, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER);
	}
	
	boolean WindowsWindow::SetPosition(i32 x, i32 y)
	{
		return ::SetWindowPos(m_hWnd, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}
	
	boolean WindowsWindow::SetInputPosition(i32 x, i32 y)
	{
		this->m_inputBoxPos.x = x;
		this->m_inputBoxPos.y = y;
		return true;
	}
	
	boolean WindowsWindow::GetTitle(StringA &title) const
	{
		auto len = ::GetWindowTextLengthA(m_hWnd);
		auto buffer = new c8[len + 1];
		boolean result = ::GetWindowTextA(m_hWnd, buffer, len + 1);
		title = buffer;
		delete[] buffer;
		return result;
	}
	
	boolean WindowsWindow::GetTitle(StringW &title) const
	{
		auto len = ::GetWindowTextLengthW(m_hWnd);
		auto buffer = new cwide[len + 1];
		boolean result = ::GetWindowTextW(m_hWnd, buffer, len + 1);
		title = buffer;
		delete[] buffer;
		return result;
	}
	
	boolean WindowsWindow::GetSize(i32 &width, i32 &height) const
	{
		::RECT rect;
		boolean result = ::GetClientRect(m_hWnd, &rect);
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
		return result;
	}
	
	boolean WindowsWindow::GetPosition(i32 &x, i32 &y) const
	{
		::POINT point{0, 0};
		boolean result = ::ClientToScreen(m_hWnd, &point);
		x = point.x;
		y = point.y;
		return result;
	}
	
	boolean WindowsWindow::GetInputPosition(i32 &x, i32 &y) const
	{
		x = this->m_inputBoxPos.x;
		y = this->m_inputBoxPos.y;
		return true;
	}
	
	LRESULT WindowsWindow::WndProcA(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		WindowsWindow *pThis;
		
		if (uMsg == WM_NCCREATE)
		{
			auto *pCreate = reinterpret_cast<CREATESTRUCTA *>(lParam);
			pThis = reinterpret_cast<WindowsWindow *>(pCreate->lpCreateParams);
			::SetWindowLongPtrA((HWND) hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
			pThis->m_hWnd = hWnd;
		}
		else
		{
			pThis = reinterpret_cast<WindowsWindow *>(::GetWindowLongPtrA((HWND) hWnd, GWLP_USERDATA));
		}
		
		if (pThis) return pThis->OnMessageA(uMsg, wParam, lParam);
		
		return ::DefWindowProcA(hWnd, uMsg, wParam, lParam);
	}
	
	LRESULT WindowsWindow::WndProcW(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		WindowsWindow *pThis;
		
		if (uMsg == WM_NCCREATE)
		{
			auto *pCreate = reinterpret_cast<CREATESTRUCTW *>(lParam);
			pThis = reinterpret_cast<WindowsWindow *>(pCreate->lpCreateParams);
			::SetWindowLongPtrW((HWND) hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pThis));
			pThis->m_hWnd = hWnd;
		}
		else
		{
			pThis = reinterpret_cast<WindowsWindow *>(::GetWindowLongPtrW((HWND) hWnd, GWLP_USERDATA));
		}
		
		if (pThis) return pThis->OnMessageW(uMsg, wParam, lParam);
		
		return ::DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}
	
	LRESULT WindowsWindow::OnMessageA(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			case WM_IME_STARTCOMPOSITION:
			{
				HIMC hIMC;
				
				hIMC = ImmGetContext(m_hWnd);
				
				if (hIMC)
				{
					CANDIDATEFORM candidateForm;
					candidateForm.dwIndex = 0;
					candidateForm.dwStyle = CFS_CANDIDATEPOS;
					candidateForm.ptCurrentPos = m_inputBoxPos;
					ImmSetCandidateWindow(hIMC, &candidateForm);
				}
				else GetLogger().Log(LogLevel::Error, "ImmGetContext Failed");
				
				ImmReleaseContext(m_hWnd, hIMC);
				return 0;
			}
			case WM_IME_COMPOSITION:
			{
				HIMC hIMC;
				DWORD dwSize;
				HGLOBAL hstr;
				LPSTR lpstr;
				if (lParam & GCS_RESULTSTR)
				{
					hIMC = ImmGetContext(m_hWnd);
					
					if (!hIMC) GetLogger().Log(LogLevel::Error, "ImmGetContext Failed");
					
					// Read the size of the result string.
					dwSize = ImmGetCompositionStringA(hIMC, GCS_RESULTSTR, nullptr, 0);
					
					// increase buffer size for terminating null CharA,
					//   maybe it is in UNICODE
					dwSize += sizeof(*lpstr);
					
					hstr = GlobalAlloc(GHND, dwSize);
					if (hstr == nullptr)
						GetLogger().Log(
							LogLevel::Error, "GlobalAlloc Failed"
						);
					
					lpstr = (LPSTR) GlobalLock(hstr);
					if (lpstr == nullptr)
						GetLogger().Log(
							LogLevel::Error, "GlobalLock Failed"
						);
					
					// Read the result strings that is generated by IME into lpstr.
					ImmGetCompositionStringA(hIMC, GCS_RESULTSTR, lpstr, dwSize);
					ImmReleaseContext(m_hWnd, hIMC);
					
					// add this string into text buffer of application
					if (lpstr != nullptr) printf("%s\n", lpstr);
					
					GlobalUnlock(hstr);
					GlobalFree(hstr);
					return 0;
				}
				return 0;
			}
			default:
				return OnMessage(uMsg, wParam, lParam, ::DefWindowProcA);
		}
	}
	
	LRESULT WindowsWindow::OnMessageW(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
			case WM_IME_STARTCOMPOSITION:
			{
				HIMC hIMC;
				
				hIMC = ImmGetContext(m_hWnd);
				
				if (hIMC)
				{
					CANDIDATEFORM candidateForm;
					candidateForm.dwIndex = 0;
					candidateForm.dwStyle = CFS_CANDIDATEPOS;
					candidateForm.ptCurrentPos = m_inputBoxPos;
					ImmSetCandidateWindow(hIMC, &candidateForm);
				}
				else GetLogger().Log(LogLevel::Error, TEXT("ImmGetContext Failed"));
				
				ImmReleaseContext(m_hWnd, hIMC);
				return 0;
			}
			case WM_IME_COMPOSITION:
			{
				HIMC hIMC;
				DWORD dwSize;
				HGLOBAL hstr;
				LPWSTR lpstr;
				if (lParam & GCS_RESULTSTR)
				{
					hIMC = ImmGetContext(m_hWnd);
					
					if (!hIMC) GetLogger().Log(LogLevel::Error, TEXT("ImmGetContext Failed"));
					
					// Read the size of the result string.
					dwSize = ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, nullptr, 0);
					
					// increase buffer size for terminating null CharA,
					//   maybe it is in UNICODE
					dwSize += sizeof(*lpstr);
					
					hstr = GlobalAlloc(GHND, dwSize);
					if (hstr == nullptr)
						GetLogger().Log(
							LogLevel::Error, TEXT("GlobalAlloc Failed")
						);
					
					lpstr = (LPWSTR) GlobalLock(hstr);
					if (lpstr == nullptr)
						GetLogger().Log(
							LogLevel::Error, TEXT("GlobalLock Failed")
						);
					
					// Read the result strings that is generated by IME into lpstr.
					ImmGetCompositionStringW(hIMC, GCS_RESULTSTR, lpstr, dwSize);
					ImmReleaseContext(m_hWnd, hIMC);
					
					// add this string into text buffer of application
					if (lpstr != nullptr) wprintf(TEXT("%s\n"), lpstr);
					
					GlobalUnlock(hstr);
					GlobalFree(hstr);
					return 0;
				}
				return 0;
			}
			default:
				return OnMessage(uMsg, wParam, lParam, ::DefWindowProcW);
		}
	}
	
	LRESULT WindowsWindow::OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, WNDPROC wndProc)
	{
		switch (uMsg)
		{
			case WM_SETTINGCHANGE:
			case WM_THEMECHANGED:
				if (IsDarkMode() == 1)
				{
					SetDarkMode(TRUE);
				}
				else if (IsDarkMode() == 0)
				{
					SetDarkMode(FALSE);
				}
				else
				{
					GetLogger().Log(LogLevel::Error, "Unknown Dark Mode");
				}
				return 0;
			case WM_MENUCHAR:
				// 禁用 alt-enter.
				return MAKELRESULT(0, MNC_CLOSE);
			case WM_CLOSE:
				Close();
				return 0;
			case WM_DESTROY:
				::PostQuitMessage(0);
				m_hWnd = nullptr;
				return 0;
			default:
				return wndProc(m_hWnd, uMsg, wParam, lParam);
		}
	}
	
	boolean WindowsWindow::SetDarkMode(BOOL darkMode)
	{
		return SUCCEEDED(::DwmSetWindowAttribute(m_hWnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkMode, sizeof(darkMode)));
	}
	
}