//
// tVector3.cpp
//

#include "tVector.h"

#include <math.h>
#include "tPoint.h"

//
// Constructor()
//
tVector::tVector()
: _x( 0.0 ),
  _y( 0.0 ),
  _z( 0.0 )
{
}


//
// Constructor()
//
tVector::tVector( float x, float y, float z )
: _x( x ),
  _y( y ),
  _z( z )
{
}


//
// Destructor()
//
tVector::~tVector()
{
}

		
//
// getMagnitude()
//
float tVector::getMagnitude() const
{
	return sqrt( ( _x * _x ) + ( _y * _y ) + ( _z * _z ) );
}


//
// operator-
//
tVector tVector::operator- () const
{
	return ( tVector( -_x, -_y, -_z ) );
}


//
// operator +
//
tVector tVector::operator + ( const tVector& rhs )
{
	tVector result = tVector( _x + rhs._x, _y + rhs._y, _z + rhs._z );

	return result;
}


//
// operator -
//
tVector tVector::operator - ( const tVector& rhs ) const
{
	tVector result = tVector( _x - rhs._x, _y - rhs._y, _z - rhs._z );

	return result;
}


//
// operator *
//
tVector tVector::operator * ( float scalar ) const
{
	return tVector( _x * scalar, _y * scalar, _z * scalar );
}


//
// operator /
//
tVector tVector::operator / ( float scalar )
{
	return tVector( _x / scalar, _y / scalar, _z / scalar );
}


//
// dot()
//
float tVector::dot( const tVector& lhs, const tVector& rhs )
{
	return ( lhs._x * rhs._x ) + ( lhs._y * rhs._y ) + ( lhs._z * rhs._z );
}


//
// operator^
//
tVector tVector::operator^( const tVector& v ) const
{
	return ( tVector( _y * v.getZ() - _z * v.getY(), _z * v.getX() - _x * v.getZ(), _x * v.getY() - _y * v.getX() ) );
}


//
// normalize()
//
void tVector::normalize()
{
	float magnitude = getMagnitude();

	if( magnitude != 0.0 )
	{
		float factor = 1.0f / magnitude;

		_x = _x * factor;
		_y = _y * factor;
		_z = _z * factor;
	}
	else
	{
		// Do nothing.
	}
}