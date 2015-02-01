//
// tPhong.cpp
//

#include "tPhong.h"

#include "tLambertian.h"
#include "tShadeRecord.h"
#include "tScene.h"
#include "tPointLight.h"
#include "tLight.h"
#include "tGlossySpecular.h"


//
// Constructor()
//
tPhong::tPhong()
: tMaterial(),
  ambient_brdf( new tLambertian() ),
  diffuse_brdf( new tLambertian() ),
  specular_brdf( new tGlossySpecular() )
{
}


//
// Destructor()
//
tPhong::~tPhong()
{
}


//
// shade()
//
tColor tPhong::shade( tShadeRecord& sr )
{
	tVector wo = -sr.ray.getDirection();
	tColor L = ambient_brdf->rho( sr, wo ) * sr.getScenePtr()->ambient_ptr->L( sr );
	int numLights = sr.getScenePtr()->getLights().size();

	for( int j = 0; j < numLights; j++ )
	{
		tPoint positionOfLight = sr.getScenePtr()->getLights().at( j )->getPosition();
		tVector wi = positionOfLight - sr.local_hit_point;
		wi.normalize();
		float ndotwi = tVector::dot( sr.normal, wi );

		if( ndotwi > 0.0 )
		{
			bool in_shadow = false;

			//if( sr.getScenePtr()->getLights().at( j )->casts_shadows() )
			{
				tRay shadowRay( sr.local_hit_point + wi, wi );
				in_shadow = sr.getScenePtr()->getLights().at( j )->in_shadow( shadowRay, sr );
			}

			if( !in_shadow )
			{
				tColor diffuse_temp = diffuse_brdf->f( sr, wo, wi ) * sr.getScenePtr()->getLights().at( j )->L( sr ) * ndotwi;

				tColor specular_temp = specular_brdf->f( sr, wo, wi ) * sr.getScenePtr()->getLights().at( j )->L( sr ) * ndotwi;

				L += ( diffuse_temp + specular_temp );
			}
		}
	}

	return( L );
}