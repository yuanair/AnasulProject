//
// Created by admin on 2024/8/16.
//

#pragma once

#ifdef __GNUC__
	
	#include <_mingw.h>

#endif

#if defined(_WIN32)
	#define ANASUL_TARGET_WINDOWS
#elif defined(__APPLE__)
	#include "TargetConditionals.h"
	#if defined(TARGET_OS_IPHONE)
		#define ANASUL_TARGET_IOS
	#elif defined(TARGET_OS_MAC)
		#define ANASUL_TARGET_MACOS
	#else
		#error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	#define ANASUL_TARGET_ANDROID
#elif __linux__
	#define ANASUL_TARGET_LINUX
#else
	#error "Unknown platform"
#endif

#ifdef _MSC_VER
	#define ANASUL_FUNC __FUNCSIG__
#elif defined(__GNUC__)
	#define ANASUL_FUNC __PRETTY_FUNCTION__
#else
	#define ANASUL_FUNC __func__
#endif

#if __cplusplus >= 201103L
	#define ANASUL_CONSTEXPR11 constexpr
	#define ANASUL_USE_CONSTEXPR11 constexpr
#else
	#define ANASUL_CONSTEXPR11
	#define ANASUL_USE_CONSTEXPR11 const
#endif

#if __cplusplus >= 201402L
	#define ANASUL_CONSTEXPR14 constexpr
#else
	#define ANASUL_CONSTEXPR14
#endif

#if __cplusplus >= 201703L
	#define ANASUL_CONSTEXPR17 constexpr
#else
	#define ANASUL_CONSTEXPR17
#endif

#if __cplusplus >= 202002L
	#define ANASUL_CONSTEXPR20 constexpr
#else
	#define ANASUL_CONSTEXPR20
#endif

#if __cplusplus >= 202100L
	#define ANASUL_CONSTEXPR23 constexpr
#else
	#define ANASUL_CONSTEXPR23
#endif

#if __cplusplus >= 201703L
	#define ANASUL_INLINE17 inline
#else
	#define ANASUL_INLINE17
#endif

#ifndef ANASUL_API
	#ifdef _WIN32
		#define ANASUL_API __declspec(dllexport)
	#else
		#define ANASUL_API
	#endif
#else
	#ifdef _DLL
		#define ANASUL_API __declspec(dllimport)
	#else
		#define ANASUL_API
	#endif
#endif


#ifdef TEXT
	#undef TEXT
#endif

#define _ANASUL_TEXT(str) L ## str // NOLINT(*-reserved-identifier)
#define TEXT(str) _ANASUL_TEXT(str)

namespace Anasul
{
	
	using i8 = __int8;
	using i16 = __int16;
	using i32 = __int32;
	using i64 = __int64;
	
	using u8 = unsigned __int8;
	using u16 = unsigned __int16;
	using u32 = unsigned __int32;
	using u64 = unsigned __int64;
	
	using f32 = float;
	using f64 = double;
	
	using boolean = bool;
	
	using c8 = char;
	using c16 = char16_t;
	using c32 = char32_t;
	using cwide = wchar_t;
	
	using chararcter = cwide;
	
} // Anasul
