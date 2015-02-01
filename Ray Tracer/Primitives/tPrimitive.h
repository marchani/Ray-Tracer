//
// tPrimitive.h
//

#ifndef ___TPRIMITIVE_H___
#define ___TPRIMITIVE_H___

class tMaterial;
class tRay;
class tShadeRecord;

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