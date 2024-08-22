//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/String.hpp>
#include <Anasul/Logger.hpp>
#include "Window.hpp"

namespace Anasul
{
	/// 平台类
	class ANASUL_API Platform
	{
	public:
		
		/// 获取平台名称
		static void GetPlatformName(StringA &platformName);
		
		/// 获取平台名称
		static void GetPlatformName(StringW &platformName);
		
		/// 是否为黑暗模式
		static boolean IsDarkMode();
		
		/// 是否为白天模式
		static boolean IsLightMode();
		
		/// 是否为管理员
		static boolean IsUserAnAdmin();
		
		/// 获取命令行参数
		static void GetCommandLine(StringA &commandLine);
		
		/// 获取命令行参数
		static void GetCommandLine(StringW &commandLine);
		
		/// 桌面窗口
		static Window *DesktopWindow(Logger &logger);
		
		/// 查找窗口
		static Window *FindWindow(Logger &logger, StringViewA title);
		
		/// 查找窗口
		static Window *FindWindow(Logger &logger, StringViewW title);
		
		/// 仅在 Windows 平台可用
		class ANASUL_API OnlyInWindows
		{
		public:
			
			enum Key : u32
			{
				KetClassesRoot = 0x80000000,
				KeyCurrentUser = 0x80000001,
				KeyLocalMachine = 0x80000002,
				KeyUsers = 0x80000003,
				KeyCurrentConfig = 0x80000005,
			};
			
			/// 读取注册表值
			static boolean ReadFromRegedit(Key hKey, StringViewW subKey, StringViewW subKeyValue, u32 &value);
			
			/// 读取注册表值
			static boolean ReadFromRegedit(Key hKey, StringViewW subKey, StringViewW subKeyValue, StringW &value);
			
			/// 写入注册表值
			static boolean WriteToRegedit(Key hKey, StringViewW subKey, StringViewW subKeyValue, StringViewW value);
			
			/// 删除注册表键
			static boolean DeleteKeyInRegedit(Key hKey, StringViewW subKey);
			
			/// 删除注册表键值
			static boolean DeleteKeyValueInRegedit(Key hKey, StringViewW subKey, StringViewW subKeyValue);
			
			/// 设置开机启动项
			static boolean SetBootStartUp(StringViewW key, StringViewW command);
			
			/// 获取开机启动项
			static boolean GetBootStartUp(StringViewW key, StringW &command);
			
			/// 删除开机启动项
			static boolean DeleteBootStartUp(StringViewW key);
			
			/// 查找窗口类的窗口
			static Window *FindWindowFromClass(Logger &logger, StringViewA name);
			
			/// 查找窗口的窗口
			static Window *FindWindowFromClass(Logger &logger, StringViewW name);
			
			/// 设置窗口句柄
			static void *GetHWnd(const Window *window);
			
			/// 设置父窗口
			static void SetParent(Window *child, Window *parent);
			
			/// 设置父窗口为桌面
			static void SetParentToDesktop(Window *child);
			
			/// 隐藏窗口
			static void EnumWindowHide();
			
			/// 发送消息
			static void SendMessage(Window *window, u32 message, u32 wParam, u32 lParam);
			
			
		};
		
	};
	
} // Anasul
