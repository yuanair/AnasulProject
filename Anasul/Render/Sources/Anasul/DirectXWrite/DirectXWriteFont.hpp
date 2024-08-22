//
// Created by admin on 2024/8/23.
//

#pragma once

#include <Anasul/Config.hpp>
#include "../Font.hpp"
#include "DirectXWrite.hpp"

namespace Anasul
{
	
	class ANASUL_API DirectXWriteFont : public Font
	{
	public:
	
	
	public:
		
		Microsoft::WRL::ComPtr<IDWriteTextFormat> m_pTextFormat;
		
	};
	
} // Anasul
