//
// iBRDF.h
//

#ifndef ___IBRDF_H___
#define ___IBRDF_H___

#include "../Game Controller/tColor.h"

class tShadeRecord;
class tVector;

//
// iBRDF
//
// This is the interface that all classes that implement BDRFs (Bidirectional
// Reflectance Distribution Functions) must implement.
//
// The BRDF is a four-dimensional function that defines how light is reflected
// at an opaque surface.  The function takes a negative incoming light
// direction (w_i), and outgoing direction (w_r), both defined with respect to
// the surface normal (n), and returns the ratio of reflected radiance exiting
// along w_r to the irradiance incident on the surface from direction w_i.
// Each direction w is itself parameterized by azimuth angle phi and zenith
// angle theta, therefore the BRDF as a whole is 4-dimensional.
//
class iBRDF
{
	public:
	
		// f()
		virtual tColor f( const tShadeRecord& shadeRecordRef, const tVector& wo, tVector& wi ) const = 0;
		
		// rho()
		virtual tColor rho( const tShadeRecord& shadeRecordRef, const tVector& wo ) const = 0;

};

#endif