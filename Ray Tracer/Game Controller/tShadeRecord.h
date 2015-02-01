//
// tShadeRecord.h
//

#ifndef ___TSHADERECORD___
#define ___TSHADERECORD___

#include "tColor.h"
#include "tPoint.h"
#include "tRay.h"

class tMaterial;
class tScene;

//
// tShadeRecord
//
class tShadeRecord
{
	public:

		// constructor()
		tShadeRecord();

		// constructor()
		tShadeRecord( tScene* scenePtr );

		// destructor()
		~tShadeRecord();

		// getPointAtIntersection()
		tPoint getPointAtIntersection() { return _pointAtIntersection; }

		// setPointAtIntersection()
		void setPointAtIntersection( const tPoint& point ) { _pointAtIntersection = point; }

		// getNormalAtIntersection()
		tVector getNormalAtIntersection() { return _normalAtIntersection; }

		// setNormalAtIntersection()
		void setNormalAtIntersection( const tVector& normal ) { _normalAtIntersection = normal; }

		// getScenePtr()
		tScene* getScenePtr() const { return w; }

		// setScenePtr()
		void setScenePtr( tScene* _w ) { w = _w; }

		tColor color;

		bool hit_an_object;                     // did the ray hit an object?
		tMaterial* material_ptr;				// nearest object's material
//		tPoint hit_point;					    // world coordinates of hit point
		tPoint local_hit_point;					// world coordinates of hit point
		tVector normal;							// normal at hit point
		tRay ray;								// for specular highlights
		int depth;                              // recursion depth
		tScene* w;								// world reference for shading

	private:

		bool _primitiveIntersected;     // did the ray hit an object?
		tPoint _pointAtIntersection;    // world coordinates of hit point
		tVector _normalAtIntersection;  // normal at hit point

};

#endif