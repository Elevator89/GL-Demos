#ifndef MATH_TRANSFORM_H
#define MATH_TRANSFORM_H

#include "Common.Math/Algebra/Misc.h"
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Algebra/Matr4.h"

namespace math {

	class Transform
	{
	public:
		Vec2 Vec;
		float Rot;
		float Scale;

		Transform() :
			Rot( 0.0f ),
			Scale( 1.0f )
		{}

		Transform( const Vec2& vec, float rot, float scale = 1.0f ) :
			Vec( vec ),
			Rot( rot ),
			Scale( scale )
		{}

		Transform operator += ( const Transform& tf );
		Transform operator -= ( const Transform& tf );
		Transform operator *= ( const float a );

		Vec2 ToGlobal( const Vec2& local );
		Vec2 ToLocal( const Vec2& global );

		Transform GetGlobalTransform( const Transform& local );
		Transform GetLocalTransform( const Transform& global );

		Matr4 GetMatrix() const;
		Matr4 GetInvMatrix() const;

		static const Transform Zero() { return Transform( Vec2::Zero(), 0.0f, 1.0f ); }
		static Transform FromMatrix( const Matr4& matr );
	};

	inline Transform operator + ( const Transform& a, const Transform& b )
	{
		return Transform( a.Vec + b.Vec, a.Rot + b.Rot, a.Scale * b.Scale );
	}

	inline Transform operator - ( const Transform& a, const Transform& b )
	{
		return Transform( a.Vec - b.Vec, a.Rot - b.Rot, a.Scale / b.Scale );
	}

	inline Transform operator * ( const Transform& tf, const float a )
	{
		return Transform( tf.Vec * a, tf.Rot * a );
	}

	inline bool operator == ( const Transform& a, const Transform& b )
	{
		if( a.Vec != b.Vec ) return false;

		if( a.Rot != b.Rot ) return false;

		if( a.Scale != b.Scale ) return false;

		return true;
	}

	inline bool operator != ( const Transform& a, const Transform& b )
	{
		return !( a == b );
	}
}
#endif
