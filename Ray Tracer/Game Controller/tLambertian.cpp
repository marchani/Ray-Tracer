//
// tLambertian.cpp
//

#include "tLambertian.h"
//#include "Constants.h"


//
// constructor()
//
tLambertian::tLambertian()
: tBRDF(),
  kd( 0.0 ), 
  cd( 0.0, 0.0, 0.0 )
{
}


//
// constructor()
//
tLambertian::tLambertian( const tLambertian& lamb )
: tBRDF( lamb ),
  kd( lamb.kd ), 
  cd( lamb.cd )
{
}


//
// operator =
//
tLambertian& tLambertian::operator= ( const tLambertian& rhs )
{
	if( this == &rhs )
	{
		return( *this );
	}

	tBRDF::operator=( rhs );
	
	kd = rhs.kd; 
	cd = rhs.cd;
	
	return (*this);
}


//
// destructor()
//
tLambertian::~tLambertian() {}


//
// clone()
//
tLambertian* tLambertian::clone() const
{
	return ( new tLambertian( *this ) );
}


//
// f()
//
tColor tLambertian::f( const tShadeRecord& sr, const tVector& wo, const tVector& wi) const
{
	const float invPI = 0.3183098861837906715f;

	tColor returnVal = tColor( cd.getRed() * ( kd * invPI ), cd.getGreen() * ( kd * invPI ), cd.getBlue() * ( kd * invPI ) );

	return returnVal;
}


//
// sample_f()
//
/*tColor tLambertian::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf ) const
{
	tVector w = sr.normal;
	tVector v = tVector(0.0034, 1, 0.0071) ^ w;
	v.normalize();
	tVector u = v ^ w;
	
	tPoint sp = sampler_ptr->sample_hemisphere();  
	wi = sp.x * u + sp.y * v + sp.z * w;
	wi.normalize(); 	
	
	pdf = sr.normal * wi * invPI;
	
	return (kd * cd * invPI); 
}*/


//
// rho()
//
tColor tLambertian::rho( const tShadeRecord& sr, const tVector& wo ) const
{
	tColor returnVal = tColor( cd.getRed() * kd, cd.getGreen() * kd, cd.getBlue() * kd );

	return returnVal;
}


