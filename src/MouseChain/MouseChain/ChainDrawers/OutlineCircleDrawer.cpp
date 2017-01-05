#include <vector>
#include "OutlineCircleDrawer.h"
#include "DrawTools.h"

OutlineCircleDrawer::OutlineCircleDrawer( const Color& color, const Color& outlineColor ) :
	m_color( color ),
	m_outlineColor( outlineColor )
{}

OutlineCircleDrawer::~OutlineCircleDrawer() {}

void OutlineCircleDrawer::Draw( const IChain& chain ) const
{
	std::vector<math::Circle> links = chain.GetLinks();

	for( std::size_t i = 0; i < links.size(); ++i )
		DrawCircle( links[i], m_outlineColor );

	for( std::size_t i = 0; i < links.size(); ++i )
	{
		math::Circle circle = links[i];
		DrawCircle( math::Circle( circle.Center, circle.Radius * 0.75f ), m_color );
	}
}

