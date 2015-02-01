//
// tLight.h
//

#ifndef ___TLIGHT_H___
#define ___TLIGHT_H___

#include "tColor.h"
#include "tPoint.h"

class tShadeRecord;

//
// tLight
//
class tLight
{
	public:

		// constructor()
		tLight();

		// constructor()
		tLight( const tColor& color, const tPoint& position );

		// destructor()
		~tLight();

		// L()
		virtual tColor L( tShadeRecord& sr );

};

#endif