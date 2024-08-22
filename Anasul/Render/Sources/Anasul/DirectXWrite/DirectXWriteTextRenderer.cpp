//
// Created by admin on 2024/8/22.
//

#include "DirectXWriteTextRenderer.hpp"
#include "DirectXWriteFont.hpp"
#include "Anasul/Conv.hpp"

namespace Anasul
{
	DirectXWriteTextRenderer::DirectXWriteTextRenderer()
	{
		FResult{
			::DWriteCreateFactory(
				DWRITE_FACTORY_TYPE_SHARED, __uuidof(m_dWriteFactory),
				reinterpret_cast<IUnknown **>(m_dWriteFactory.ReleaseAndGetAddressOf()))
		}.ThrowIfFailed("Failed to create DirectXWrite factory");
	}
	
	Font *DirectXWriteTextRenderer::CreateFont(const StringA &fontName, float size)
	{
		auto font = new DirectXWriteFont();
		FResult{
			m_dWriteFactory->CreateTextFormat(
				Conv::AToW(fontName).c_str(), nullptr, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL, size, L"en-us",
				font->m_pTextFormat.ReleaseAndGetAddressOf())
		}.ThrowIfFailed("Failed to create DirectXWrite text format");
		return font;
	}
	
	Font *DirectXWriteTextRenderer::CreateFont(const StringW &fontName, float size)
	{
		auto font = new DirectXWriteFont();
		FResult{
			m_dWriteFactory->CreateTextFormat(
				fontName.c_str(), nullptr, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL,
				DWRITE_FONT_STRETCH_NORMAL, size, L"en-us",
				font->m_pTextFormat.ReleaseAndGetAddressOf())
		}.ThrowIfFailed("Failed to create DirectXWrite text format");
		return font;
	}
	
} // Anasul