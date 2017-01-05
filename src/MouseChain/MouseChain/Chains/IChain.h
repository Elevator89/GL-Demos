#ifndef ICHAIN_H
#define ICHAIN_H

#include <vector>
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Geometry/Circle.h"

class IChain
{
public:
	virtual ~IChain() {}

	virtual void Update( const math::Vec2& headPos ) = 0;

	virtual const std::vector<math::Circle>& GetLinks() const = 0;
};

#endif // ICHAIN_H
