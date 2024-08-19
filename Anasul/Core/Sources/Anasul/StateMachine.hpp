//
// Created by admin on 2024/8/18.
//

#pragma once

#include "Config.hpp"
#include "State.hpp"
#include "Exception.hpp"

#include <memory>
#include <cassert>

namespace Anasul
{
	
	/// 状态机异常
	class ANASUL_API StateMachineException : Exception
	{
	public:
		
		using Exception::Exception;
		
	};
	
	/// 状态机
	template<class StateT>
	class ANASUL_API StateMachine
	{
	public:
		
		StateMachine() : m_state(), m_nextState(), m_needNext(false) {}
	
	public:
		
		/// 设置状态（不要在State的函数内调用）
		template<class T, class... Types>
		void SetState(Types &&... args)
		{
			m_nextState = std::make_unique<T>(std::forward<Types>(args)...);
			m_needNext = true;
		}
		
		/// 下一个状态
		void NextState()
		{
			if (m_needNext)
			{
				Quit();
				m_state = std::move(m_nextState);
				m_needNext = false;
			}
		}
		
		/// 每帧调用（不要在State的函数内调用）
		template<class ...Types>
		auto Tick(Types &&... args)
		{
			NextState();
			assert(m_state);
			if (m_state->m_state == StateT::Quited) throw StateMachineException(TEXT("m_state was [State::Quited]!"));
			if (m_state->m_state == StateT::Started) m_state->OnInit();
			m_state->m_state = StateT::Inited;
			return m_state->OnTick(std::forward<Types>(args)...);
		}
		
		/// 退出状态（不要在State的函数内调用）
		void Quit()
		{
			if (!m_state || m_state->m_state == StateT::Quited) return;
			m_state->OnQuit();
			m_state->m_state = StateT::Quited;
		}
	
	public:
		
		/// 获取当前状态
		[[nodiscard]] const std::unique_ptr<StateT> &GetState() const { return m_state; }
		
		/// 获取下一个状态
		[[nodiscard]] const std::unique_ptr<StateT> &GetNextState() const { return m_nextState; }
	
	private:
		
		std::unique_ptr<StateT> m_state;
		
		std::unique_ptr<StateT> m_nextState;
		
		boolean m_needNext;
		
	};
	
} // Anasul
