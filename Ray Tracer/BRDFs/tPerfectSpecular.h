//
// tPerfectSpecular.h
//

#ifndef ___TPERFECTSPECULAR_H___
#define ___TPERFECTSPECULAR_H___

#include "tBRDF.h"

//
// tPerfectSpecular
//
class tPerfectSpecular: public tBRDF
{
	public:
	
		// constructor()
		tPerfectSpecular();
		
		// destructor()
		~tPerfectSpecular();
		
		// set_kr()
		void set_kr( const float k ) { kr = k; }

		// set_cr()
		void set_cr( const tColor& c ) { cr = c; }
		
		// f()
		virtual tColor f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const;
		
		// rho()
		virtual tColor rho( const tShadeRecord& sr, const tVector& wo ) const;
		
	private:
	
		float kr;   // reflection coefficient
		tColor cr;  // the reflection color
};

#endif