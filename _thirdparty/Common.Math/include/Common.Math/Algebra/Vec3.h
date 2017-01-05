#ifndef MATH_VEC3_H
#define MATH_VEC3_H

#include <math.h>
#include "Common.Math/Algebra/Vec2.h"

namespace math
{

	class Vec3
	{
	public:
		float X, Y, Z;

		Vec3() :
			X( 0.0f ),
			Y( 0.0f ),
			Z( 0.0f )
		{}

		Vec3( float x, float y, float z ) :
			X( x ),
			Y( y ),
			Z( z )
		{}

		Vec3( const Vec2& vec, float z ) :
			X( vec.X ),
			Y( vec.Y ),
			Z( z )
		{}

		Vec3 operator += ( const Vec3& v );
		Vec3 operator -= ( const Vec3& v );
		Vec3 operator *= ( float a );
		Vec3 operator /= ( float a );

		inline float Len() const
		{
			return ( float ) sqrt( Norm() );
		}

		inline float Norm() const
		{
			return ( float )( X * X + Y * Y + Z * Z );
		}

		Vec3 Normalize();

		static inline Vec3 Zero() { return Vec3( 0.0f, 0.0f, 0.0f ); }
		static inline Vec3 Up() { return Vec3( 0.0f, 1.0f, 0.0f ); }
		static inline Vec3 Down() { return Vec3( 0.0f, -1.0f, 0.0f ); }
		static inline Vec3 Left() { return Vec3( -1.0f, 0.0f, 0.0f ); }
		static inline Vec3 Right() { return Vec3( 1.0f, 0.0f, 0.0f ); }
		static inline Vec3 Forward() { return Vec3( 0.0f, 0.0f, -1.0f ); }
		static inline Vec3 Backward() { return Vec3( 0.0f, 0.0f, 1.0f ); }
	};

	inline Vec3 operator- ( const Vec3& v )
	{
		return Vec3( -v.X, -v.Y, -v.Z );
	}

	inline Vec3 operator+ ( const Vec3& a, const Vec3& b )
	{
		return Vec3( a.X + b.X, a.Y + b.Y, a.Z + b.Z );
	}

	inline Vec3 operator- ( const Vec3& a, const Vec3& b )
	{
		return Vec3( a.X - b.X, a.Y - b.Y, a.Z - b.Z );
	}

	inline Vec3 operator* ( const Vec3& v, float a )
	{
		return Vec3( v.X * a, v.Y * a, v.Z * a );
	}

	inline Vec3 operator* ( float a, const Vec3& v )
	{
		return Vec3( v.X * a, v.Y * a, v.Z * a );
	}

	inline Vec3 operator/ ( const Vec3& v, float a )
	{
		return Vec3( v.X / a, v.Y / a, v.Z / a );
	}

	inline Vec3 operator^ ( const Vec3& a, const Vec3& b )
	{
		return Vec3( a.Z * b.Y - a.Y * b.Z, a.X * b.Z - a.Z * b.X, a.Y * b.X - a.X * b.Y );
	}

	inline float operator* ( const Vec3& a, const Vec3& b )
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
	}

	inline bool operator== ( const Vec3& a, const Vec3& b )
	{
		return a.X == b.X && a.Y == b.Y && a.Z == b.Z;
	}

	inline bool operator!= ( const Vec3& a, const Vec3& b )
	{
		return a.X != b.X || a.Y != b.Y || a.Z != b.Z;
	}
}

#endif
