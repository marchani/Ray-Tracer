//
// tRay.cpp
//

#include "tRay.h"


//
// Constructor()
//
tRay::tRay()
{
}


//
// Constructor
//
tRay::tRay( const tPoint& origin, const tVector& direction )
: _origin( origin ),
  _direction( direction )
{
}


//
// Destructor()
//
tRay::~tRay()
{
}