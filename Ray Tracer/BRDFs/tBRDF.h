//
// tBDRF.h
//

#ifndef ___TBRDF_H___
#define ___TBRDF_H___

#include "../Game Controller/tColor.h"
#include "../Game Controller/tVector.h"
#include "../Game Controller/tShadeRecord.h"

class tSampler;

//
// tBDRF
//
class tBRDF
{
	public:
	
		// constructor()
		tBRDF();

		// destructor
		virtual ~tBRDF();

		// set_sampler()
		//void set_sampler(Sampler* sPtr);
		
		virtual tColor f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const;
		
		virtual tColor sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const;
		
		virtual tColor sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi, float& pdf ) const;
		
		virtual tColor rho( const tShadeRecord& sr, const tVector& wo ) const;
		
			
	protected:
	
		tSampler* sampler_ptr;		// for indirect illumination
};

#endif