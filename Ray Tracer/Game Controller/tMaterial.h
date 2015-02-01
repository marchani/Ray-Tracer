//
// tMaterial.h
//

#ifndef ___TMATERIAL_H___
#define ___TMATERIAL_H___

#include "tColor.h"

class tShadeRecord;

//
// tMaterial
//
class tMaterial
{
	public:

		// constructor()
		tMaterial();

		// constructor()
		tMaterial( tColor& color, float ka, float kd, float ks, float ke );

		// destructor()
		~tMaterial();

		// getColor()
		tColor getColor() const { return _color; }

		// getKa()
		float getKa() const { return _ka; }

		// getKd()
		float getKd() const { return _kd; }

		// getKs()
		float getKs() const { return _ks; }

		// getKe()
		float getKe() const { return _ke; }

		// shade()
		virtual tColor shade( tShadeRecord& sr );

	private:

		tColor _color;

		float _ka;
		float _kd;
		float _ks;
		float _ke;

};

#endif