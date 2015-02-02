//
// tPerfectSpecular.cpp
//

#include "tPerfectSpecular.h"

#include <math.h>
#include "../Game Controller/tShadeRecord.h"


//
// constructor()
//
tPerfectSpecular::tPerfectSpecular()
: kr( 0.0 ),
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
tColor tPerfectSpecular::f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const
{
	float ndotwo = tVector::dot( sr.normal, wo );
	wi = -wo + sr.normal * 2.0 * ndotwo; 
	return ( cr * kr / fabs( tVector::dot( sr.normal, wi ) ) );
}


//
// rho()
//
tColor tPerfectSpecular::rho( const tShadeRecord& sr, const tVector& wo ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}

