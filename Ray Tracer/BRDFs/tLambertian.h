//
// tLambertian.h
//

#ifndef ___TLAMBERTIAN_H___
#define ___TLAMBERTIAN_H___

#include "tBRDF.h"

//
// tLambertian
//
class tLambertian: public tBRDF
{
	public:
	
		// constructor()
		tLambertian();
		
		// destructor()
		virtual ~tLambertian();

		// set_ka()
		void set_ka( const float ka ) { kd = ka; }
				
		// set_kd()
		void set_kd(const float _kd) { kd = _kd; }
		
		// set_cd()
		void set_cd( const tColor& c ) { cd = c; };

		// f()
		virtual tColor f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const;
		
		// rho()
		virtual tColor rho( const tShadeRecord& sr, const tVector& wo ) const;
					
	private:
	
		float kd;
		tColor cd;

};

#endif