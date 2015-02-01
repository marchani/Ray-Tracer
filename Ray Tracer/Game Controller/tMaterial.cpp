//
// tMaterial.cpp
//

#include "tMaterial.h"

#include "tShadeRecord.h"
#include "tScene.h"
#include "tLight.h"


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
