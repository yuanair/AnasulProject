//
// Created by admin on 2024/8/17.
//

#pragma once


#include "Lexer.hpp"

#include <Anasul/StateMachine.hpp>
#include <Anasul/Logger.hpp>
#include <Anasul/Type.hpp>

#include <memory>

namespace Anasul
{
	
	
	/// 默认词法分析器
	template<class ElemT>
	class ANASUL_API LexerDefault : public Lexer<ElemT>
	{
	public:
		
		using StateBase = State<Token<ElemT> *, LexerDefault<ElemT> &>;
		using StateMachineBase = StateMachine<StateBase>;
	
	public:
		
		/// 信息
		enum Info
		{
			InfoNone = 0x0000,
		};
		
		/// 警告
		enum Warning
		{
			WarningNone = 0x0000,
		};
		
		/// 错误
		enum Error
		{
			ErrorNone = 0x0000,
			ErrorUnexpectedCharacter = 0x0001
		};
		
		/// 初始模式
		class StateStart : public StateBase
		{
		protected:
			
			void OnInit() override
			{
			
			}
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override
			{
				auto ch = lexer.GetIStream().peek();
				if (IsDigit(ch))
				{
					lexer.GetStateMachine().template SetState<StateInteger>();
					return nullptr;
				}
				else if (IsSpace(ch))
				{
					lexer.GetIStream().get();
					return nullptr;
				}
				else if (IsEOF(ch))
				{
					lexer.GetIStream().get();
					return nullptr;
				}
				else
				{
					lexer.OutErrorUnexpectedChar(ch);
					return nullptr;
				}
			}
			
			void OnQuit() override
			{
			
			}
			
		};
		
		/// 操作符模式
		class StateOperator : public StateBase
		{
		protected:
			
			void OnInit() override;
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override;
			
			void OnQuit() override;
			
		};
		
		/// 整数模式
		/// 例如：0/100/...
		class StateInteger : public StateBase
		{
		protected:
			
			void OnInit() override
			{
			
			}
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override
			{
				auto ch = lexer.GetIStream().peek();
				if (IsDigit(ch))
				{
					m_integer += ch;
					lexer.GetIStream().get();
					return nullptr;
				}
				else if (ch == 'e' || ch == 'E')
				{
					lexer.GetStateMachine().template SetState<StateE>(std::move(m_integer));
					lexer.GetIStream().get();
					return nullptr;
				}
				else if (ch == '.')
				{
					lexer.GetStateMachine().template SetState<StateIntegerDot>(std::move(m_integer));
					lexer.GetIStream().get();
					return nullptr;
				}
				else
				{
					lexer.GetStateMachine().template SetState<StateStart>();
					return new TokenInteger<ElemT>(std::move(m_integer));
				}
			}
			
			void OnQuit() override
			{
			
			}
		
		private:
			
			BasicString<ElemT> m_integer;
			
		};
		
		/// 整数后的小数点模式
		/// 例如：0.5/50.2/...
		class StateIntegerDot : public StateBase
		{
		public:
			
			explicit StateIntegerDot(BasicString<ElemT> m_integer) : m_integer(std::move(m_integer)) {}
		
		protected:
			
			void OnInit() override
			{
			
			}
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override
			{
				auto ch = lexer.GetIStream().peek();
				if (IsDigit(ch))
				{
					m_dec += ch;
					lexer.GetIStream().get();
					return nullptr;
				}
//				else if (ch == 'e' || ch == 'E')
//				{
//					lexer.GetStateMachine().template SetState<StateE>();
//					lexer.GetIStream().get();
//					return new TokenDecimal<ElemT>(std::move(m_integer), std::move(m_dec));
//				}
				else
				{
					lexer.GetStateMachine().template SetState<StateStart>();
					return new TokenDecimal<ElemT>(std::move(m_integer), std::move(m_dec));
				}
			}
			
			void OnQuit() override
			{
			
			}
		
		private:
			
			BasicString<ElemT> m_integer;
			
			BasicString<ElemT> m_dec;
			
		};
		
		/// 小数点模式
		/// 例如：.1/.5f/...
		class StateDot : public StateBase
		{
		protected:
			
			void OnInit() override;
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override;
			
			void OnQuit() override;
			
		};
		
		/// 小数模式
		/// 例如：0.5/50.2/...
		class StateDecimal : public StateBase
		{
		protected:
			
			void OnInit() override;
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override;
			
			void OnQuit() override;
			
		};
		
		/// 科学计数法模式
		/// 例如：0.5e1/1e-5/...
		class StateE : public StateBase
		{
		public:
			
			explicit StateE(BasicString<ElemT> m_integer) : m_integer(std::move(m_integer)) {}
		
