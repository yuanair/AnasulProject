//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>

#include <Anasul/String.hpp>
#include "Anasul/Event.hpp"

namespace Anasul
{
	
	class Icon;
	
	/// 键盘按键
	enum Key : i32
	{
		KeyBackspace = 0x08,
		KeyTab = 0x09,
		KeyEnter = 0x0D,
		KeyShift = 0x10,
		KeyControl = 0x11,
		KeyAlt = 0x12,
		KeyPause = 0x13,
		KeyCapsLock = 0x14,
		KeyEscape = 0x1B,
		KeySpace = 0x20,
		KeyPageUp = 0x21,
		KeyPageDown = 0x22,
		KeyEnd = 0x23,
		KeyHome = 0x24,
		KeyLeft = 0x25,
		KeyUp = 0x26,
		KeyRight = 0x27,
		KeyDown = 0x28,
		KeyPrintScreen = 0x2C,
		KeyInsert = 0x2D,
		KeyDelete = 0x2E,
		Key0 = 0x30,
		Key1 = 0x31,
		Key2 = 0x32,
		Key3 = 0x33,
		Key4 = 0x34,
		Key5 = 0x35,
		Key6 = 0x36,
		Key7 = 0x37,
		Key8 = 0x38,
		Key9 = 0x39,
		KeyA = 0x41,
		KeyB = 0x42,
		KeyC = 0x43,
		KeyD = 0x44,
		KeyE = 0x45,
		KeyF = 0x46,
		KeyG = 0x47,
		KeyH = 0x48,
		KeyI = 0x49,
		KeyJ = 0x4A,
		KeyK = 0x4B,
		KeyL = 0x4C,
		KeyM = 0x4D,
		KeyN = 0x4E,
		KeyO = 0x4F,
		KeyP = 0x50,
		KeyQ = 0x51,
		KeyR = 0x52,
		KeyS = 0x53,
		KeyT = 0x54,
		KeyU = 0x55,
		KeyV = 0x56,
		KeyW = 0x57,
		KeyX = 0x58,
		KeyY = 0x59,
		KeyZ = 0x5A,
		KeyLeftWindows = 0x5B,
		KeyRightWindows = 0x5C,
		KeyApplications = 0x5D,
		KeySleep = 0x5F,
		KeyNumpad0 = 0x60,
		KeyNumpad1 = 0x61,
		KeyNumpad2 = 0x62,
		KeyNumpad3 = 0x63,
		KeyNumpad4 = 0x64,
		KeyNumpad5 = 0x65,
		KeyNumpad6 = 0x66,
		KeyNumpad7 = 0x67,
		KeyNumpad8 = 0x68,
		KeyNumpad9 = 0x69,
		KeyMultiply = 0x6A,
		KeyAdd = 0x6B,
		KeySeparator = 0x6C,
		KeySubtract = 0x6D,
		KeyDecimal = 0x6E,
		KeyDivide = 0x6F,
		KeyF1 = 0x70,
		KeyF2 = 0x71,
		KeyF3 = 0x72,
		KeyF4 = 0x73,
		KeyF5 = 0x74,
		KeyF6 = 0x75,
		KeyF7 = 0x76,
		KeyF8 = 0x77,
		KeyF9 = 0x78,
		KeyF10 = 0x79,
		KeyF11 = 0x7A,
		KeyF12 = 0x7B,
		KeyF13 = 0x7C,
		KeyF14 = 0x7D,
		KeyF15 = 0x7E,
		KeyF16 = 0x7F,
		KeyF17 = 0x80,
		KeyF18 = 0x81,
		KeyF19 = 0x82,
		KeyF20 = 0x83,
		KeyF21 = 0x84,
		KeyF22 = 0x85,
		KeyF23 = 0x86,
		KeyF24 = 0x87,
		KeyNumLock = 0x90,
		KeyScrollLock = 0x91,
		KeyLeftShift = 0xA0,
		KeyRightShift = 0xA1,
		KeyLeftControl = 0xA2,
		KeyRightControl = 0xA3,
		KeyLeftAlt = 0xA4,
		KeyRightAlt = 0xA5,
		KeyBrowserBack = 0xA6,
		KeyBrowserForward = 0xA7,
		KeyBrowserRefresh = 0xA8,
		KeyBrowserStop = 0xA9,
		KeyBrowserSearch = 0xAA,
		KeyBrowserFavorites = 0xAB,
		KeyBrowserHome = 0xAC,
		KeyVolumeMute = 0xAD,
		KeyVolumeDown = 0xAE,
		KeyVolumeUp = 0xAF,
		KeyMediaNextTrack = 0xB0,
		KeyMediaPreviousTrack = 0xB1,
		KeyMediaStop = 0xB2,
		KeyMediaPlayPause = 0xB3,
		KeyLaunchMail = 0xB4,
		KeyLaunchMediaSelect = 0xB5,
		KeyLaunchApp1 = 0xB6,
		KeyLaunchApp2 = 0xB7,
		KeyOem1 = 0xBA,
		KeyOemPlus = 0xBB,
		KeyOemComma = 0xBC,
		KeyOemMinus = 0xBD,
		KeyOemPeriod = 0xBE,
		KeyOem2 = 0xBF,
		KeyOem3 = 0xC0,
		KeyOem4 = 0xDB,
		KeyOem5 = 0xDC,
		KeyOem6 = 0xDD,
		KeyOem7 = 0xDE,
		KeyOem8 = 0xDF,
		KeyOem102 = 0xE2,
		KeyProcessKey = 0xE5,
		KeyPacket = 0xE7,
		KeyAttn = 0xF6,
		KeyCrSel = 0xF7,
		KeyExSel = 0xF8,
		KeyErEOF = 0xF9,
		KeyPlay = 0xFA,
		KeyZoom = 0xFB,
		KeyNoname = 0xFC,
		KeyPA1 = 0xFD,
		KeyOemClear = 0xFE,
	};
	
