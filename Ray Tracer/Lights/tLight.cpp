//
// tLight.cpp
//

#include "tLight.h"

#include "../Game Controller/tColor.h"

//
// Constructor()
//
tLight::tLight()
{
}


//
// Constructor()
//
tLight::tLight( const tColor& color, const tPoint& position )
{
}


//
// Destructor()
//
tLight::~tLight()
{
}


//
// L()
//
tColor tLight::L( tShadeRecord& s )
{
	return tColor( 0.0f, 0.0f, 0.0f );
}

