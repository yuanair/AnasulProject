//
// Created by admin on 2024/8/22.
//

#include "DWriteRenderer.hpp"

namespace Anasul
{
	void DWriteRenderer::Init()
	{
		FResult{
			::DWriteCreateFactory(
				DWRITE_FACTORY_TYPE_SHARED, __uuidof(m_dWriteFactory),
				reinterpret_cast<IUnknown **>(m_dWriteFactory.ReleaseAndGetAddressOf()))
		}.ThrowIfFailed("Failed to create DWrite factory");
	}
} // Anasul