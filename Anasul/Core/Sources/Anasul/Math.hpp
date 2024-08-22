//
// Created by admin on 2024/8/22.
//

#pragma once

#include <Anasul/Config.hpp>

#include <utility>

namespace Anasul
{
	template<typename ElemT>
	class ANASUL_API Vector2D
	{
	public:
		
		Vector2D() : x{}, y{} {}
		
		Vector2D(ElemT x, ElemT y) : x(std::move(x)), y(std::move(y)) {}
	
	public:
		
		ElemT x, y;
		
	};
	
	using Vector2i = Vector2D<i32>;
	using Vector2u = Vector2D<u32>;
	using Vector2f = Vector2D<float>;
	using Vector2d = Vector2D<double>;
	
	template<typename ElemT>
	class ANASUL_API Vector3D
	{
	public:
		
		
		Vector3D() : x{}, y{}, z{} {}
		
		Vector3D(ElemT x, ElemT y, ElemT z) : x(std::move(x)), y(std::move(y)), z(std::move(z)) {}
	
	public:
		
		ElemT x, y, z;
		
	};
	
	using Vector3i = Vector3D<i32>;
	using Vector3u = Vector3D<u32>;
	using Vector3f = Vector3D<float>;
	using Vector3d = Vector3D<double>;
	
	template<typename ElemT>
	class ANASUL_API Vector4D
	{
	public:
		
		Vector4D() : x{}, y{}, z{}, w{} {}
		
		Vector4D(ElemT x, ElemT y, ElemT z, ElemT w) : x(std::move(x)), y(std::move(y)), z(std::move(z)),
		                                               w(std::move(w)) {}
	
	public:
		
		ElemT x, y, z, w;
		
	};
	
	using Vector4i = Vector4D<i32>;
	using Vector4u = Vector4D<u32>;
	using Vector4f = Vector4D<float>;
	using Vector4d = Vector4D<double>;
	
	template<typename ElemT>
	class ANASUL_API Point2D : public Vector2D<ElemT>
	{
	public:
		
		using Vector2D<ElemT>::Vector2D;
		
	};
	
	
	using Point2i = Point2D<i32>;
	using Point2u = Point2D<u32>;
	using Point2f = Point2D<float>;
	using Point2d = Point2D<double>;
	
	template<typename ElemT>
	class ANASUL_API Point3D : public Vector3D<ElemT>
	{
	public:
		
		using Vector3D<ElemT>::Vector3D;
		
	};
	
	using Point3i = Point3D<i32>;
	using Point3u = Point3D<u32>;
	using Point3f = Point3D<float>;
	using Point3d = Point3D<double>;
	
	template<typename ElemT>
	class ANASUL_API Point4D : public Vector4D<ElemT>
	{
	public:
		
		using Vector4D<ElemT>::Vector4D;
		
	};
	
	template<typename ElemT>
	class ANASUL_API Size2D : public Vector2D<ElemT>
	{
	public:
		
		using Vector2D<ElemT>::Vector2D;
		
	};
	
	using Size2i = Size2D<i32>;
	using Size2u = Size2D<u32>;
	using Size2f = Size2D<float>;
	using Size2d = Size2D<double>;
	
	template<typename ElemT>
	class ANASUL_API Rect4D : public Vector4D<ElemT>
	{
	public:
		
		using Vector4D<ElemT>::Vector4D;
		
	};
	
	using Rect4i = Rect4D<i32>;
	using Rect4u = Rect4D<u32>;
	using Rect4f = Rect4D<float>;
	using Rect4d = Rect4D<double>;
	
	using Point4i = Point4D<i32>;
	using Point4u = Point4D<u32>;
	using Point4f = Point4D<float>;
	using Point4d = Point4D<double>;
	
	template<typename ElemT>
	class ANASUL_API Color : public Vector4D<ElemT>
	{
	public:
		
		using Vector4D<ElemT>::Vector4D;
		
	};
	
	using Color4i = Color<i32>;
	using Color4u = Color<u32>;
	using Color4f = Color<float>;
	using Color4d = Color<double>;
	
} // Anasul
