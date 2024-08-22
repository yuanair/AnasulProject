//
// Created by admin on 2024/8/20.
//

#pragma once

#include <Anasul/Config.hpp>

#include <Anasul/String.hpp>

namespace Anasul
{
	/// 窗口
	class ANASUL_API Window
	{
	public:
		
		Window() = default;
		
		virtual ~Window() = default;
	
	public:
		
		virtual boolean Create(StringViewA title, i32 width, i32 height) = 0;
		
		virtual boolean Create(StringViewW title, i32 width, i32 height) = 0;
		
		virtual boolean Update() = 0;
		
		virtual boolean Show() = 0;
		
		virtual boolean Hide() = 0;
		
		virtual boolean Notify(StringViewA tip) = 0;
		
		virtual boolean Notify(StringViewW tip) = 0;
		
		virtual boolean Close() = 0;
		
		[[nodiscard]] virtual boolean IsOpen() const = 0;
	
	public:
		
		virtual boolean SetTitle(StringViewA title) = 0;
		
		virtual boolean SetTitle(StringViewW title) = 0;
		
		virtual boolean SetSize(i32 width, i32 height) = 0;
		
		virtual boolean SetPosition(i32 x, i32 y) = 0;
		
		virtual boolean SetInputPosition(i32 x, i32 y) = 0;
		
		virtual boolean GetTitle(StringA &title) const = 0;
		
		virtual boolean GetTitle(StringW &title) const = 0;
		
		virtual boolean GetSize(i32 &width, i32 &height) const = 0;
		
		virtual boolean GetPosition(i32 &x, i32 &y) const = 0;
		
		virtual boolean GetInputPosition(i32 &x, i32 &y) const = 0;
		
	};
	
} // Anasul
