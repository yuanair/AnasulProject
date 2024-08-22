//
// Created by admin on 2024/8/22.
//

#include "../Windows/WindowsWindow.hpp"
#include "../GLFW/GLFWWindow.hpp"
#include "DirectX2DRenderer.hpp"
#include "DirectX2DWindowRenderTarget.hpp"

#include "../Window.hpp"

namespace Anasul
{
	DirectX2DRenderer::DirectX2DRenderer()
	{
		FResult{
			::D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, m_factory.ReleaseAndGetAddressOf())
		}.ThrowIfFailed("Failed to create Direct2D factory");
		
		
	}
	
	WindowRenderTarget *DirectX2DRenderer::CreateWindowRenderTarget(const Window &window)
	{
		if (!m_factory)
		{
			throw NullPointerException(TEXT("DirectX2D factory is not initialized"));
		}
		HWND hwnd = (HWND) Platform::OnlyInWindows::GetHWnd(&window);
		D2D1_RENDER_TARGET_PROPERTIES props{
			.type = D2D1_RENDER_TARGET_TYPE_DEFAULT,
			.pixelFormat = {
				.format = DXGI_FORMAT_B8G8R8A8_UNORM,
				.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED
			},
			.dpiX = 0.0f,
			.dpiY = 0.0f,
			.usage = D2D1_RENDER_TARGET_USAGE_NONE,
			.minLevel = D2D1_FEATURE_LEVEL_DEFAULT
		};
		D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProps{
			.hwnd = hwnd,
			.pixelSize = {},
			.presentOptions = D2D1_PRESENT_OPTIONS_NONE
		};
		window.GetSize(hwndProps.pixelSize.width, hwndProps.pixelSize.height);
		auto *renderTarget = new DirectX2DWindowRenderTarget();
		FResult{
			m_factory->CreateHwndRenderTarget(props, hwndProps, renderTarget->m_pRenderTarget.ReleaseAndGetAddressOf())
		}.ThrowIfFailed("Failed to create Direct2D render target");
		
		return renderTarget;
	}
} // Anasul