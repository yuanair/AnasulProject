//
// Created by admin on 2024/8/22.
//

#include "DirectX2DRenderer.hpp"

namespace Anasul
{
	void DirectX2DRenderer::Init()
	{
		FResult{
			::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, m_factory.ReleaseAndGetAddressOf())
		}.ThrowIfFailed("Failed to create Direct2D factory");
		
		
	}
} // Anasul