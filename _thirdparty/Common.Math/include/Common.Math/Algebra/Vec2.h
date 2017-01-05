#ifndef MATH_VEC2_H
#define MATH_VEC2_H

#include <math.h>
#include "Common.Math/Algebra/Misc.h"

namespace math
{

	class Vec2
	{
	public:
		float X, Y;

		Vec2() :
			X( 0.0f ),
			Y( 0.0f )
		{}

		Vec2( float x, float y ) :
			X( x ),
			Y( y )
		{}

		Vec2 operator += ( const Vec2& v );
		Vec2 operator -= ( const Vec2& v );
		Vec2 operator *= ( float a );
		Vec2 operator /= ( float a );

		inline float Length() const
		{
			return ( float ) sqrt( Norm() );
		}

		inline float Norm() const
		{
			return ( float )( X * X + Y * Y );
		}

		Vec2 Normalize();
		Vec2 RotateByAngle( float angle );
		Vec2 RotateToAngle( float angle );
		Vec2 RotateLeft();
		Vec2 RotateRight();

		float GetAngle() const;
		Vec2 GetNormal() const;
		Vec2 GetRotationByAngle( float angle ) const;
		Vec2 GetRotationToAngle( float angle ) const;
		Vec2 GetLeftRotation() const;
		Vec2 GetRightRotation() const;

		static inline bool Clockwise( const Vec2& a, const Vec2& b )
		{
			return Det2( a.X, b.X, a.Y, b.Y ) < 0;
		}

		static inline bool Counterclockwise( const Vec2& a, const Vec2& b )
		{
			return Det2( a.X, b.X, a.Y, b.Y ) > 0;
		}

		static inline Vec2 Zero() { return Vec2( 0.0f, 0.0f ); }
		static inline Vec2 Up() { return Vec2( 0.0f, 1.0f ); }
		static inline Vec2 Down() { return Vec2( 0.0f, -1.0f ); }
		static inline Vec2 Left() { return Vec2( -1.0f, 0.0f ); }
		static inline Vec2 Right() { return Vec2( 1.0f, 0.0f ); }
	};

	inline Vec2 operator- ( const Vec2& v )
	{
		return Vec2( -v.X, -v.Y );
	}

	inline Vec2 operator+ ( const Vec2& a, const Vec2& b )
	{
		return Vec2( a.X + b.X, a.Y + b.Y );
	}

	inline Vec2 operator- ( const Vec2& a, const Vec2& b )
	{
		return Vec2( a.X - b.X, a.Y - b.Y );
	}

	inline Vec2 operator* ( const Vec2& v, float a )
	{
		return Vec2( v.X * a, v.Y * a );
	}

	inline Vec2 operator* ( float a, const Vec2& v )
	{
		return Vec2( v.X * a, v.Y * a );
	}

	inline Vec2 operator/ ( const Vec2& v, float a )
	{
		return Vec2( v.X / a, v.Y / a );
	}

	inline float operator^ ( const Vec2& a, const Vec2& b )
	{
		return a.Y * b.X - a.X * b.Y;
	}

	inline Vec2 operator^ ( const Vec2& v, float z )
	{
		return Vec2( -v.Y * z, v.X * z );
	}

	inline Vec2 operator^ ( float z, const Vec2& v )
	{
		return Vec2( z * v.Y, -z * v.X );
	}

	inline float operator* ( const Vec2& a, const Vec2& b )
	{
		return a.X * b.X + a.Y * b.Y;
	}

	inline bool operator== ( const Vec2& a, const Vec2& b )
	{
		return a.X == b.X && a.Y == b.Y;
	}

	inline bool operator!= ( const Vec2& a, const Vec2& b )
	{
		return a.X != b.X || a.Y != b.Y;
	}

	inline float Angle( const Vec2& a, const Vec2& b )
	{
		return acos( a.GetNormal() * b.GetNormal() );
	}

	inline float Distance( const Vec2& a, const Vec2& b )
	{
		float dx = a.X - b.X;
		float dy = a.Y - b.Y;
		return sqrt( dx * dx + dy * dy );
	}
}

#endif
