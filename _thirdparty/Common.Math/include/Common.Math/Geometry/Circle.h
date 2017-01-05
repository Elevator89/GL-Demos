#ifndef MATH_CIRCLE_H
#define MATH_CIRCLE_H

#include "Common.Math/Algebra/Vec2.h"

namespace math
{

	struct Circle
	{
	public:
		Vec2 Center;
		float Radius;

		Circle( Vec2 position, float raduis ) :
			Center( position ),
			Radius( raduis )
		{}

		Circle() :
			Center( Vec2::Zero() ),
			Radius( 0.0f )
		{}
	};

	inline bool operator == ( const Circle& a, const Circle& b )
	{
		return
			a.Center.X == b.Center.X &&
			a.Center.Y == b.Center.Y &&
			a.Radius == b.Radius;
	}

	inline bool operator != ( const Circle& a, const Circle& b )
	{
		return !( a == b );
	}
}
#endif
