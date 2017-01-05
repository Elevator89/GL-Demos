#include "Caterpillar.h"

using math::Vec2;
using math::Circle;

Caterpillar::Caterpillar( int linkCount, float headRadius, float tailRadius )
{
	float radiusDiff = tailRadius - headRadius;

	for( int i = 0; i < linkCount; ++i )
		m_links.push_back( Circle( Vec2::Zero(), headRadius + radiusDiff * float( i ) / ( linkCount - 1 ) ) );
}

Caterpillar::~Caterpillar() {}

void Caterpillar::Update( const Vec2& headPos )
{
	m_links[0].Center = headPos;
	Circle frontCircle = m_links[0];

	for( std::size_t i = 1; i < m_links.size(); ++i )
	{
		Vec2 linkPos = m_links[i].Center;
		Vec2 linkDirection = linkPos - frontCircle.Center;

		m_links[i].Center = frontCircle.Center + linkDirection.GetNormal() * frontCircle.Radius;

		frontCircle = m_links[i];
	}
}
