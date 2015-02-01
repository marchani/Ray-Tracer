//
// tScene.cpp
//

#include "tScene.h"

#include <gl/glut.h>
#include <math.h>
#include "tAmbientLight.h"
#include "tRay.h"
#include "tRayTracer.h"
#include "../Primitives/tPlane.h"
#include "tShadeRecord.h"
#include "../Primitives/tSphere.h"
#include "../tViewPlane.h"
#include "../Materials/tReflective.h"
#include "../Materials/tPhong.h"
#include "tPointLight.h"
#include "../Primitives/tTorus.h"
#include "../Materials/tTransparent.h"

static const float kHugeValue = std::numeric_limits<float>::max();

tScene* tScene::_instancePtr = NULL;

//
// Constructor()
//
tScene::tScene()
{
	_viewPlanePtr = new tViewPlane();
	_rayTracerPtr = new tRayTracer( this );
}


//
// Destructor()
//
tScene::~tScene()
{
	delete _rayTracerPtr;
	_rayTracerPtr = NULL;
}


//
// setInstancePtr()
//
void tScene::setInstancePtr( tScene* instancePtr )
{
	_instancePtr = instancePtr;
}


//
// renderWrapper()
//
void tScene::renderWrapper()
{
	if( _instancePtr != NULL )
	{
		_instancePtr->render();
	}
	else // _instancePtr == NULL
	{
		// Do nothing.
	}
}


//
// build()
//
void tScene::build()
{
	_viewPlanePtr->setHorizontalImageResolution( 900 );
	_viewPlanePtr->setVerticalImageResolution( 600 );
	_viewPlanePtr->setPixelSize( 1.0 );
	_viewPlanePtr->setGamma( 1.0 );

	// Create the ambient light for the scene.
	ambient_ptr = new tAmbientLight();
	( ( tAmbientLight* )ambient_ptr )->set_color( tColor( 1.0f, 1.0f, 1.0f ) );

	// Create a light source and add it to the light sources.
	tPointLight* light1 = new tPointLight();
	( ( tPointLight* )light1 )->set_color( 1.0f, 1.0f, 1.0f );
	light1->set_position( tPoint( 0.0f, 600.0f, 400.0f ) );
	_lights.push_back( light1 );

	// Create a light source and add it to the light sources.
//	tLight* light2 = new tDirectionalLight( tColor( 1.0f, 1.0f, 1.0f ), tPoint( 450.0f, 0.0f, 100.0f ) );
//	_lights.push_back( light2 );

	// Create a sphere primitive and add it to the primitives.
	tReflective* material1 = new tReflective();
	material1->set_cd( tColor( 0.75f, 0.0f, 0.0f ) );
	material1->setKa( 0.25f );
	material1->setKd( 0.5f );
	material1->setKs( 0.5f );
	material1->setExp( 2000.0f );
	//material1->set_ior( 1.5f );
	material1->set_kr( 0.1f );
	//material1->set_kt( 0.9f );
	tSphere* sphere1 = new tSphere( material1, tPoint( 450.0f, 300.0f, 800.0f ), 200.0f );
	_primitives.push_back( sphere1 );

	// Create a sphere primitive and add it to the primitives.
	tReflective* material2 = new tReflective();
	material2->set_cd( tColor( 0.0f, 0.75f, 0.0f ) );
	material2->setKa( 0.25f );
	material2->setKd( 0.5f );
	material2->setKs( 0.15f );
	material2->setExp( 100.0f );
	material2->set_kr( 0.75f );
	tSphere* sphere2 = new tSphere( material2, tPoint( 850.0f, 300.0f, 1400.0f ), 400.0f );
	_primitives.push_back( sphere2 );

	//tTorus* torus1 = new tTorus( material2, tPoint( 450.0f, 300.0f, 800.0f ), 100.0f );
	//_primitives.push_back( torus1 );

	// Create a plane primitive and add it to the primitives.
	tReflective* material3 = new tReflective();
	material3->set_cd( tColor( 0.0f, 0.0f, 0.75f ) );
	material3->setKa( 0.25f );
	material3->setKd( 0.5f );
	material3->setKs( 0.15f );
	material3->setExp( 100.0f );
	material3->set_kr( 0.75f );
	tPlane* plane1 = new tPlane( material3, tPoint( 0.0f, 0.0f, 5000.0f ), tVector( 0.0f, 0.0f, -1.0f ) );
	//_primitives.push_back( plane1 );
}


