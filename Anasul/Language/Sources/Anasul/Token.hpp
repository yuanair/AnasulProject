//
// Created by admin on 2024/8/18.
//

#pragma once

#include <Anasul/Config.hpp>
#include <Anasul/String.hpp>

namespace Anasul
{
	/// 符号
	template<class ElemT>
	class ANASUL_API Token
	{
	public:
		
		virtual ~Token() = default;
	
	public:
		
		[[nodiscard]] virtual BasicString<ElemT> ToString() const = 0;
		
	};
	
	/// 符号：操作符
	template<class ElemT>
	class ANASUL_API TokenOperator : public Token<ElemT>
	{
	public:
		
		~TokenOperator() override = default;
	
	public:
		
		[[nodiscard]] BasicString<ElemT> ToString() const override = 0;
		
	};
	
	/// 符号：整数
	template<class ElemT>
	class ANASUL_API TokenInteger : public Token<ElemT>
	{
	public:
		
		explicit TokenInteger(BasicString<ElemT> mInteger) : m_integer(std::move(mInteger)) {}
		
		~TokenInteger() override = default;
	
	public:
		
		[[nodiscard]] BasicString<ElemT> ToString() const override { return m_integer; }
	
	private:
		
		BasicString<ElemT> m_integer;
		
	};
	
	/// 符号：小数
	template<class ElemT>
	class ANASUL_API TokenDecimal : public Token<ElemT>
	{
	public:
		
		TokenDecimal(BasicString<ElemT> mInteger, BasicString<ElemT> mDecimal) : m_integer(std::move(mInteger)),
		                                                                         m_decimal(std::move(mDecimal)) {}
		
		~TokenDecimal() override = default;
	
	public:
		
		[[nodiscard]] BasicString<ElemT> ToString() const override
		{
			return BasicString<ElemT>(m_integer)
				.append({static_cast<ElemT>('.')})
				.append(m_decimal);
		}
	
	private:
		
		BasicString<ElemT> m_integer;
		
		BasicString<ElemT> m_decimal;
		
	};
	
	
	/// 符号：科学计数整数
	template<class ElemT>
	class ANASUL_API TokenEInteger : public Token<ElemT>
	{
	public:
		
		TokenEInteger(BasicString<ElemT> mInteger, boolean mESign, BasicString<ElemT> mEInteger)
			: m_integer(std::move(mInteger)), m_eSign(mESign), m_eInteger(std::move(mEInteger)) {}
		
		~TokenEInteger() override = default;
	
	public:
		
		[[nodiscard]] BasicString<ElemT> ToString() const override
		{
			return BasicString<ElemT>(m_integer)
				.append({static_cast<ElemT>('e')})
				.append({static_cast<ElemT>(m_eSign ? '-' : '+')})
				.append(m_eInteger);
		}
	
	private:
		
		BasicString<ElemT> m_integer;
		
		boolean m_eSign;
		
		BasicString<ElemT> m_eInteger;
		
	};
	
	/// 符号：科学计数小数
	template<class ElemT>
	class ANASUL_API TokenEDecimal : public Token<ElemT>
	{
	public:
		
		TokenEDecimal(BasicString<ElemT> mInteger, BasicString<ElemT> mDecimal, boolean mESign,
		              BasicString<ElemT> mEInteger) : m_integer(std::move(mInteger)), m_decimal(std::move(mDecimal)),
		                                              m_eSign(mESign), m_eInteger(std::move(mEInteger)) {}
		
		~TokenEDecimal() override = default;
	
	public:
		
		[[nodiscard]] BasicString<ElemT> ToString() const override
		{
			return BasicString<ElemT>(m_integer)
				.append({static_cast<ElemT>('.')})
				.append(m_decimal)
				.append({static_cast<ElemT>('e')})
				.append({static_cast<ElemT>(m_eSign ? '-' : '+')})
				.append(m_decimal);
		}
	
	private:
		
		BasicString<ElemT> m_integer;
		
		BasicString<ElemT> m_decimal;
		
		boolean m_eSign;
		
		BasicString<ElemT> m_eInteger;
		
	};
	
} // Anasul
