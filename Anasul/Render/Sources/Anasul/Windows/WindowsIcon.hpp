//
// Created by admin on 2024/8/23.
//

#pragma once

#include "../Icon.hpp"
#include <Anasul/String.hpp>
#include <Anasul/Windows/Windows.hpp>

namespace Anasul
{
	
	class ANASUL_API WindowsIcon : public Icon
	{
	public:
		
		~WindowsIcon() override;
	
	public:
		
		boolean Reload(const StringViewA &filename) override;
		
		boolean Reload(const StringViewW &filename) override;
	
	public:
		
		[[nodiscard]] HICON GetHandle() const { return m_hIcon; }
	
	private:
		
		HICON m_hIcon;
		
	};
	
} // Anasul
