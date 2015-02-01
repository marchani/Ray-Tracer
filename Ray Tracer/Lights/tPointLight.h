//
// tPointLight.h
//

#ifndef ___TPOINTLIGHT_H___
#define ___TPOINTLIGHT_H___

#include "tLight.h"
#include "../Game Controller/tVector.h"
#include "../Game Controller/tColor.h"
#include "../Game Controller/tScene.h"
#include "../Game Controller/tShadeRecord.h"

//
// tPointLight
//
class tPointLight : public tLight
{
	public:
	
		// constructor()
		tPointLight();   							

		// destructor()
		virtual	~tPointLight(); 

		// set_color()
		void set_color( const float c )  { color.setRed( c ); color.setGreen( c ); color.setBlue( c ); }

		// set_color()
		void set_color( const tColor& c ) { color = c; };
		
		// set_color()
		void set_color( const float r, const float g, const float b ) { color.setRed( r ); color.setGreen( g ); color.setBlue( b ); }
	
		// getPosition()
		tPoint getPosition() const { return location; }

		// set_position()
		void set_position( const tPoint& position ) { location = position; }
				
		// L()
		virtual tColor L( tShadeRecord& sr );	
		
		// in_shadow()
		bool in_shadow( const tRay& ray, const tShadeRecord& sr ) const;

	private:

		tColor	color;     // color of the light source
		tPoint	location;  // position of the light source
};

#endif