//
// tSphere.cpp
//

#include "tSphere.h"

#include <math.h>
#include "tRay.h"
#include "tShadeRecord.h"


//
// Constructor()
//
tSphere::tSphere()
{
}


//
// Constructor()
//
tSphere::tSphere( tMaterial* material, const tPoint& position, float radius )
: tPrimitive( material ),
  _position( position ),
  _radius( radius )
{
}


//
// Destructor()
//
tSphere::~tSphere()
{
}


//
// hit()
//
bool tSphere::hit( const tRay& ray, float& tmin, tShadeRecord& sr )
{
	tVector temp = ray.getOrigin() - _position;
	float a = tVector::dot( ray.getDirection(), ray.getDirection() );
	float b = 2 * tVector::dot( temp, ray.getDirection() );
	float c = tVector::dot( temp, temp ) - pow( _radius, 2 );
	float disc = pow( b, 2 ) - ( 4 * a * c );

	if( disc < 0.0 )
	{
		return false;
	}
	else
	{
		float e = sqrt( disc );
		float denom = 2.0f * a;
		float t = ( -b - e ) / denom;   // smaller root

		if( t > 0.0001 )
		{
			tmin = t;
			sr.normal = ( temp + ray.getDirection() * t ) / _radius;
			sr.local_hit_point = ray.getOrigin() + ( ray.getDirection() * t );
			return true;
		}

		t = ( -b + e ) / denom;   // larger root

		if( t > 0.0001 )
		{
			tmin = t;
			sr.normal = ( temp + ray.getDirection() * t ) / _radius;
			sr.local_hit_point = ray.getOrigin() + ray.getDirection() * t;
			return true;
		}

		return false;
	}
}


//
// shadow_hit()
//
bool tSphere::shadow_hit( const tRay& ray, float& tmin )
{
	float t;
	tVector temp = ray.getOrigin() - _position;
	float a = tVector::dot( ray.getDirection(), ray.getDirection() );
	float b = 2 * tVector::dot( temp, ray.getDirection() );
	float c = tVector::dot( temp, temp ) - pow( _radius, 2 );
	float disc = pow( b, 2 ) - ( 4 * a * c );

	if( disc < 0.0 )
	{
		return false;
	}
	else
	{
		float e = ( float )sqrt( disc );
		float denom = 2.0f * a;
		t = ( -b - e ) / denom;   // smaller root

		if( t > 0.1 )
		{
			tmin = t;
			return true;
		}

		t = ( -b + e ) / denom;   // larger root

		if( t > 0.1 )
		{
			tmin = t;
			return true;
		}

		return false;
	}
}