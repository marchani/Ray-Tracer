//
// tGlossySpecular.cpp
//

#include "tGlossySpecular.h"

#include <math.h>
#include "../Game Controller/tShadeRecord.h"


//
// constructor()
//
tGlossySpecular::tGlossySpecular() 
: ks( 0.0 ),
  cs( 1.0f, 1.0f, 1.0f )
{
}


//
// destructor()
//
tGlossySpecular::~tGlossySpecular()
{
}


//
// f()
//
tColor tGlossySpecular::f( const tShadeRecord& sr, const tVector& viewingDirection, tVector& toLight ) const
{
	// Calculate specular component.
	tColor specularComponent = tColor();

	tVector reflectedRay = -toLight + sr.normal * 2.0f * tVector::dot( toLight, sr.normal );
	float reflectedLightAlongRay = tVector::dot( viewingDirection, reflectedRay );

	if( reflectedLightAlongRay > 0.0f )
	{
		specularComponent = cs * ks * pow( tVector::dot( reflectedRay, viewingDirection ), exp );
	}

	return specularComponent;
}


//
// rho()
//
tColor tGlossySpecular::rho( const tShadeRecord& sr, const tVector& wo) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}