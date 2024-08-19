//
// Created by admin on 2024/8/16.
//

#pragma once

#include "Config.hpp"
#include "String.hpp"

namespace Anasul
{
	
	extern "C"
	{
	
	/// 获取库名称
	ANASUL_API const c8 *GetNameA();
	
	/// 获取库名称
	ANASUL_API const cwide *GetNameW();
	
	/// 获取主版本号
	ANASUL_API i32 GetMajor();
	
	/// 获取次版本号
	ANASUL_API i32 GetMinor();
	
	/// 获取补丁版本号
	ANASUL_API i32 GetPatch();
	
	/// 获取库编译日期
	ANASUL_API const c8 *GetBuildDataA();
	
	/// 获取库编译日期
	ANASUL_API const cwide *GetBuildDataW();
	
	/// 获取库编译时间
	ANASUL_API const c8 *GetBuildTimeA();
	
	/// 获取库编译时间
	ANASUL_API const cwide *GetBuildTimeW();
	
	/// 获取库希腊字母版本号
	ANASUL_API const c8 *GetGreekAlphabetA();
	
	/// 获取库希腊字母版本号
	ANASUL_API const cwide *GetGreekAlphabetW();
	
	}
	
	/// 获取库版本
	ANASUL_API StringA GetVersionA();
	
	/// 获取库版本
	ANASUL_API StringW GetVersionW();
	
} // Anasul
