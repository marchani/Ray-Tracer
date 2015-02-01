//
// tRayTracer.cpp
//

#include "tRayTracer.h"

#include <gl/glut.h>
#include <stdio.h>
#include "../Materials/tMaterial.h"
#include "tRay.h"
#include "tScene.h"
#include "tShadeRecord.h"
#include "tVector.h"
#include "../Primitives/tSphere.h"

static const int kMaxTraceDepth = 2;

//
// constructor()
//
tRayTracer::tRayTracer()
{
	_scenePtr = new tScene();
}


//
// constructor()
//
tRayTracer::tRayTracer( tScene* scenePtr )
{
	_scenePtr = scenePtr;
}


//
// destructor()
//
tRayTracer::~tRayTracer()
{
	delete _scenePtr;
	_scenePtr = NULL;
}


//
// traceRay()
//
tColor tRayTracer::traceRay( const tRay& ray, unsigned int depth )
{
	tColor returnVal = tColor( 0.0f, 0.0f, 0.0f );

	if( depth > kMaxTraceDepth )
	{
		// Do nothing
	}
	else // depth <= kMaxTraceDepth
	{
		tShadeRecord sr( _scenePtr->hit_bare_bones_objects( ray ) );

		if( sr.hit_an_object )
		{
			sr.depth = depth;
			sr.ray = ray;

			returnVal = sr.material_ptr->shade( sr );
		}
		else
		{
			returnVal = _scenePtr->background_color;
		}
	}

	return returnVal;
}