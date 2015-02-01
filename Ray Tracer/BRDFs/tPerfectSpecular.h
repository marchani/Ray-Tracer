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
		
		// set_cr()
		void set_cr( const float r, const float g, const float b ) { cr.setRed( r ); cr.setGreen( g ); cr.setBlue( b ); }
		
		// set_cr()
		void set_cr( const float c ) { cr.setRed( c ); cr.setGreen( c ); cr.setBlue( c ); }

		// f()
		virtual tColor f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const;
		
		// sample_f()
		virtual tColor sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const;

		// sample_f()
		virtual tColor sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf ) const;

		// rho()
		virtual tColor rho( const tShadeRecord& sr, const tVector& wo ) const;
		
	private:
	
		float kr;   // reflection coefficient
		tColor cr;  // the reflection color
};

#endif