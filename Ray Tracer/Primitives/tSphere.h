//
// tSphere.h
//

#ifndef ___TSPHERE_H___
#define ___TSPHERE_H___

#include "../Game Controller/tColor.h"
#include "../Materials/tMaterial.h"
#include "../Game Controller/tPoint.h"
#include "tPrimitive.h"

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

		tPoint _position;
		float _radius;

};

#endif