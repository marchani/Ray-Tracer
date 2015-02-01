//
// tPerfectTransmitter.cpp
//

#include <math.h>
#include "tPerfectTransmitter.h"
#include "../Game Controller/tShadeRecord.h"

//#include "tBTDF.h"

//
// constructor()
//
tPerfectTransmitter::tPerfectTransmitter()
{
}


//
// destructor
//
tPerfectTransmitter::~tPerfectTransmitter()
{
}


//
// f()
//
tColor tPerfectTransmitter::f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}


//
// sample_f()
//
tColor tPerfectTransmitter::sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wt ) const
{
	tVector n = sr.normal;
	float cos_thetai = tVector::dot( n, wo );
	float eta = ior;

	if( cos_thetai < 0.0f )
	{
		cos_thetai = -cos_thetai;
		n = -n;
		eta = 1.0f / eta;
	}

	float temp = 1.0f - ( 1.0f - cos_thetai * cos_thetai ) / (eta * eta );
	float cos_theta2 = sqrt( temp );
	wt = -wo / eta - ( n * ( cos_theta2 - cos_thetai / eta ) );

	return(  tColor( 1.0f, 1.0f, 1.0f ) * kt / ( eta * eta ) ) / fabs( tVector::dot( sr.normal, wt ) );
}


//
// rho()
//
tColor tPerfectTransmitter::rho( const tShadeRecord& sr, const tVector& wo ) const
{
	return tColor( 0.0f, 0.0f, 0.0f );
}


//
// tir()
//
bool tPerfectTransmitter::tir( const tShadeRecord& sr ) const
{
	tVector wo = -sr.ray.getDirection();
	float cos_thetai = tVector::dot( sr.normal, wo );
	float eta = ior;

	if( cos_thetai < 0.0f )
	{
		eta = 1.0f / eta;
	}

	return( ( 1.0f - (1.0f - cos_thetai * cos_thetai ) / ( eta * eta ) ) < 0.0f );
}