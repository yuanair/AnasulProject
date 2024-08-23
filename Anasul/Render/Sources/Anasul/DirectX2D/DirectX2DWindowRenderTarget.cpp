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
	
	void DirectX2DWindowRenderTarget::DrawCircle(const Point2f &center, float radius, const Color4f &color)
	{
		Microsoft::WRL::ComPtr <ID2D1SolidColorBrush> pBrush;
		FResult{
			m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color.x, color.y, color.z, color.w), &pBrush)
		}.ThrowIfFailed("CreateSolidColorBrush Failed");
		m_pRenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, center.y), radius, radius), pBrush.Get());
	}
	
	void DirectX2DWindowRenderTarget::FillCircle(const Point2f &center, float radius, const Color4f &color)
	{
		Microsoft::WRL::ComPtr <ID2D1SolidColorBrush> pBrush;
		FResult{
			m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color.x, color.y, color.z, color.w), &pBrush)
		}.ThrowIfFailed("CreateSolidColorBrush Failed");
		m_pRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(center.x, center.y), radius, radius), pBrush.Get());
	}
	
	void DirectX2DWindowRenderTarget::DrawRectangle(const Rect4f &rect, const Color4f &color)
	{
		Microsoft::WRL::ComPtr <ID2D1SolidColorBrush> pBrush;
		FResult{
			m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color.x, color.y, color.z, color.w), &pBrush)
		}.ThrowIfFailed("CreateSolidColorBrush Failed");
		m_pRenderTarget->DrawRectangle(D2D1::RectF(rect.x, rect.y, rect.z, rect.w), pBrush.Get());
	}
	
	void DirectX2DWindowRenderTarget::FillRectangle(const Rect4f &rect, const Color4f &color)
	{
		Microsoft::WRL::ComPtr <ID2D1SolidColorBrush> pBrush;
		FResult{
			m_pRenderTarget->CreateSolidColorBrush(D2D1::ColorF(color.x, color.y, color.z, color.w), &pBrush)
		}.ThrowIfFailed("CreateSolidColorBrush Failed");
		m_pRenderTarget->FillRectangle(D2D1::RectF(rect.x, rect.y, rect.z, rect.w), pBrush.Get());
	}
	
	void DirectX2DWindowRenderTarget::Resize(const Size2u &size)
	{
		FResult{m_pRenderTarget->Resize(D2D1::SizeU(size.x, size.y))}.ThrowIfFailed("Resize Failed");
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