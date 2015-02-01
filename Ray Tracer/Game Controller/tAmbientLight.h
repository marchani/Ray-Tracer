//
// tAmbientLight.h
//

#ifndef ___TAMBIENTLIGHT_H___
#define ___TAMBIENTLIGHT_H___

#include "tLight.h"
#include "tColor.h"
#include "tPoint.h"

class tShadeRecord;

//
// tAmbientLight
//
class tAmbientLight : public tLight
{
	public:

		// constructor()
		tAmbientLight();

		// constructor()
		tAmbientLight( const tColor& color, const tPoint& position );

		// destructor()
		~tAmbientLight();

		// getColor()
		tColor getColor() const { return _color; }

		// set_color()
		void set_color( const tColor& c ) { _color = c; }

		// getPosition()
		tPoint getPosition() const { return _position; }

		// get_direction()
		tVector get_direction( tShadeRecord& sr ) { return tVector( 0.0f, 0.0f, 0.0f ); }

		// L()
		virtual tColor L( tShadeRecord& s );

	private:

		float ls;

		tColor _color;
		tPoint _position;

};

#endif