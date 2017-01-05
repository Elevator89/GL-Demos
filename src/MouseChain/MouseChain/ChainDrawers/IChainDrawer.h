#ifndef ICHAINDRAWER_H
#define ICHAINDRAWER_H

#include "MouseChain/Chains/IChain.h"

class IChainDrawer
{
public:
	virtual ~IChainDrawer() {}
	virtual void Draw( const IChain& chain ) const = 0;
};

#endif // ICHAINDRAWER_H