		protected:
			
			void OnInit() override
			{
			
			}
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override
			{
				auto ch = lexer.GetIStream().peek();
				if (IsDigit(ch))
				{
					m_eNumber += ch;
					lexer.GetIStream().get();
					return nullptr;
				}
				else
				{
					lexer.GetStateMachine().template SetState<StateStart>();
					return new TokenEInteger<ElemT>(std::move(m_integer), false, std::move(m_eNumber));
				}
			}
			
			void OnQuit() override
			{
			
			}
		
		private:
			
			BasicString<ElemT> m_integer;
			
			BasicString<ElemT> m_eNumber;
			
		};
		
		/// 科学计数法符号模式
		/// 例如：0.5e+1/1e-5/...
		class StateESign : public StateBase
		{
		protected:
			
			void OnInit() override;
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override;
			
			void OnQuit() override;
			
		};
		
		/// 科学计数法数字模式
		/// 例如：0.5e+1/1e-5/...
		class StateENumber : public StateBase
		{
		protected:
			
			void OnInit() override;
			
			StateBase::ResultType OnTick(LexerDefault &lexer) override;
			
			void OnQuit() override;
			
		};
	
	public:
		
		explicit LexerDefault(BasicIStream<ElemT> &iStream, Logger &logger);
	
	public:
		
		Token<ElemT> *AnalysisNext() override;
		
		boolean IsEnd() override { return GetIStream().eof(); }
	
	public:
		
		void OutInfo(Info info, StringViewA message,
		             std::source_location sourceLocation = std::source_location::current());
		
		void OutWarning(Warning warning, StringViewA message,
		                std::source_location sourceLocation = std::source_location::current());
		
		void OutError(Error error, StringViewA message,
		              std::source_location sourceLocation = std::source_location::current());
		
		void OutErrorUnexpectedChar(i32 ch, std::source_location sourceLocation = std::source_location::current());
	
	public:
		
		/// 获取状态机
		[[nodiscard]] auto &GetStateMachine() const { return m_stateMachine; }
		
		/// 获取状态机
		[[nodiscard]] auto &GetStateMachine() { return m_stateMachine; }
		
		/// 获取输入流
		[[nodiscard]] auto &GetIStream() const { return m_istream; }
		
		/// 获取输入流
		[[nodiscard]] auto &GetIStream() { return m_istream; }
		
		/// 获取日志
		[[nodiscard]] auto &GetLogger() const { return m_logger; }
		
		/// 获取日志
		[[nodiscard]] auto &GetLogger() { return m_logger; }
	
	private:
		
		StateMachineBase m_stateMachine;
		
		BasicIStream<ElemT> &m_istream;
		
		Logger &m_logger;
		
	};
	
	template<class ElemT>
	LexerDefault<ElemT>::LexerDefault(BasicIStream<ElemT> &iStream, Logger &logger)
		: m_stateMachine(), m_istream(iStream), m_logger(logger)
	{
		GetStateMachine().template SetState<StateStart>();
	}
	
	template<class ElemT>
	void LexerDefault<ElemT>::OutInfo(LexerDefault::Info info, StringViewA message, std::source_location sourceLocation)
	{
		GetLogger().Log(
			Anasul::LogLevel::Info, std::format("I{:04X}: {}", static_cast<i32>(info), message), sourceLocation
		);
	}
	
	template<class ElemT>
	void LexerDefault<ElemT>::OutWarning(LexerDefault::Warning warning, StringViewA message,
	                                     std::source_location sourceLocation)
	{
		GetLogger().Log(
			Anasul::LogLevel::Warning, std::format("W{:04X}: {}", static_cast<i32>(warning), message), sourceLocation
		);
	}
	
	template<class ElemT>
	void LexerDefault<ElemT>::OutError(Error error, StringViewA message, std::source_location sourceLocation)
	{
		GetLogger().Log(
			Anasul::LogLevel::Error, std::format("E{:04X}: {}", static_cast<i32>(error), message), sourceLocation
		);
	}
	
	template<class ElemT>
	void LexerDefault<ElemT>::OutErrorUnexpectedChar(i32 ch, std::source_location sourceLocation)
	{
		OutError(
			ErrorUnexpectedCharacter,
			isprint(ch) ? std::format("unexpected character '{}'", static_cast<c8>(ch)) : std::format(
				"unexpected character 0x{:X}", ch
			), sourceLocation
		);
		GetStateMachine().template SetState<StateStart>();
		GetIStream().get();
	}
	
	template<class ElemT>
	Token<ElemT> *LexerDefault<ElemT>::AnalysisNext()
	{
		auto result = GetStateMachine().Tick(*this);
		return result;
	}
	
	
} // Anasul
