//
// Created by admin on 2024/8/22.
//

#include "DirectX2DWindowRenderTarget.hpp"
#include "Anasul/DirectXWrite/DirectXWriteFont.hpp"
#include "Anasul/Conv.hpp"

namespace Anasul
{
	void DirectX2DWindowRenderTarget::BeginDraw()
	{
		m_pRenderTarget->BeginDraw();
	}
	
	void DirectX2DWindowRenderTarget::Clear(const Color4f &color)
	{
		m_pRenderTarget->Clear(D2D1::ColorF(color.x, color.y, color.z, color.w));
	}
	
	void DirectX2DWindowRenderTarget::EndDraw()
	{
		FResult{m_pRenderTarget->EndDraw()}.ThrowIfFailed("EndDraw Failed");
	}
	
	void DirectX2DWindowRenderTarget::DrawText(const Font *font, const StringA &text,
	                                           const Rect4f &rect, const Color4f &color)
	{
		return DrawText(font, Conv::AToW(text), rect, color);
	}
	
	void DirectX2DWindowRenderTarget::DrawText(const Font *font, const StringW &text,
	                                           const Rect4f &rect, const Color4f &color)
	{
		auto *pFont = dynamic_cast<const DirectXWriteFont *>(font);
		Microsoft::WRL::ComPtr <ID2D1SolidColorBrush> pBrush;
		FResult{
			m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color.x, color.y, color.z, color.w), &pBrush)
		}.ThrowIfFailed("CreateSolidColorBrush Failed");
		m_pRenderTarget->DrawTextW(
			text.c_str(), text.length(), pFont->m_pTextFormat.Get(),
			D2D1::RectF(rect.x, rect.y, rect.z, rect.w), pBrush.Get());
	}
} // Anasul