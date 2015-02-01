//
// tBRDF.cpp
//

#include "tBRDF.h"

//
// constructor()
//
tBRDF::tBRDF()
{
}


//
// destructor()
//
tBRDF::~tBRDF()
{
}  


//
// f()
//
tColor tBRDF::f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}


//
// sample_f()
//
tColor tBRDF::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}


//
// sample_f()
//
tColor tBRDF::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}


//
// rho()
//
tColor tBRDF::rho( const tShadeRecord& sr, const tVector& wo) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}