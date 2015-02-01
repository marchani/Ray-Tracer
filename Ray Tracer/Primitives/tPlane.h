//
// tPlane.h
//

#ifndef ___TPLANE_H___
#define ___TPLANE_H___

#include "tPrimitive.h"
#include "../Game Controller/tPoint.h"

class tMaterial;
class tRay;
class tShadeRecord;
class tVector;

//
// tPlane
//
class tPlane : public tPrimitive
{
	public:

		// constructor()
		tPlane();

		// constructor()
		tPlane( tMaterial* material, const tPoint& position, const tVector& normal );

		// destructor()
		~tPlane();

		// hit()
		bool hit( const tRay& ray, float& tmin, tShadeRecord& sr );

		// shadow_hit()
		bool shadow_hit( const tRay& ray, float& tmin );

	private:

		tPoint _position;  // Point through which the plane passes.
		tVector _normal;   // Normal to the plane

};

#endif