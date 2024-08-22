//
// Created by admin on 2024/8/21.
//

#include "Result.hpp"

#include "Windows.hpp"

namespace Anasul
{
	
	template<>
	ANASUL_API StringA MessageToString(HResult dwMessageId)
	{
		auto strBufferError = new c8[256];
		::FormatMessageA
			(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr, dwMessageId, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				strBufferError, 256, nullptr
			);
		StringA buffer = strBufferError;
		delete[] strBufferError;
		return buffer;
	}
	
	template<>
	ANASUL_API StringW MessageToString(HResult dwMessageId)
	{
		auto strBufferError = new cwide[256];
		::FormatMessageW
			(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr, dwMessageId, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
				strBufferError, 256, nullptr
			);
		StringW buffer = strBufferError;
		delete[] strBufferError;
		return buffer;
	}
	
	HResult LastErrorForHResult()
	{
		return HRESULT_FROM_WIN32(::GetLastError());
	}
} // Anasul