//
// tTorus.h
//

#ifndef ___TTORUS_H___
#define ___TTORUS_H___

#include "tBBox.h"
#include "tColor.h"
#include "tMaterial.h"
#include "tPoint.h"
#include "tPrimitive.h"

class tRay;
class tShadeRecord;

//
// tTorus
//
class tTorus : public tPrimitive
{
	public:

		// constructor()
		tTorus();

		// constructor()
		tTorus( tMaterial* material, const tPoint& position, float radius );

		// destructor()
		~tTorus();

		// hit()
		bool hit( const tRay& ray, float& tmin, tShadeRecord& sr );

		// shadow_hit()
		bool shadow_hit( const tRay& ray, float& tmin );

	private:

		// compute_normal()
		tVector compute_normal( const tPoint& p ) const;

	private:

		float a; // swept radius
		float b; // tube radius

};

#endif