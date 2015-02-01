//
// tReflective.h
//

#ifndef ___TREFLECTIVE_H___
#define ___TREFLECTIVE_H___

#include "tMaterial.h"
#include "../BRDFs/tPerfectSpecular.h"
#include "tPhong.h"

//
// tReflective
//
// This class represents a reflective material.
//
class tReflective: public tPhong
{	
	public:
	
		// constructor()
		tReflective();										

		// destructor()
		~tReflective();										
		
		// set_kr()
		void set_kr( const float k ) { 	reflective_brdf->set_kr( k ); }
		
		// set_cr()
		void set_cr( const tColor& c ) { reflective_brdf->set_cr( c ); };
		
		// set_cr()
		void set_cr( const float r, const float g, const float b ) { reflective_brdf->set_cr( r, g, b ); }
		
		// set_cr()
		void set_cr( const float c ) {	reflective_brdf->set_cr( c ); }
		
		// shade()
		tColor shade( tShadeRecord& s );
		
	private:
	
		tPerfectSpecular* reflective_brdf;
};

#endif