	/// 鼠标按键
	enum MouseButton : i32
	{
		MouseButtonLeft = 0x01,
		MouseButtonRight = 0x02,
		MouseButtonMiddle = 0x04,
		MouseButtonX1 = 0x05,
		MouseButtonX2 = 0x06,
	};
	
	template<class ElemT>
	struct ANASUL_API WindowCreateArgs
	{
	public:
		
		using StringViewT = BasicStringView<ElemT>;
	
	public:
		
		StringViewT m_title;
		i32 m_x = 0;
		i32 m_y = 0;
		i32 m_width = 400;
		i32 m_height = 300;
		Icon *m_icon = nullptr;
		Icon *m_iconSm = nullptr;
		
		class Window *m_parent = nullptr;
		
		boolean m_isFrameless = false;
		
	};
	
	/// 窗口
	class ANASUL_API Window
	{
	public:
		
		Window() = default;
		
		virtual ~Window() = default;
	
	public:
		
		virtual boolean Create(const WindowCreateArgs<c8> &args) = 0;
		
		virtual boolean Create(const WindowCreateArgs<cwide> &args) = 0;
		
		virtual boolean Update() = 0;
		
		virtual boolean Show() = 0;
		
		virtual boolean Hide() = 0;
		
		virtual boolean Notify(StringViewA tip, Icon *icon) = 0;
		
		virtual boolean Notify(StringViewW tip, Icon *icon) = 0;
		
		virtual boolean Close() = 0;
	
	public:
		
		virtual boolean SetTitle(StringViewA title) = 0;
		
		virtual boolean SetTitle(StringViewW title) = 0;
		
		virtual boolean SetSize(i32 width, i32 height) = 0;
		
		virtual boolean SetSize(u32 width, u32 height) = 0;
		
		virtual boolean SetPosition(i32 x, i32 y) = 0;
		
		virtual boolean SetInputPosition(i32 x, i32 y) = 0;
		
		virtual boolean GetTitle(StringA &title) const = 0;
		
		virtual boolean GetTitle(StringW &title) const = 0;
		
		virtual boolean GetSize(i32 &width, i32 &height) const = 0;
		
		virtual boolean GetSize(u32 &width, u32 &height) const = 0;
		
		virtual boolean GetPosition(i32 &x, i32 &y) const = 0;
		
		virtual boolean GetInputPosition(i32 &x, i32 &y) const = 0;
		
		[[nodiscard]] virtual boolean IsOpen() const = 0;
		
		[[nodiscard]] virtual boolean GetKeyDown(Key key) const = 0;
		
		[[nodiscard]] virtual boolean GetKeyUp(Key key) const = 0;
		
		[[nodiscard]] virtual boolean GetKeyPress(Key key) const = 0;
		
		[[nodiscard]] virtual boolean GetMouseButtonDown(MouseButton button) const = 0;
		
		[[nodiscard]] virtual boolean GetMouseButtonUp(MouseButton button) const = 0;
		
		[[nodiscard]] virtual boolean GetMouseButtonPress(MouseButton button) const = 0;
		
		virtual void GetMousePosition(i32 &x, i32 &y) const = 0;
	
	public:
		
		Event<void()> m_onInactive;
		Event<void()> m_onActive;
		Event<void()> m_onClickActive;
		Event<boolean()> m_onClose;
		Event<boolean()> m_onDestroy;
		Event<boolean()> m_onQueryEndSession;
		Event<boolean()> m_onEndSession;
		Event<void(i32, i32)> m_onResize;
		Event<void(i32, i32)> m_onMove;
		Event<void(Key)> m_onKeyDown;
		Event<void(Key)> m_onKeyUp;
		Event<void(Key)> m_onKeyPress;
		Event<void(i32, i32, MouseButton)> m_onMouseDown;
		Event<void(i32, i32, MouseButton)> m_onMouseUp;
		Event<void(i32, i32, MouseButton)> m_onMousePress;
		
	};
	
} // Anasul
