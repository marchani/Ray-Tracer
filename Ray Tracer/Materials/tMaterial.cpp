//
// tMaterial.cpp
//

#include "tMaterial.h"

#include "../Game Controller/tShadeRecord.h"
#include "../Game Controller/tScene.h"
#include "../Lights/tLight.h"


//
// Constructor()
//
tMaterial::tMaterial()
{
	_color = tColor();
}


//
// Constructor()
//
tMaterial::tMaterial( tColor& color, float ka, float kd, float ks, float ke )
{
	_color = color;
	_ka = ka;
	_kd = kd;
	_ks = ks;
	_ke = ke;
}


//
// Destructor()
//
tMaterial::~tMaterial()
{
}


//
// shade()
//
tColor tMaterial::shade( tShadeRecord& sr )
{
	return tColor();
}
