//
// tAmbientLight.cpp
//

#include "tAmbientLight.h"

#include "tColor.h"

//
// Constructor()
//
tAmbientLight::tAmbientLight()
{
	ls = 1.0f;
}


//
// Constructor()
//
tAmbientLight::tAmbientLight( const tColor& color, const tPoint& position )
{
	_color = color;
	_position = position;
}


//
// Destructor()
//
tAmbientLight::~tAmbientLight()
{
}


//
// L()
//
tColor tAmbientLight::L( tShadeRecord& sr )
{
	return ( _color * ls );
}