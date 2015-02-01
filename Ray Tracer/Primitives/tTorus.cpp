//
// tTorus.cpp
//

#include <math.h>
#include <limits>
#include "../Game Controller/Maths.h"
#include "tTorus.h"
#include "../Game Controller/tShadeRecord.h"

static const float kHugeValue = std::numeric_limits< float >::max();
static const float kEpsilon = 0.0001f;

//
// constructor()
//
tTorus::tTorus()
: tPrimitive(),
  a( 2.0f ),
  b( 0.5f )
{
}


//
// constructor()
//
tTorus::tTorus( tMaterial* material, const tPoint& position, float radius )
: tPrimitive( material ),
  a( 200.0f ),
  b( 50.0f )
{
}
																				

//
// destructor()
//
tTorus::~tTorus()
{
}


//
// compute_normal()
//
tVector tTorus::compute_normal( const tPoint& p ) const
{
	tVector normal;
	float param_squared = a * a + b * b;

	float x = p.getX();
	float y = p.getY();
	float z = p.getZ();
	float sum_squared = x * x + y * y + z * z;
	
	normal.setX( 4.0f * x * (sum_squared - param_squared) );
	normal.setY( 4.0f * y * (sum_squared - param_squared + 2.0f * a * a) );
	normal.setZ( 4.0f * z * (sum_squared - param_squared) );
	normal.normalize();
	
	return (normal);	
}


//
// hit()
//
bool tTorus::hit( const tRay& ray, float& tmin, tShadeRecord& sr )
{
	float x1 = ray.getOrigin().getX();
	float y1 = ray.getOrigin().getY();
	float z1 = ray.getOrigin().getZ();
	
	float d1 = ray.getDirection().getX();
	float d2 = ray.getDirection().getY();
	float d3 = ray.getDirection().getZ();	

	float coeffs[ 5 ];	// coefficient array for the quartic equation
	float roots[ 4 ];	// solution array for the quartic equation
	
	// define the coefficients of the quartic equation
	
	float sum_d_sqrd = d1 * d1 + d2 * d2 + d3 * d3;
	float e	= x1 * x1 + y1 * y1 + z1 * z1 - a * a - b * b;
	float f	= x1 * d1 + y1 * d2 + z1 * d3;
	float four_a_sqrd = 4.0f * a * a;
	
	coeffs[ 0 ] = e * e - four_a_sqrd * ( b * b - y1 * y1 ); 	// constant term
	coeffs[ 1 ] = 4.0f * f * e + 2.0f * four_a_sqrd * y1 * d2;
	coeffs[ 2 ] = 2.0f * sum_d_sqrd * e + 4.0f * f * f + four_a_sqrd * d2 * d2;
	coeffs[ 3 ] = 4.0f * sum_d_sqrd * f;
	coeffs[ 4 ] = sum_d_sqrd * sum_d_sqrd;  					// coefficient of t^4

	// find roots of the quartic equation
	
	int num_real_roots = SolveQuartic( coeffs, roots );
	
	bool	intersected = false;
	float t = kHugeValue;
	
	if (num_real_roots == 0)  // ray misses the torus
		return(false);
	
	// find the smallest root greater than kEpsilon, if any
	// the roots array is not sorted
			
	for (int j = 0; j < num_real_roots; j++)  
		if (roots[j] > kEpsilon) {
			intersected = true;
			if (roots[j] < t)
				t = roots[j];
		}
		
	if(!intersected)
		return (false);
		
	tmin 			 	= t;
	sr.local_hit_point 	= ray.getOrigin() + ray.getDirection() * t;
	sr.normal 		 	= compute_normal(sr.local_hit_point);
	
	return (true);
}


//
// shadow_hit()
//
bool tTorus::shadow_hit( const tRay& ray, float& tmin )
{		
	float x1 = ray.getOrigin().getX(); float y1 = ray.getOrigin().getY(); float z1 = ray.getOrigin().getZ();
	float d1 = ray.getDirection().getX(); float d2 = ray.getDirection().getY(); float d3 = ray.getDirection().getZ();	
	
	float coeffs[5];	// coefficient array for the quartic equation
	float roots[4];	// solution array for the quartic equation
	
	// define the coefficients of the quartic equation
	
	float sum_d_sqrd 	= d1 * d1 + d2 * d2 + d3 * d3;
	float e			= x1 * x1 + y1 * y1 + z1 * z1 - a * a - b * b;
	float f			= x1 * d1 + y1 * d2 + z1 * d3;
	float four_a_sqrd	= 4.0f * a * a;
	
	coeffs[0] = e * e - four_a_sqrd * (b * b - y1 * y1); 	// constant term
	coeffs[1] = 4.0f * f * e + 2.0f * four_a_sqrd * y1 * d2;
	coeffs[2] = 2.0f * sum_d_sqrd * e + 4.0f * f * f + four_a_sqrd * d2 * d2;
	coeffs[3] = 4.0f * sum_d_sqrd * f;
	coeffs[4] = sum_d_sqrd * sum_d_sqrd;  					// coefficient of t^4
	
	// find roots of the quartic equation
	
	int num_real_roots = SolveQuartic(coeffs, roots);
	
	bool	intersected = false;
	float t = kHugeValue;
	
	if (num_real_roots == 0)  // ray misses the torus
		return(false);
	
	// find the smallest root greater than kEpsilon, if any
	// the roots array is not sorted
			
	for (int j = 0; j < num_real_roots; j++)  
		if (roots[j] > kEpsilon) {
			intersected = true;
			if (roots[j] < t)
				t = roots[j];
		}
		
	if(!intersected)
		return (false);
		
	tmin 			 	= t;
	
	return (true);
}