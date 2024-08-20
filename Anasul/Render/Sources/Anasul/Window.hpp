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
		
		virtual ~Window() = default;
	
	public:
		
		virtual void Create(StringViewA title, i32 width, i32 height) = 0;
		
		virtual void Update() = 0;
		
		virtual void Close() = 0;
		
		[[nodiscard]] virtual boolean IsOpen() const = 0;
		
		virtual void SetTitle(StringViewA title) = 0;
		
		virtual void SetSize(i32 width, i32 height) = 0;
		
		virtual void SetPosition(i32 x, i32 y) = 0;
		
		virtual void GetTitle(StringViewA &title) = 0;
		
		virtual void GetSize(i32 &width, i32 &height) = 0;
		
		virtual void GetPosition(i32 &x, i32 &y) = 0;
		
	};
	
} // Anasul
