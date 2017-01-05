#ifndef MATH_VEC4_H
#define MATH_VEC4_H

#include <math.h>
#include "Common.Math/Algebra/Misc.h"
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Algebra/Vec3.h"

namespace math
{

	class Vec4
	{
	public:
		float X, Y, Z, W;

		Vec4( float x, float y, float z, float w ) :
			X( x ),
			Y( y ),
			Z( z ),
			W( w )
		{}

		Vec4() :
			X( 0.0f ),
			Y( 0.0f ),
			Z( 0.0f ),
			W( 1.0f )
		{}

		Vec4( const Vec3& vec, float w ) :
			X( vec.X ),
			Y( vec.Y ),
			Z( vec.Z ),
			W( w )
		{}

		Vec4( const Vec2& vec, float z, float w ) :
			X( vec.X ),
			Y( vec.Y ),
			Z( z ),
			W( w )
		{}

		Vec4 operator += ( const Vec4& v );
		Vec4 operator -= ( const Vec4& v );
		Vec4 operator *= ( float a );
		Vec4 operator /= ( float a );

		inline float Len() const
		{
			return ( float ) sqrt( Norm() );
		}

		inline float Norm() const
		{
			return ( float )( X * X + Y * Y + Z * Z + W * W );
		}

		Vec4 Normalize();

		static Vec4 ZeroVec() { return Vec4( 0.0f, 0.0f, 0.0f, 0.0f ); }
		static Vec4 ZeroPoint() { return Vec4( 0.0f, 0.0f, 0.0f, 1.0f ); }

		static Vec4 Up() { return Vec4( 0.0f, 1.0f, 0.0f, 0.0f ); }
		static Vec4 Down() { return Vec4( 0.0f, -1.0f, 0.0f, 0.0f ); }
		static Vec4 Left() { return Vec4( -1.0f, 0.0f, 0.0f, 0.0f ); }
		static Vec4 Right() { return Vec4( 1.0f, 0.0f, 0.0f, 0.0f ); }
		static Vec4 Forward() { return Vec4( 0.0f, 0.0f, 1.0f, 0.0f ); }
		static Vec4 Back() { return Vec4( 0.0f, 0.0f, -1.0f, 0.0f ); }
	};

	inline Vec4 operator- ( const Vec4& v )
	{
		return Vec4( -v.X, -v.Y, -v.Z, -v.W );
	}

	inline Vec4 operator+ ( const Vec4& a, const Vec4& b )
	{
		return Vec4( a.X + b.X, a.Y + b.Y, a.Z + b.Z, a.W + b.W );
	}

	inline Vec4 operator- ( const Vec4& a, const Vec4& b )
	{
		return Vec4( a.X - b.X, a.Y - b.Y, a.Z - b.Z, a.W - b.W );
	}

	inline Vec4 operator* ( const Vec4& v, float a )
	{
		return Vec4( v.X * a, v.Y * a, v.Z * a, v.W * a );
	}

	inline Vec4 operator/ ( const Vec4& v, float a )
	{
		return Vec4( v.X / a, v.Y / a, v.Z / a, v.W / a );
	}

	inline Vec4 operator^ ( const Vec4& a, const Vec4& b )
	{
		return Vec4( a.Y * b.Z - a.Z * b.Y, a.Z * b.X - a.X * b.Z, a.X * b.Y - a.Y * b.X, a.W );
	}

	inline float operator* ( const Vec4& a, const Vec4& b )
	{
		return a.X * b.X + a.Y * b.Y + a.Z * b.Z + a.W * b.W;
	}

	inline bool operator== ( const Vec4& a, const Vec4& b )
	{
		return a.X == b.X && a.Y == b.Y && a.Z == b.Z && a.W == b.W;
	}

	inline bool operator!= ( const Vec4& a, const Vec4& b )
	{
		return a.X != b.X || a.Y != b.Y || a.Z != b.Z || a.W != b.W;
	}
}
#endif
