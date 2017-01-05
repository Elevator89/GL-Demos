#ifndef SOLIDCIRCLEDRAWER_H
#define SOLIDCIRCLEDRAWER_H

#include "MouseChain/ChainDrawers/IChainDrawer.h"
#include "MouseChain/Color.h"

class SolidCircleDrawer : public IChainDrawer
{
public:
	SolidCircleDrawer( const Color & color );
	virtual ~SolidCircleDrawer();

	virtual void Draw( const IChain& chain ) const;
private:
	Color m_color;
};

#endif // SOLIDCIRCLEDRAWER_H
