//
// Created by admin on 2024/8/18.
//

#pragma once

#include "Config.hpp"

namespace Anasul
{
	
	/// 状态
	template<class ResultT, class... Types>
	class ANASUL_API State
	{
	public:
		
		template<class StateT>
		friend
		class StateMachine;
	
	public:
		
		using ResultType = ResultT;
	
	public:
		
		enum StateState
		{
			Started,
			Inited,
			Quited
		};
	
	public:
		
		State() : m_state(Started) {}
		
		virtual ~State() = default;
	
	public:
		
		[[nodiscard]] StateState GetState() const { return m_state; }
	
	protected:
		
		virtual void OnInit() = 0;
		
		virtual ResultT OnTick(Types... args) = 0;
		
		virtual void OnQuit() = 0;
	
	private:
		
		StateState m_state;
		
	};
	
} // Anasul
