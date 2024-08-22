//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>

#include "../TextRenderer.hpp"
#include "DirectXWrite.hpp"


namespace Anasul
{
	
	class ANASUL_API DirectXWriteTextRenderer : public TextRenderer
	{
	public:
		
		DirectXWriteTextRenderer();
	
	public:
		
		Font *CreateFont(const StringA &fontName, float size) override;
		
		Font *CreateFont(const StringW &fontName, float size) override;
	
	private:
		
		Microsoft::WRL::ComPtr<IDWriteFactory> m_dWriteFactory;
		
	};
	
} // Anasul