//
// render()
//
void tScene::render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	// Don't need reshape with these function calls
	GLint width = glutGet( GLUT_WINDOW_WIDTH );
	GLint height = glutGet( GLUT_WINDOW_HEIGHT );

	GLfloat aspectRatio = ( double )width / height;

	// Setup the projection and model view matricies
	glViewport( 0, 0, _viewPlanePtr->getHorizontalImageResolution(), _viewPlanePtr->getVerticalImageResolution() );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0, _viewPlanePtr->getHorizontalImageResolution(), 0, _viewPlanePtr->getVerticalImageResolution(), -1, 1 );

	// Camera position from which the rays are cast.
	tRay ray;
	tPoint cameraPosition = tPoint( 450.0, 300.0, -500.0 );
	ray.setOrigin( cameraPosition );
	
	for( int i = 0; i <= width; i++ )
	{
		for( int j = 0; j <= height; j++ )
		{
			if( ( i == 450 ) && ( j == 300 ) )
			{
				int i = 0;
			}

			// Create a ray from the camera position to the pixel (i, j).
			tVector direction = tPoint( ( float )i, ( float )j, 0.0 ) - cameraPosition;
			direction.normalize();
			ray.setDirection( direction );

			tColor pixel_color = _rayTracerPtr->traceRay( ray, 1 );

			tColor temp = max_to_one( pixel_color );
			
			// Paint pixel (i, j) on the screen.
			glColor3f( temp.getRed(), temp.getGreen(), temp.getBlue() );
			glBegin( GL_POINTS );
			glVertex2f( ( float )i, ( float )j );
			glEnd();
		}
	}

	// We just drew to the back buffer.  Now we need to swap that with the
	// front buffer to show it on screen.
	glutSwapBuffers();
}


//
// add_object()
//
void tScene::add_object( tPrimitive* object_ptr )
{
	_primitives.push_back( object_ptr );
}


//
// hit_bare_bones_objects()
//
tShadeRecord tScene::hit_bare_bones_objects( const tRay& ray )
{
	tShadeRecord sr;
	sr.setScenePtr( this );

	float t;
	tVector normal;
	tPoint local_hit_point;
	float tmin = kHugeValue;
	int num_objects = _primitives.size();

	for( int j = 0; j < num_objects; j++ )
	{
		if( _primitives[ j ]->hit( ray, t, sr ) && ( t < tmin ) )
		{
			sr.hit_an_object = true;
			tmin = t;
			sr.material_ptr = _primitives[ j ]->getMaterial();
			sr.local_hit_point = ray.getOrigin() + ray.getDirection() * t;
			normal = sr.normal;
			local_hit_point = sr.local_hit_point;
		}
	}

	if( sr.hit_an_object )
	{
		//sr.t = tmin;
		sr.normal = normal;
		sr.local_hit_point = local_hit_point;
	}

	return sr;
}


//
// max_to_one()
//
tColor tScene::max_to_one( const tColor& c ) const
{
	float max_value = std::fmax( c.getRed(), std::fmax( c.getGreen(), c.getBlue() ) );

	if( max_value > 1.0 )
	{
		tColor returnVal = tColor( c.getRed() / max_value, c.getGreen() / max_value, c.getBlue() / max_value );

		return returnVal;
	}
	else
	{
		return c;
	}
}


//
// main()
//
int main( int argc, char* argv[] )
{
	// Construct a default scene object.
	tScene scene;
	scene.setInstancePtr( &scene );
	scene.build();

	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
	glutInitWindowPosition ( 200, 200 );
	glutInitWindowSize( 900, 600 );
	glutCreateWindow( "Ray Tracer" );

	// Register the wrappers with the event handlers.
	glutDisplayFunc( tScene::renderWrapper );

	glutMainLoop();

	return 0;
}