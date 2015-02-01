//
// tSphere.h
//

#ifndef ___TSPHERE_H___
#define ___TSPHERE_H___

#include "tPrimitive.h"
#include "../Game Controller/tPoint.h"

class tMaterial;
class tRay;
class tShadeRecord;

//
// tSphere
//
class tSphere : public tPrimitive
{
	public:

		// constructor()
		tSphere();

		// constructor()
		tSphere( tMaterial* material, const tPoint& position, float radius );

		// destructor()
		~tSphere();

		// hit()
		bool hit( const tRay& ray, float& tmin, tShadeRecord& sr );

		// shadow_hit()
		bool shadow_hit( const tRay& ray, float& tmin );

	private:

		tPoint _position;  // Center of the sphere
		float _radius;     // Radius of the sphere

};

#endif