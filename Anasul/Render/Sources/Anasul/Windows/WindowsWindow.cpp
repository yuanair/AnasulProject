//
// Created by admin on 2024/8/21.
//



#include "WindowsWindow.hpp"
#include <Anasul/Logger.hpp>
#include <Anasul/String.hpp>
#include <Anasul/Windows/Windows.hpp>
#include "../Platform.hpp"

#include <format>
#include <windowsx.h>

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
	
	LPSTR WindowsWindow::RegisterDefaultWindowClassA(Icon *icon, Icon *iconSm)
	{
		static u64 count = 0;
		auto atom = (LPSTR) MAKEINTATOM(RegisterWindowClass(
			std::format("AnasulWindowClassA-{}", count++), WndProcA,
			(HICON) Platform::OnlyInWindows::GetHIcon(icon),
			(HICON) Platform::OnlyInWindows::GetHIcon(iconSm),
			::LoadCursorA(nullptr, (LPCSTR) IDC_ARROW)));
		return atom;
	}
	
	LPWSTR WindowsWindow::RegisterDefaultWindowClassW(Icon *icon, Icon *iconSm)
	{
		static u64 count = 0;
		auto atom = (LPWSTR) MAKEINTATOM(
			RegisterWindowClass(
				std::format(L"AnasulWindowClassW-{}", count++), WndProcW,
				(HICON) Platform::OnlyInWindows::GetHIcon(icon),
				(HICON) Platform::OnlyInWindows::GetHIcon(iconSm),
				::LoadCursorW(nullptr, (LPCWSTR) IDC_ARROW)));
		return atom;
	}
	
	ATOM
	WindowsWindow::RegisterWindowClass(StringViewA className, WNDPROC wndProc, HICON icon, HICON iconSm, HCURSOR cursor)
	{
		WNDCLASSEXA wc{
			.cbSize = sizeof(wc),
			.style = CS_HREDRAW | CS_VREDRAW,
			.lpfnWndProc = wndProc,
			.cbClsExtra = 0,
			.cbWndExtra = sizeof(WindowsWindow *),
			.hInstance = ::GetModuleHandleA(nullptr),
			.hIcon = icon,
			.hCursor = cursor,
			.hbrBackground = nullptr,
			.lpszMenuName = nullptr,
			.lpszClassName = className.data(),
			.hIconSm = iconSm
		};
		return ::RegisterClassExA(&wc);
	}
	
	ATOM
	WindowsWindow::RegisterWindowClass(StringViewW className, WNDPROC wndProc, HICON icon, HICON iconSm, HCURSOR cursor)
	{
		WNDCLASSEXW wc{
			.cbSize = sizeof(wc),
			.style = CS_HREDRAW | CS_VREDRAW,
			.lpfnWndProc = wndProc,
			.cbClsExtra = 0,
			.cbWndExtra = sizeof(WindowsWindow *),
			.hInstance = ::GetModuleHandleW(nullptr),
			.hIcon = icon,
			.hCursor = cursor,
			.hbrBackground = nullptr,
			.lpszMenuName = nullptr,
			.lpszClassName = className.data(),
			.hIconSm = iconSm
		};
		return ::RegisterClassExW(&wc);
	}
	
	boolean WindowsWindow::Create(const WindowCreateArgs<c8> &args)
	{
		Close();
		m_hWnd = ::CreateWindowExA(
			0,
			RegisterDefaultWindowClassA(args.m_icon, args.m_iconSm), args.m_title.data(), CreateStyle(args),
			args.m_x, args.m_y, args.m_width, args.m_height,
			(HWND) Platform::OnlyInWindows::GetHWnd(args.m_parent), nullptr,
			::GetModuleHandleA(nullptr),
			this
		);
		if (Platform::IsLightMode())
			SetDarkMode(FALSE);
		else
			SetDarkMode(TRUE);
		return IsOpen();
	}
	
	boolean WindowsWindow::Create(const WindowCreateArgs<cwide> &args)
	{
		Close();
		m_hWnd = ::CreateWindowExW(
			0,
			RegisterDefaultWindowClassW(args.m_icon, args.m_iconSm), args.m_title.data(), CreateStyle(args),
			args.m_x, args.m_y, args.m_width, args.m_height,
			(HWND) Platform::OnlyInWindows::GetHWnd(args.m_parent), nullptr,
			::GetModuleHandleW(nullptr),
			this
		);
		if (Platform::IsLightMode())
			SetDarkMode(FALSE);
		else
			SetDarkMode(TRUE);
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
	
	boolean WindowsWindow::Notify(StringViewA title, Icon *icon)
	{
		//声明变量并初始化
		NOTIFYICONDATAA nID = {
			.cbSize = sizeof(nID),
			.hWnd = m_hWnd,
			.uID = 1,
			.uFlags = NIF_MESSAGE | NIF_TIP | NIF_ICON,
			.uCallbackMessage = WM_COMMAND,
			.hIcon = (HICON) Platform::OnlyInWindows::GetHIcon(icon),
			.szTip = {},
			.dwState = 0,
			.dwStateMask = 0,
			.szInfo = {},
			.uVersion = NOTIFYICON_VERSION_4,
			.szInfoTitle = {},
			.dwInfoFlags = 0,
			.guidItem = GUID_NULL,
			.hBalloonIcon = nullptr,
		};
		::lstrcpynA(nID.szTip, title.data(), static_cast<int>(title.size() + 1));
		//通知windows添加一个托盘图标，看参数就知道啦
		return ::Shell_NotifyIconA(NIM_ADD, &nID);
	}
	
	boolean WindowsWindow::Notify(StringViewW title, Icon *icon)
	{
		//声明变量并初始化
		NOTIFYICONDATAW nID = {
			.cbSize = sizeof(nID),
			.hWnd = m_hWnd,
			.uID = 1,
			.uFlags = NIF_MESSAGE | NIF_TIP | NIF_ICON,
			.uCallbackMessage = WM_COMMAND,
			.hIcon = (HICON) Platform::OnlyInWindows::GetHIcon(icon),
			.szTip = {},
			.dwState = 0,
			.dwStateMask = 0,
			.szInfo = {},
			.uVersion = NOTIFYICON_VERSION_4,
			.szInfoTitle = {},
			.dwInfoFlags = 0,
			.guidItem = GUID_NULL,
			.hBalloonIcon = nullptr,
		};
		::lstrcpynW(nID.szTip, title.data(), static_cast<int>(title.size() + 1));
		//通知windows添加一个托盘图标，看参数就知道啦
		return ::Shell_NotifyIconW(NIM_ADD, &nID);
	}
	
	boolean WindowsWindow::Close()
	{
		boolean result = true;
		if (this->m_hWnd)
		{
			if (!::DestroyWindow((HWND) this->m_hWnd))
				result = false;
			// this->m_hWnd = nullptr; // 在WM_DESTROY事件中重置
		}
		if (this->m_classAtom)
		{
			if (!::UnregisterClassW((LPCWSTR) this->m_classAtom, ::GetModuleHandleW(nullptr)))
				result = false;
		}
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
	
	boolean WindowsWindow::SetSize(u32 width, u32 height)
	{
		return ::SetWindowPos(
			m_hWnd, nullptr, 0, 0, static_cast<i32>(width), static_cast<i32>(height), SWP_NOMOVE | SWP_NOZORDER
		);
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
	
	boolean WindowsWindow::GetSize(u32 &width, u32 &height) const
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
			case WM_COMMAND:
				POINT pt;
				::GetCursorPos(&pt);
				switch (lParam)
				{
					case WM_LBUTTONDOWN:
						if (m_onMouseDown) m_onMouseDown(pt.x, pt.y, MouseButtonLeft);
						return 0;
					case WM_RBUTTONDOWN:
						if (m_onMouseDown) m_onMouseDown(pt.x, pt.y, MouseButtonRight);
						return 0;
					case WM_MBUTTONDOWN:
						if (m_onMouseDown) m_onMouseDown(pt.x, pt.y, MouseButtonMiddle);
						return 0;
					case WM_LBUTTONUP:
						if (m_onMouseUp) m_onMouseUp(pt.x, pt.y, MouseButtonLeft);
						return 0;
					case WM_RBUTTONUP:
						if (m_onMouseUp) m_onMouseUp(pt.x, pt.y, MouseButtonRight);
						return 0;
					case WM_MBUTTONUP:
						if (m_onMouseUp) m_onMouseUp(pt.x, pt.y, MouseButtonMiddle);
						return 0;
					default:
						return wndProc(m_hWnd, uMsg, wParam, lParam);
				}
			case WM_LBUTTONDOWN:
				if (m_onMouseDown) m_onMouseDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), MouseButtonLeft);
				return 0;
			case WM_RBUTTONDOWN:
				if (m_onMouseDown) m_onMouseDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), MouseButtonRight);
				return 0;
			case WM_MBUTTONDOWN:
				if (m_onMouseDown) m_onMouseDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), MouseButtonMiddle);
				return 0;
			case WM_LBUTTONUP:
				if (m_onMouseUp) m_onMouseUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), MouseButtonLeft);
				return 0;
			case WM_RBUTTONUP:
				if (m_onMouseUp) m_onMouseUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), MouseButtonRight);
				return 0;
			case WM_MBUTTONUP:
				if (m_onMouseUp) m_onMouseUp(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), MouseButtonMiddle);
				return 0;
			case WM_ACTIVATE:
				switch (LOWORD(wParam))
				{
					case WA_INACTIVE:
						if (m_onInactive) m_onInactive();
						return 0;
					case WA_ACTIVE:
						if (m_onActive) m_onActive();
						return 0;
					case WA_CLICKACTIVE:
						if (m_onClickActive) m_onClickActive();
						return 0;
					default:
						return wndProc(m_hWnd, uMsg, wParam, lParam);
				}
			case WM_SIZE:
				if (m_onResize) m_onResize(LOWORD(lParam), HIWORD(lParam));
				return 0;
			case WM_MOVE:
				if (m_onMove) m_onMove(LOWORD(lParam), HIWORD(lParam));
				return 0;
			case WM_SETTINGCHANGE:
			case WM_THEMECHANGED:
				if (Platform::IsLightMode())
					SetDarkMode(FALSE);
				else
					SetDarkMode(TRUE);
				return 0;
			case WM_MENUCHAR:
				// 禁用 alt-enter.
				return MAKELRESULT(0, MNC_CLOSE);
			case WM_CLOSE:
				if (!m_onClose || m_onClose()) Close();
				return 0;
			case WM_DESTROY:
				if (!m_onDestroy || m_onDestroy()) ::PostQuitMessage(0);
				m_hWnd = nullptr;
				return 0;
			case WM_QUERYENDSESSION:
				return !m_onQueryEndSession || m_onQueryEndSession();
			case WM_ENDSESSION:
				return !m_onEndSession || m_onEndSession();
			default:
				return wndProc(m_hWnd, uMsg, wParam, lParam);
		}
	}
	
	boolean WindowsWindow::SetDarkMode(BOOL darkMode)
	{
		return SUCCEEDED(::DwmSetWindowAttribute(m_hWnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &darkMode, sizeof(darkMode)));
	}
	
	boolean WindowsWindow::GetKeyDown(Key key) const
	{
		return (::GetAsyncKeyState(key) & 0x8000) != 0;
	}
	
	boolean WindowsWindow::GetKeyUp(Key key) const
	{
		return (::GetAsyncKeyState(key) & 0x8000) == 0;
	}
	
	boolean WindowsWindow::GetKeyPress(Key key) const
	{
		return ::GetKeyState(key);
	}
	
	boolean WindowsWindow::GetMouseButtonDown(MouseButton button) const
	{
		return (::GetAsyncKeyState(button) & 0x8000) != 0;
	}
	
	boolean WindowsWindow::GetMouseButtonUp(MouseButton button) const
	{
		return (::GetAsyncKeyState(button) & 0x8000) == 0;
	}
	
	boolean WindowsWindow::GetMouseButtonPress(MouseButton button) const
	{
		return ::GetKeyState(button);
	}
	
	void WindowsWindow::GetMousePosition(i32 &x, i32 &y) const
	{
		::POINT point;
		::GetCursorPos(&point);
		::ScreenToClient(m_hWnd, &point);
		x = point.x;
		y = point.y;
	}
	
}