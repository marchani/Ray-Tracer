//
// tScene.h
//

#ifndef ___TSCENE_H___
#define ___TSCENE_H___

#include <vector>
#include "tColor.h"

class tPointLight;
class tLight;
class tPoint;
class tPrimitive;
class tRay;
class tRayTracer;
class tShadeRecord;
class tVector;
class tViewPlane;

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

		tColor background_color;

		tLight* ambient_ptr;

		// getRayTracerPtr()
		tRayTracer* getRayTracerPtr() const { return _rayTracerPtr; }

	protected:

		static tScene* _instancePtr;

	private:

		tViewPlane* _viewPlanePtr;
		tRayTracer* _rayTracerPtr;

		tColor _ambientLight;

		std::vector< tPrimitive* > _primitives;
		std::vector< tPointLight* > _lights;

};

#endif