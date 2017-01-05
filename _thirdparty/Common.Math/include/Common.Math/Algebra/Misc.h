#ifndef MATH_MISC_H
#define MATH_MISC_H

namespace math
{

	const float Pi = 3.14159265358979323846f;

	inline float ToDegrees( float radian )
	{
		return radian * 180.0f / float( Pi );
	}

	inline float ToRadians( float degree )
	{
		return degree * float( Pi ) / 180.0f;
	}

	inline float Det2( float a11, float a12, float a21, float a22 )
	{
		return a11 * a22 - a12 * a21;
	}

	inline unsigned ToChar( float val )
	{
		return unsigned( val * 255.0f );
	}

	inline float ToFloat( unsigned val )
	{
		return float( val ) / 255.0f;
	}
}
#endif
