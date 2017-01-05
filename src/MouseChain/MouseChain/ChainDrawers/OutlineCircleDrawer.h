#ifndef OUTLINECIRCLEDRAWER_H
#define OUTLINECIRCLEDRAWER_H

#include "MouseChain/ChainDrawers/IChainDrawer.h"
#include "MouseChain/Color.h"

class OutlineCircleDrawer : public IChainDrawer
{
public:
	OutlineCircleDrawer( const Color& color, const Color& outlineColor );
	virtual ~OutlineCircleDrawer();

	virtual void Draw( const IChain& chain ) const;
private:
	Color m_color;
	Color m_outlineColor;
};

#endif // OUTLINECIRCLEDRAWER_H
