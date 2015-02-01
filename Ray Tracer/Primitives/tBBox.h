//
// tBBox.h
//

#ifndef ___TBBOX_H___
#define ___TBBOX_H___

#include "../Game Controller/tRay.h"
#include "../Game Controller/tPoint.h"

//
// tBBox
//
class tBBox
{
	public:

		float x0, x1, y0, y1, z0, z1;
		
		tBBox(void);										
						
		tBBox( const float x0, const float x1, const float y0, const float y1, const float z0, const float z1 );

		tBBox(const tPoint p0, const tPoint p1);											

		tBBox(const tBBox& bbox);							

		tBBox& 												
		operator= (const tBBox& rhs);			

		~tBBox(void);										
		
		bool 															
		hit(const tRay& ray) const;
	
		bool
		inside(const tPoint& p) const;
};
	
#endif

