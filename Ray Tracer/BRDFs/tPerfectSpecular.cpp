//
// tPerfectSpecular.cpp
//

#include <math.h>
#include "tPerfectSpecular.h"


//
// constructor()
//
tPerfectSpecular::tPerfectSpecular()
: tBRDF(),
  kr( 0.0 ),
  cr( 1.0, 1.0, 1.0 )
{
}


//
// destructor()
//
tPerfectSpecular::~tPerfectSpecular()
{
}


//
// f()
//
tColor tPerfectSpecular::f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}


//
// sample_f()
//
tColor tPerfectSpecular::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi) const
{
	float ndotwo = tVector::dot( sr.normal, wo );
	wi = -wo + sr.normal * 2.0 * ndotwo; 
	return ( cr * kr / fabs( tVector::dot( sr.normal, wi) ) );
}											 // for transparency when ray hits inside surface?, if so it should go in Chapter 24


//
// sample_f()
//
tColor tPerfectSpecular::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf ) const
{
	float ndotwo = tVector::dot( sr.normal, wo );
	wi = -wo + sr.normal * 2.0 * ndotwo; 
	pdf = fabs( tVector::dot( sr.normal, wi ) );
	return ( cr * kr );
}


//
// rho()
//
tColor tPerfectSpecular::rho( const tShadeRecord& sr, const tVector& wo) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}

