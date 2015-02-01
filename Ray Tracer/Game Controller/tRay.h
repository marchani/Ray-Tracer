//
// tRay.h
//

#ifndef ___TRAY_H___
#define ___TRAY_H___

#include "tPoint.h"
#include "tVector.h"

//
// tRay
//
class tRay
{
	public:

		// constructor()
		tRay();

		// constructor()
		tRay( const tPoint& origin, const tVector& direction );

		// destructor()
		~tRay();

		// getOrigin()
		tPoint getOrigin() const { return _origin; }

		// setOrigin()
		void setOrigin( const tPoint& origin ) { _origin = origin; }

		// getDirection()
		tVector getDirection() const { return _direction; }

		// setDirection()
		void setDirection( const tVector& direction ) { _direction = direction; }

	private:

		tPoint _origin;
		tVector _direction;

};

#endif