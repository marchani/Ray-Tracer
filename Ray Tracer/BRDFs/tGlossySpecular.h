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
	
		tGlossySpecular(void);
		
		~tGlossySpecular(void);
		
		virtual tGlossySpecular* clone(void) const;
		
		virtual tColor f(const tShadeRecord& sr, const tVector& wo, const tVector& wi) const;
				
		virtual tColor sample_f(const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf) const;
		
		virtual tColor rho(const tShadeRecord& sr, const tVector& wo) const;
		
		// set_ks()
		void set_ks( const float k ) { ks = k; }
		
		// set_exp()
		void set_exp( const float e ) { exp = e; }
		
		// set_cs()
		void set_cs( const tColor& c ) { cs = c; }
		
		// set_cs()
		void set_cs( const float r, const float g, const float b ) { cs.setRed( r ); cs.setGreen( g ); cs.setBlue( b ); }
		
		// set_cs()
		void set_cs( const float c ) { cs.setRed( c ); cs.setGreen( c ); cs.setBlue( c ); }
		
		//void set_sampler(Sampler* sp, const float exp);   			// any type of sampling
		
		void
		set_samples(const int num_samples, const float exp); 	// multi jittered sampling
		
		void
		set_normal(const tVector& n);
		
		
	private:
	
		float ks;
		tColor cs;			// specular color
		float exp; 		// specular exponent
		//Sampler*	sampler;    // for use in sample_f
};

#endif