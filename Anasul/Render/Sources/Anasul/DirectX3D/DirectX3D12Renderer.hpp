//
// Created by admin on 2024/8/20.
//

#pragma once

#include "../Renderer.hpp"

#include "DirectX3D12.hpp"

namespace Anasul
{
	
	/// DirectX 3D 12 渲染器
	class ANASUL_API DirectX3D12Renderer : public Renderer
	{
	public:
		
		DirectX3D12Renderer();
		
		~DirectX3D12Renderer() override;
	
	public:
		
		WindowRenderTarget *CreateWindowRenderTarget(const Window &window) override;
	
	private:
		
		Microsoft::WRL::ComPtr<IDXGIFactory4> m_factory;
		Microsoft::WRL::ComPtr<IDXGIAdapter1> m_adapter;
		Microsoft::WRL::ComPtr<IDXGIDevice> m_dxgiDevice;
		Microsoft::WRL::ComPtr<ID3D12Debug> m_debugController;
		Microsoft::WRL::ComPtr<ID3D12Device> m_device;
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_commandQueue;
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_commandAllocator;
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_commandList;
		
	};
	
} // Anasul
