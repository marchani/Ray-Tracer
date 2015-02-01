//
// tPointLight.cpp
//

#include "tPointLight.h"
#include "tPrimitive.h"

//
// constructor()
//
tPointLight::tPointLight()
: tLight(),
  color( 1.0f, 1.0f, 1.0f )
{
}


//
// destructor()
//
tPointLight::~tPointLight()
{
}


//
// L()
//
tColor tPointLight::L( tShadeRecord& s )
{
	return ( color );
}


//
// in_shadow()
//
bool tPointLight::in_shadow( const tRay& ray, const tShadeRecord& sr ) const
{
	float t;
	int num_objects = sr.getScenePtr()->getPrimitives().size();
	float d = location.distance( ray.getOrigin() );

	for( int j = 0; j < num_objects; j++ )
	{
		if( sr.getScenePtr()->getPrimitives().at( j )->shadow_hit( ray, t ) && t < d )
		{
			return true;
		}
	}

	return false;
}
