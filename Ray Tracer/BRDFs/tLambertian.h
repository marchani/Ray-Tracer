//
// tLambertian.h
//

#ifndef ___TLAMBERTIAN_H___
#define ___TLAMBERTIAN_H___

#include "tBRDF.h"

class tLambertian: public tBRDF
{
	public:
	
		// constructor()
		tLambertian();
		
		// constructor()
		tLambertian( const tLambertian& lamb );
		
		tLambertian& operator= (const tLambertian& rhs);
		
		virtual ~tLambertian();
		
		virtual tLambertian* clone(void) const;
		
		virtual tColor f(const tShadeRecord& sr, const tVector& wo, const tVector& wi) const;
		
		//virtual tColor sample_f(const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf) const;
		
		// rho()
		virtual tColor rho( const tShadeRecord& sr, const tVector& wo ) const;

		// set_ka()
		void set_ka( const float ka );	
				
		// set_kd()
		void set_kd( const float kd );
		
		// set_cd()
		void set_cd( const tColor& c );
		
		// set_cd()
		void set_cd( const float r, const float g, const float b );
		
		// set_cd()
		void set_cd(const float c);
					
	private:
	
		float		kd;
		tColor 		cd;
};




// -------------------------------------------------------------- set_ka

inline void
tLambertian::set_ka(const float k) {
	kd = k;
}



// -------------------------------------------------------------- set_kd

inline void
tLambertian::set_kd(const float k) {
	kd = k;
}


// -------------------------------------------------------------- set_cd

inline void
tLambertian::set_cd(const tColor& c) {
	cd = c;
}


// ---------------------------------------------------------------- set_cd

inline void													
tLambertian::set_cd(const float r, const float g, const float b) {
	cd.setRed( r );
	cd.setGreen( g );
	cd.setBlue( b );
}


// ---------------------------------------------------------------- set_cd

inline void													
tLambertian::set_cd(const float c)
{
	cd.setRed( c );
	cd.setGreen( c );
	cd.setBlue( c );
}

#endif