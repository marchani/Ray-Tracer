//
// tPlane.cpp
//

#include "tPlane.h"

#include "tRay.h"
#include "tShadeRecord.h"


//
// Constructor()
//
tPlane::tPlane()
{
}


//
// Constructor()
//
tPlane::tPlane( tMaterial* material, const tPoint& position, const tVector& normal )
: tPrimitive( material ),
  _position( position ),
  _normal( normal )
{
}


//
// Destructor()
//
tPlane::~tPlane()
{
}


//
// hit()
//
bool tPlane::hit( const tRay& ray, float& tmin, tShadeRecord& sr )
{
	float t = tVector::dot( ( _position - ray.getOrigin() ), _normal ) / tVector::dot( ray.getDirection(), _normal );

	if( t > 0.0001 /* kEpsilon*/ )
	{
		tmin = t;
		sr.normal = _normal;
		sr.local_hit_point = ray.getOrigin() + ray.getDirection() * t;

		return true;
	}
	else // distance > kEpsilon
	{
		return false;
	}
}


//
// shadow_hit()
//
bool tPlane::shadow_hit( const tRay& ray, float& tmin )
{
	float t = tVector::dot( ( _position - ray.getOrigin() ), _normal ) / tVector::dot( ray.getDirection(), _normal );

	if( t > 0.0001 /* kEpsilon*/ )
	{
		tmin = t;
		return true;
	}
	else // distance > kEpsilon
	{
		return false;
	}
}