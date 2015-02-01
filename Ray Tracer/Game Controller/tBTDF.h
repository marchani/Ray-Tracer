//
// tBTDF.h
//

#ifndef ___TBTDF_H___
#define ___TBTDF_H___

#include "tColor.h"

class tShadeRecord;
class tVector;

//
// tBTDF
//
class tBTDF
{
	public:
	
		// constructor()
		tBTDF();

		// destructor
		virtual ~tBTDF();
		
		// f()
		virtual tColor f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const = 0;
		
		// sample_f()
		virtual tColor sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const = 0;
		
		// rho()		
		virtual tColor rho( const tShadeRecord& sr, const tVector& wo ) const = 0;
		
		// tir()
		virtual bool tir( const tShadeRecord& sr ) const = 0;
			
};

#endif