#ifndef CHAIN_H
#define CHAIN_H

#include <vector>
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Geometry/Circle.h"
#include "IChain.h"

class Chain : public IChain
{
public:
	Chain() {}
	virtual ~Chain() {}

	virtual const std::vector<math::Circle>& GetLinks() const {
		return m_links;
	}

protected:
	std::vector<math::Circle> m_links;

};

#endif // CHAIN_H
