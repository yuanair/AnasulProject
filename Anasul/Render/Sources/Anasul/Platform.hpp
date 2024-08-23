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
		
		/// 致命错误退出程序
		static void FatalExit(Logger &logger, StringViewA message, StringViewA caption,
		                      std::source_location sourceLocation = std::source_location::current());
		
		/// 致命错误退出程序
		static void FatalExit(Logger &logger, StringViewW message, StringViewW caption,
		                      std::source_location sourceLocation = std::source_location::current());
		
		/// 致命错误退出程序
		static void FatalExit(Logger &logger, Window *window, StringViewA message, StringViewA caption,
		                      std::source_location sourceLocation = std::source_location::current());
		
		/// 致命错误退出程序
		static void FatalExit(Logger &logger, Window *window, StringViewW message, StringViewW caption,
		                      std::source_location sourceLocation = std::source_location::current());
		
		/// 致命错误退出程序
		static void FatalExit(Logger &logger, Window *window, StringViewA message,
		                      std::source_location sourceLocation = std::source_location::current());
		
		/// 致命错误退出程序
		static void FatalExit(Logger &logger, Window *window, StringViewW message,
		                      std::source_location sourceLocation = std::source_location::current());
		
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
			
			enum MessageBoxType : u32
			{
				MessageBoxTypeOk = 0x00000000,
				MessageBoxTypeOkCancel = 0x00000001,
				MessageBoxTypeAbortRetryIgnore = 0x00000002,
				MessageBoxTypeYesNoCancel = 0x00000003,
				MessageBoxTypeYesNo = 0x00000004,
				MessageBoxTypeRetryCancel = 0x00000005,
				MessageBoxTypeCancelTryAgainContinue = 0x00000006,
				MessageBoxTypeIconHand = 0x00000010,
				MessageBoxTypeIconQuestion = 0x00000020,
				MessageBoxTypeIconExclamation = 0x00000030,
				MessageBoxTypeIconAsterisk = 0x00000040,
				MessageBoxTypeUserIcon = 0x00000080,
				MessageBoxTypeIconWarning = 0x00000030,
				MessageBoxTypeIconError = 0x00000010,
				MessageBoxTypeIconInformation = 0x00000040,
			};
			
			/// 显示消息框
			static void MessageBox(StringViewA text, StringViewA caption);
			
			/// 显示消息框
			static void MessageBox(StringViewW text, StringViewW caption);
			
			/// 显示消息框
			static i32 MessageBox(Window *window, StringViewA text, StringViewA caption, MessageBoxType type);
			
			/// 显示消息框
			static i32 MessageBox(Window *window, StringViewW text, StringViewW caption, MessageBoxType type);
			
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
			
			/// 加载图标
			static void *LoadIcon(StringViewA name);
			
			/// 加载图标
			static void *LoadIcon(StringViewW name);
			
			/// 销毁图标
			static boolean DestroyIcon(void *icon);
			
			/// 加载光标
			static void *LoadCursor(StringViewA name);
			
			/// 加载光标
			static void *LoadCursor(StringViewW name);
			
			/// 销毁光标
			static boolean DestroyCursor(void *cursor);
			
			/// 获取窗口句柄
			static void *GetHWnd(const Window *window);
			
			/// 获取图标句柄
			static void *GetHIcon(const Icon *icon);
			
			/// 设置父窗口
			static void SetParent(Window *child, Window *parent);
			
			/// Aero效果是否可用（Windows Vista/Win7 可用，Win8/Win10 保持开启）
			static boolean IsAeroEnabled();
			
			/// 设置渲染到桌面
			static void RenderToDesktop(Window *child);
			
			/// 隐藏窗口WorkerW
			static void EnumWindowHideWorkerW();
			
			/// 发送消息
			static void SendMessage(Window *window, u32 message, u32 wParam, u32 lParam);
			
			
		};
		
	};
	
} // Anasul
