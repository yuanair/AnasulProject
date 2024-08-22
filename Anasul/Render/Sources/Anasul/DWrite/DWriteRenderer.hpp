//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>

#include "../Renderer.hpp"
#include "DWrite.hpp"

namespace Anasul
{
	
	class ANASUL_API DWriteRenderer : public Renderer
	{
	public:
		
		void Init() override;
	
	private:
		
		Microsoft::WRL::ComPtr <IDWriteFactory> m_dWriteFactory;
		
	};
	
} // Anasul
