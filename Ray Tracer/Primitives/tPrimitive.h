//
// tPrimitive.h
//

#ifndef ___TPRIMITIVE_H___
#define ___TPRIMITIVE_H___

#include "../Game Controller/tColor.h"

class tMaterial;
class tShadeRecord;
class tRay;

//
// tPrimitive
//
class tPrimitive
{
	public:

		// constructor()
		tPrimitive();

		// constructor()
		tPrimitive( tMaterial* material );

		// destructor()
		~tPrimitive();

		// get_color()
		tColor get_color() const { return tColor( 1.0f, 1.0f, 0.0f ); }

		// getMaterial()
		tMaterial* getMaterial() const { return _material; }

		// hit()
		virtual bool hit( const tRay& ray, float& tmin, tShadeRecord& sr ) = 0;

		// shadow_hit()
		virtual bool shadow_hit( const tRay& ray, float& tmin ) = 0;

	private:

		tMaterial* _material;

};

#endif