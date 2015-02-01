//
// tColor.cpp
//

#include "tColor.h"

//
// Constructor()
//
tColor::tColor()
: _red( 0.0 ),
  _green( 0.0 ),
  _blue( 0.0 )
{
}


//
// Constructor()
//
tColor::tColor( float red, float green, float blue )
: _red( red ),
  _green( green ),
  _blue( blue )
{
}


//
// Destructor()
//
tColor::~tColor()
{
}


//
// operator +=
//
void tColor::operator += ( const tColor& rhs )
{
	_red += rhs._red;
	_green += rhs._green;
	_blue += rhs._blue;
}


//
// operator +
//
tColor tColor::operator + ( const tColor& rhs )
{
	return tColor( _red + rhs._red, _green + rhs._green, _blue + rhs._blue );
}


//
// operator *
//
tColor tColor::operator * ( float scalar ) const
{
	return tColor( _red * scalar, _green * scalar, _blue * scalar );
}


//
// operator /
//
tColor tColor::operator / ( float scalar )
{
	return tColor( _red / scalar, _green / scalar, _blue / scalar );
}


//
// operator *
//
tColor tColor::operator * ( const tColor& rhs )
{
	return tColor( _red * rhs._red, _green * rhs._green, _blue * rhs._blue );
}
