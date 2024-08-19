//
// Created by admin on 2024/8/18.
//

#pragma once

#include "Config.hpp"

#include <string>
#include <string_view>
#include <sstream>

namespace Anasul
{
	
	template<class ElemT>
	using BasicString = std::basic_string<ElemT>;
	
	template<class ElemT>
	using BasicStringView = std::basic_string_view<ElemT>;
	
	template<class ElemT>
	using BasicIOStream = std::basic_iostream<ElemT>;
	
	template<class ElemT>
	using BasicIStream = std::basic_istream<ElemT>;
	
	template<class ElemT>
	using BasicOStream = std::basic_ostream<ElemT>;
	
	template<class ElemT>
	using BasicStringStream = std::basic_stringstream<ElemT>;
	
	using String = BasicString<chararcter>;
	using StringA = BasicString<c8>;
	using StringW = BasicString<cwide>;
	
	using StringView = BasicStringView<chararcter>;
	using StringViewA = BasicStringView<c8>;
	using StringViewW = BasicStringView<cwide>;
	
	using StringStream = BasicStringStream<chararcter>;
	using StringStreamA = BasicStringStream<c8>;
	using StringStreamW = BasicStringStream<cwide>;
	
} // Anasul
