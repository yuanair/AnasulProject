//
// Created by admin on 2024/8/22.
//

#pragma once

#include "DirectX2DRenderer.hpp"

#include "../WindowRenderTarget.hpp"


namespace Anasul
{
	
	class ANASUL_API DirectX2DWindowRenderTarget : public WindowRenderTarget
	{
	public:
		
		void BeginDraw() override;
		
		void Clear(const Color4f &color) override;
		
		void DrawText(const Font *font, const StringA &text, const Rect4f &rect,
		              const Color4f &color) override;
		
		void DrawText(const Font *font, const StringW &text, const Rect4f &rect,
		              const Color4f &color) override;
		
		void EndDraw() override;
	
	public:
		
		Microsoft::WRL::ComPtr <ID2D1HwndRenderTarget> m_pRenderTarget;
		
	};
	
} // Anasul
