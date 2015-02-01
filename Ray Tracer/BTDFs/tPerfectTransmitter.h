//
// tPerfectTransmitter.h
//

#ifndef ___TPERFECTTRANSMITTER_H___
#define ___TPERFECTTRANSMITTER_H___

#include "tBTDF.h"

//
// tPerfectTransmitter
//
class tPerfectTransmitter : public tBTDF
{
	public:
	
		// constructor()
		tPerfectTransmitter();

		// destructor
		virtual ~tPerfectTransmitter();
		
		// set_kt()
		void set_kt( const float k ) { kt = k; }

		// set_ior()
		void set_ior( const float _ior ) { ior = _ior; }

		// f()
		tColor f( const tShadeRecord& sr, const tVector& wo, const tVector& wi ) const;
		
		// sample_f()
		tColor sample_f( const tShadeRecord& sr, const tVector& wo, tVector& wi ) const;
		
		// rho()		
		tColor rho( const tShadeRecord& sr, const tVector& wo ) const;
		
		// tir()
		bool tir( const tShadeRecord& sr ) const;

	private:

		float kt;
		float ior;

};

#endif