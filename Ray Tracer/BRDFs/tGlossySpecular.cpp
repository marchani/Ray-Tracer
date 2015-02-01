//
// tGlossySpecular.cpp
//

#include <math.h>
#include "tGlossySpecular.h"


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
// clone()
//
tGlossySpecular* tGlossySpecular::clone () const
{
	return (new tGlossySpecular(*this));
}


//
// f()
//
tColor tGlossySpecular::f( const tShadeRecord& sr, const tVector& viewingDirection, const tVector& toLight ) const
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
// sample_f()
//
tColor tGlossySpecular::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf ) const
{
	float ndotwo = tVector::dot( sr.normal, wo );
	tVector r = -wo + sr.normal * 2.0 * ndotwo;     // direction of mirror reflection
	
	tVector w = r;
	tVector u = tVector( 0.00424f, 1.0f, 0.00764f ) ^ w;
	u.normalize();
	tVector v = u ^ w;
		
	//tPoint sp = sampler_ptr->sample_hemisphere();
	//wi = sp.getX() * u + sp.getY() * v + sp.getZ() * w;			// reflected ray direction
	
	if( tVector::dot( sr.normal, wi ) < 0.0) 						// reflected ray is below tangent plane
	{
	//	wi = -sp.getX() * u - sp.getY() * v + sp.getZ() * w;
	}

	float phong_lobe = pow( tVector::dot( r, wi ), exp);
	pdf = phong_lobe * ( tVector::dot( sr.normal, wi) );

	return ( cs * ks * phong_lobe);
}


//
// rho()
//
tColor tGlossySpecular::rho( const tShadeRecord& sr, const tVector& wo) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}