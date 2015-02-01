//
// tReflective.cpp
//

#include "tReflective.h"

#include <stdio.h>
#include "tPhong.h"
#include "../BRDFs/tPerfectSpecular.h"
#include "../Game Controller/tScene.h"
#include "../Game Controller/tRayTracer.h"
#include "../Game Controller/tShadeRecord.h"


//
// constructor()
//
tReflective::tReflective()
: tPhong(),
  reflective_brdf( new tPerfectSpecular() )
{
}


//
// destructor()
//
tReflective::~tReflective()
{
	if( reflective_brdf )
	{
		delete reflective_brdf;
		reflective_brdf = NULL;
	}
}


//
// shade()
//
tColor tReflective::shade( tShadeRecord& sr )
{
	tColor L( tPhong::shade( sr ) );  // direct illumination
	
	tVector wo = -sr.ray.getDirection();
	tVector wi;	
	tColor fr = reflective_brdf->f( sr, wo, wi ); 
	tRay reflected_ray( sr.local_hit_point + wi, wi ); 

	L += ( fr * ( sr.getScenePtr()->getRayTracerPtr()->traceRay( reflected_ray, sr.depth + 1 ) ) * tVector::dot( sr.normal, wi ) );
					
	return L;
}