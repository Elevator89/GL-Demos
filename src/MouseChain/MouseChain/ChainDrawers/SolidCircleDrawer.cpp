#include <vector>
#include "SolidCircleDrawer.h"
#include "DrawTools.h"

SolidCircleDrawer::SolidCircleDrawer( const Color& color ) :
	m_color( color )
{}

SolidCircleDrawer::~SolidCircleDrawer() {}

void SolidCircleDrawer::Draw( const IChain& chain ) const
{
	std::vector<math::Circle> links = chain.GetLinks();

	for( std::size_t i = 0; i < links.size(); ++i )
		DrawCircle( links[i], m_color );
}
