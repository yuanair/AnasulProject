//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>

#include "../Renderer.hpp"
#include "DirectX2D.hpp"

namespace Anasul
{
	
	class ANASUL_API DirectX2DRenderer : public Renderer
	{
	public:
		
		void Init() override;
	
	private:
		
		Microsoft::WRL::ComPtr <ID2D1Factory> m_factory;
		
	};
	
} // Anasul
