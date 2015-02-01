//
// tScene.h
//

#ifndef ___TSCENE_H___
#define ___TSCENE_H___

#include <vector>
#include "tColor.h"
#include "tShadeRecord.h"

class tLight;
class tPointLight;
class tPrimitive;
class tRayTracer;
class tRay;

//
// tScene
//
class tScene
{
	public:

		// constructor()
		tScene();

		// destructor()
		~tScene();

		// setInstancePtr()
		void setInstancePtr( tScene* instancePtr );

		// getRayTracerPtr()
		tRayTracer* getRayTracerPtr() const { return _rayTracerPtr; }

		// getBackgroundColor()
		tColor getBackgroundColor() const { return background_color; }

		// getAmbientLightPtr()
		tLight* getAmbientLightPtr() const { return ambient_ptr; }

		// getLights()
		std::vector< tPointLight* > getLights() const { return _lights; }

		// getPrimitives()
		std::vector< tPrimitive* > getPrimitives() const { return _primitives; }

		// renderWrapper()
		static void renderWrapper();

		// build()
		void build();

		// render()
		void render();

		// add_object()
		void add_object( tPrimitive* object_ptr );

		// hit_bare_bones_objects()
		tShadeRecord hit_bare_bones_objects( const tRay& ray );

		// max_to_one()
		tColor max_to_one( const tColor& c ) const;

	protected:

		static tScene* _instancePtr;

	private:

		tRayTracer* _rayTracerPtr;               // Pointer to the ray tracer.
		tColor background_color;                 // Background color of the scene.
		tLight* ambient_ptr;                     // Pointer to the ambient light in the scene.

		std::vector< tPrimitive* > _primitives;  // List of primitive objects in the scene.
		std::vector< tPointLight* > _lights;     // List of light sources in the scene.

};

#endif