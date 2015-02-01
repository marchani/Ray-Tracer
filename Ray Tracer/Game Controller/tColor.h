//
// tColor.h
//

#ifndef ___TCOLOR_H___
#define ___TCOLOR_H___

//
// tColor
//
class tColor
{
	public:

		// constructor()
		tColor();

		// constructor()
		tColor( float red, float green, float blue );

		// destructor()
		~tColor();

		// getRed()
		float getRed() const { return _red; }

		// setRed()
		void setRed( float red ) { _red = red; }

		// getGreen()
		float getGreen() const { return _green; }

		// setGreen()
		void setGreen( float green ) { _green = green; }

		// getBlue()
		float getBlue() const { return _blue; }

		// setBlue()
		void setBlue( float blue ) { _blue = blue; }

		// operator +=
		void operator += ( const tColor& rhs );

		// operator +
		tColor operator + ( const tColor& rhs );

		// operator *
		tColor operator * ( float scalar ) const;

		// operator /
		tColor operator / ( float scalar );

		// operator *
		tColor operator * ( const tColor& rhs );

	private:

		float _red;
		float _green;
		float _blue;
};

#endif