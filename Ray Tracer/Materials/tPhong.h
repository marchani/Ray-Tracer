//
// tPhong.h
//

#ifndef ___TPHONG_H___
#define ___TPHONG_H___

#include "../Game Controller/tColor.h"
#include "../BRDFs/tLambertian.h"
#include "tMaterial.h"
#include "../BRDFs/tGlossySpecular.h"

class tShadeRecord;

//
// tPhong
//
class tPhong : public tMaterial
{
	public:

		// constructor()
		tPhong();

		// destructor()
		~tPhong();

		// setKa()
		void setKa( float ka ) { ambient_brdf->set_kd( ka ); }

		// setKd()
		void setKd( float kd ) { diffuse_brdf->set_kd( kd ); }

		// setKs()
		void setKs( float ks ) { specular_brdf->set_ks( ks ); }

		// setExp()
		void setExp( float exp ) { specular_brdf->set_exp( exp ); }

		// set_cd()
		void set_cd( const tColor c ) { ambient_brdf->set_cd( c ); diffuse_brdf->set_cd( c ); }

		// shade()
		tColor shade( tShadeRecord& s );

	private:

		tLambertian* ambient_brdf;
		tLambertian* diffuse_brdf;
		tGlossySpecular* specular_brdf;

};

#endif