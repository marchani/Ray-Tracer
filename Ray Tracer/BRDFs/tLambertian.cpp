//
// tLambertian.cpp
//

#include "tLambertian.h"


//
// constructor()
//
tLambertian::tLambertian()
: kd( 0.0 ), 
  cd( 0.0, 0.0, 0.0 )
{
}


//
// destructor()
//
tLambertian::~tLambertian()
{
}


//
// f()
//
tColor tLambertian::f( const tShadeRecord& sr, const tVector& wo, tVector& wi) const
{
	const float invPI = 0.3183098861837906715f;

	tColor returnVal = tColor( cd.getRed() * ( kd * invPI ), cd.getGreen() * ( kd * invPI ), cd.getBlue() * ( kd * invPI ) );

	return returnVal;
}


//
// rho()
//
tColor tLambertian::rho( const tShadeRecord& sr, const tVector& wo ) const
{
	tColor returnVal = tColor( cd.getRed() * kd, cd.getGreen() * kd, cd.getBlue() * kd );

	return returnVal;
}