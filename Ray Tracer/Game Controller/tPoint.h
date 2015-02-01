//
// tPoint.h
//

#ifndef ___TPOINT_H___
#define ___TPOINT_H___

#include "tVector.h"

//
// tPoint
//
class tPoint
{
	public:

		// constructor()
		tPoint();

		// constructor()
		tPoint( float x, float y, float z );

		// destructor()
		~tPoint();

		// getX()
		float getX() const { return _x; }

		// setX()
		void setX( float x ) { _x = x; }

		// getY()
		float getY() const { return _y; }

		// setY()
		void setY( float y ) { _y = y; }

		// getZ()
		float getZ() const { return _z; }

		// setZ()
		void setZ( float z ) { _z = z; }

		// operator +
		tPoint operator + ( const tVector& rhs );

		// operator -
		tVector operator - ( const tPoint& rhs );

		// distance()
		float distance( const tPoint& p ) const;

	private:

		float _x;  // x-coordinate of point
		float _y;  // y-coordinate of point
		float _z;  // z-coordinate of point
};

#endif