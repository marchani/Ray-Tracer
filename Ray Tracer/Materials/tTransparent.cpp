//
// tTransparent.cpp
//

#include "tTransparent.h"
#include "../Game Controller/tShadeRecord.h"
#include <stdio.h>
#include "../Game Controller/tScene.h"
#include "../Game Controller/tRayTracer.h"

//
// constructor()
//
tTransparent::tTransparent()
: tPhong(),
  reflective_brdf( new tPerfectSpecular() ),
  specular_btdf( new tPerfectTransmitter() )
{
}


//
// destructor()
//
tTransparent::~tTransparent()
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
tColor tTransparent::shade( tShadeRecord& sr )
{
	tColor L( tPhong::shade( sr ) );
	
	tVector wo = -sr.ray.getDirection();
	tVector wi;
	tColor fr = reflective_brdf->sample_f( sr, wo, wi ); 
	tRay reflected_ray( sr.local_hit_point + wi, wi ); 

	if( specular_btdf->tir( sr ) )
	{
		L += sr.getScenePtr()->getRayTracerPtr()->traceRay( reflected_ray, sr.depth + 1 );
	}
	else
	{
		tVector wt;
		tColor ft = specular_btdf->sample_f( sr, wo, wt );
		tRay transmitted_ray( sr.local_hit_point + wt, wt );

		L += ( fr * ( sr.getScenePtr()->getRayTracerPtr()->traceRay( reflected_ray, sr.depth + 1 ) ) * fabs( tVector::dot( sr.normal, wi ) ) );
		L += ( ft * ( sr.getScenePtr()->getRayTracerPtr()->traceRay( transmitted_ray, sr.depth + 1 ) ) * fabs( tVector::dot( sr.normal, wt ) ) );
	}

	return L;
}