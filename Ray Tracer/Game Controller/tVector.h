//
// tVector.h
//

#ifndef ___TVECTOR_H___
#define ___TVECTOR_H___

//
// tVector
//
class tVector
{
	public:

		// constructor()
		tVector();

		// constructor()
		tVector( float x, float y, float z );

		// destructor()
		~tVector();

		// getX()
		float getX() const { return _x; }

		// setX()
		void setX( float x ) { _x = x; }

		// getY()
		float getY() const { return _y; }

		// setY()
		void setY( float y ) { _y = y; }

		// getZ()
		float getZ() const { return _z; }

		// setZ()
		void setZ( float z ) { _z = z; }

		// getMagnitude()
		float getMagnitude() const;

		// operator-
		tVector operator- () const;

		// operator +
		tVector operator + ( const tVector& rhs );

		// operator -
		tVector operator - ( const tVector& rhs ) const;

		// operator *
		tVector operator * ( float scalar ) const;

		// operator /
		tVector operator / ( float scalar );

		// dot()
		static float dot( const tVector& lhs, const tVector& rhs);

		// operator^
		tVector operator^( const tVector& v ) const;

		// normalize()
		void normalize();

	private:

		float _x;  // x-component of vector
		float _y;  // y-component of vector
		float _z;  // z-component of vector
};

#endif