//
// tRayTracer.h
//

#ifndef ___TRAYTRACER_H___
#define ___TRAYTRACER_H___

#include "tColor.h"

class tRay;
class tScene;

//
// tRayTracer
//
class tRayTracer
{
	public:

		// constructor()
		tRayTracer();

		// constructor()
		tRayTracer( tScene* scenePtr );

		// destructor()
		~tRayTracer();

		// traceRay()
		tColor traceRay( const tRay& ray, unsigned int depth );

	private:

		tScene* _scenePtr;

};

#endif