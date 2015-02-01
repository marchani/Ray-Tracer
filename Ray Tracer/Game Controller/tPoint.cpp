//
// tPoint.cpp
//

#include "tPoint.h"

#include <math.h>


//
// Constructor()
//
tPoint::tPoint()
: _x( 0.0 ),
  _y( 0.0 ),
  _z( 0.0 )
{
}


//
// Constructor()
//
tPoint::tPoint( float x, float y, float z )
: _x( x ),
  _y( y ),
  _z( z )
{
}


//
// Destructor()
//
tPoint::~tPoint()
{
}


//
// operator +
//
tPoint tPoint::operator + ( const tVector& rhs )
{
	tPoint result = tPoint( _x + rhs.getX(), _y + rhs.getY(), _z + rhs.getZ() );

	return result;
}


//
// operator -
//
tVector tPoint::operator - ( const tPoint& rhs )
{
	tVector result = tVector( _x - rhs._x, _y - rhs._y, _z - rhs._z );

	return result;
}


//
// distance()
//
float tPoint::distance( const tPoint& p ) const
{
	return( sqrt( ( _x - p.getX() ) * ( _x - p.getX() ) + ( _y - p.getY() ) * ( _y - p.getY() ) + ( _z - p.getZ() ) * ( _z - p.getZ() ) ) );
}
