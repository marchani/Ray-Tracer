//
// tBBox.cpp
//

#include "tBBox.h"
//#include "Constants.h"

static const float kEpsilon = 0.0001f;

//
// constructor()
//
tBBox::tBBox()
: x0(-1), x1(1), y0(-1), y1(1), z0(-1), z1(1)
{
}	


// --------------------------------------------------------------------- constructor

tBBox::tBBox (	const float _x0, const float _x1,			
				const float _y0, const float _y1, 
				const float _z0, const float _z1)
	: x0(_x0), x1(_x1), y0(_y0), y1(_y1), z0(_z0), z1(_z1)
{
}


// --------------------------------------------------------------------- constructor

tBBox::tBBox (const tPoint p0, const tPoint p1)
	: x0( p0.getX() ), x1(p1.getX()), y0(p0.getY()), y1(p1.getY()), z0(p0.getZ()), z1(p1.getZ())
{}										


//
// destructor()
//
tBBox::~tBBox()
{
}	


//
// hit()
//
bool tBBox::hit( const tRay& ray ) const
{	
	float ox = ray.getOrigin().getX(); float oy = ray.getOrigin().getY(); float oz = ray.getOrigin().getZ();
	float dx = ray.getDirection().getX(); float dy = ray.getDirection().getY(); float dz = ray.getDirection().getZ();
	
	float tx_min, ty_min, tz_min;
	float tx_max, ty_max, tz_max; 

	float a = 1.0f / dx;
	if (a >= 0) {
		tx_min = (x0 - ox) * a;
		tx_max = (x1 - ox) * a;
	}
	else {
		tx_min = (x1 - ox) * a;
		tx_max = (x0 - ox) * a;
	}
	
	float b = 1.0f / dy;
	if (b >= 0) {
		ty_min = (y0 - oy) * b;
		ty_max = (y1 - oy) * b;
	}
	else {
		ty_min = (y1 - oy) * b;
		ty_max = (y0 - oy) * b;
	}
	
	float c = 1.0f / dz;
	if (c >= 0) {
		tz_min = (z0 - oz) * c;
		tz_max = (z1 - oz) * c;
	}
	else {
		tz_min = (z1 - oz) * c;
		tz_max = (z0 - oz) * c;
	}
	
	double t0, t1;
	
	// find largest entering t value
	
	if (tx_min > ty_min)
		t0 = tx_min;
	else
		t0 = ty_min;
		
	if (tz_min > t0)
		t0 = tz_min;	
		
	// find smallest exiting t value
		
	if (tx_max < ty_max)
		t1 = tx_max;
	else
		t1 = ty_max;
		
	if (tz_max < t1)
		t1 = tz_max;
		
	return (t0 < t1 && t1 > kEpsilon);
}


//
// inside()
//
bool tBBox::inside( const tPoint& p ) const
{
	return ((p.getX() > x0 && p.getX() < x1) && (p.getY() > y0 && p.getY() < y1) && (p.getZ() > z0 && p.getZ() < z1));
}