//
// tBDRF.h
//

#ifndef ___TBRDF_H___
#define ___TBRDF_H___

#include "../Game Controller/tColor.h"

class tShadeRecord;
class tVector;

//
// tBDRF
//
class tBRDF
{
	public:
	
		// f()
		virtual tColor f( const tShadeRecord& shadeRecordRef, const tVector& wo, tVector& wi ) const = 0;
		
		// rho()
		virtual tColor rho( const tShadeRecord& shadeRecordRef, const tVector& wo ) const = 0;

};

#endif