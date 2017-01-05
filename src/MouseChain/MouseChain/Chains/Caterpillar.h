#ifndef CATERPILLAR_H
#define CATERPILLAR_H

#include <vector>
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Geometry/Circle.h"
#include "Chain.h"

class Caterpillar : public Chain
{
public:
	Caterpillar( int linkCount, float headRadius, float tailRadius );
	virtual ~Caterpillar();

	virtual void Update( const math::Vec2& headPos );
};

#endif // CATERPILLAR_H
