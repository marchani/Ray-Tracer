//
// tViewPlane.h
//

#ifndef ___TVIEWPLANE_H___
#define ___TVIEWPLANE_H___

//
// tViewPlane
//
class tViewPlane
{
	public:

		// constructor()
		tViewPlane();

		// destructor()
		~tViewPlane();

		// getHorizontalImageResolution()
		int getHorizontalImageResolution() const { return _horizontalImageResolution; }

		// setHorizontalImageResolution()
		void setHorizontalImageResolution( int resolution ) { _horizontalImageResolution = resolution; }

		// getVerticalImageResolution()
		int getVerticalImageResolution() const { return _verticalImageResolution; }

		// setVerticalImageResolution()
		void setVerticalImageResolution( int resolution ) { _verticalImageResolution = resolution; }

		// getPixelSize()
		float getPixelSize() { return _pixelSize; }

		// setPixelSize()
		void setPixelSize( float size ) { _pixelSize = size; }

		// setGamma()
		void setGamma( float gamma ) { _gamma = gamma; }

		int num_samples;

	private:

		int _horizontalImageResolution;
		int _verticalImageResolution;
		float _pixelSize;
		float _gamma;
		float _inverseGamma;

};

#endif