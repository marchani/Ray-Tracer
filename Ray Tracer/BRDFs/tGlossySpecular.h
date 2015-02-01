//
// tGlossySpecular.h
//

#ifndef ___TGLOSSYSPECULAR_H___
#define ___TGLOSSYSPECULAR_H___

#include "tBRDF.h"

//
// tGlossySpecular
//
class tGlossySpecular: public tBRDF
{
	public:
	
		// constructor()
		tGlossySpecular();
		
		// destructor()
		~tGlossySpecular();
		
		// set_ks()
		void set_ks( const float k ) { ks = k; }
		
		// set_exp()
		void set_exp( const float e ) { exp = e; }
		
		// set_cs()
		void set_cs( const tColor& c ) { cs = c; }

		// f()
		tColor f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const;

		// rho()
		tColor rho( const tShadeRecord& sr, const tVector& wo ) const;

	private:
	
		float ks;
		tColor cs;	// specular color
		float exp;  // specular exponent

};

#endif