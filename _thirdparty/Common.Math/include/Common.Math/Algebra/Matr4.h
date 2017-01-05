#ifndef MATH_MATR4_H
#define MATH_MATR4_H

#include "Common.Math/Algebra/Vec3.h"
#include "Common.Math/Algebra/Vec4.h"

namespace math
{

	class Matr4
	{
	private:
		float m_array[16];

	public:

		Matr4();
		Matr4( const Matr4& matr );
		Matr4( float array[] );

		Matr4(
			float a11, float a12, float a13, float a14,
			float a21, float a22, float a23, float a24,
			float a31, float a32, float a33, float a34,
			float a41, float a42, float a43, float a44 );

		Matr4( Vec4 col0, Vec4 col1, Vec4 col2, Vec4 col3 );

		inline int GetIndex( int row, int col ) const { return col * 4 + row; }

		inline float& operator()( int row, int col )
		{
			return m_array[GetIndex( row, col )];
		}

		inline const float& operator()( int row, int col ) const
		{
			return m_array[GetIndex( row, col )];
		}

		inline float& operator[]( int index )
		{
			return m_array[index];
		}

		inline const float& operator[]( int index ) const
		{
			return m_array[index];
		}

		inline float* ToArray()
		{
			return m_array;
		}

		float GetDeterminant() const;
		Matr4 GetInverted() const;
		Matr4 GetTransposed() const;

		Matr4 operator += ( const Matr4& m );
		Matr4 operator -= ( const Matr4& m );
		Matr4 operator *= ( const Matr4& m );
		Matr4 operator *= ( float a );
		Matr4 operator /= ( float a );

		static Matr4 Identity()
		{
			return Matr4(
					   1.0f, 0.0f, 0.0f, 0.0f,
					   0.0f, 1.0f, 0.0f, 0.0f,
					   0.0f, 0.0f, 1.0f, 0.0f,
					   0.0f, 0.0f, 0.0f, 1.0f );
		}
	};

	inline Matr4 operator - ( Matr4 m )
	{
		float array[16];

		for( int i = 0; i < 16; ++i )
			array[i] = -m[i];

		return Matr4( array );
	}

	inline Matr4 operator + ( Matr4 a, Matr4 b )
	{
		float array[16];

		for( int i = 0; i < 16; ++i )
			array[i] = a[i] + b[i];

		return Matr4( array );
	}

	inline Matr4 operator - ( Matr4 a, Matr4 b )
	{
		float array[16];

		for( int i = 0; i < 16; ++i )
			array[i] = a[i] - b[i];

		return Matr4( array );
	}

	inline Matr4 operator * ( Matr4 m, float a )
	{
		float array[16];

		for( int i = 0; i < 16; ++i )
			array[i] = m[i] * a;

		return Matr4( array );
	}

	inline Matr4 operator / ( Matr4 m, float a )
	{
		float array[16];

		for( int i = 0; i < 16; ++i )
			array[i] = m[i] / a;

		return Matr4( array );
	}

	inline Matr4 operator * ( Matr4 a, Matr4 b )
	{
		return Matr4(
				   a[0] * b[0] + a[4] * b[1] + a[8] * b[2] + a[12] * b[3],
				   a[1] * b[0] + a[5] * b[1] + a[9] * b[2] + a[13] * b[3],
				   a[2] * b[0] + a[6] * b[1] + a[10] * b[2] + a[14] * b[3],
				   a[3] * b[0] + a[7] * b[1] + a[11] * b[2] + a[15] * b[3],

				   a[0] * b[4] + a[4] * b[5] + a[8] * b[6] + a[12] * b[7],
				   a[1] * b[4] + a[5] * b[5] + a[9] * b[6] + a[13] * b[7],
				   a[2] * b[4] + a[6] * b[5] + a[10] * b[6] + a[14] * b[7],
				   a[3] * b[4] + a[7] * b[5] + a[11] * b[6] + a[15] * b[7],

				   a[0] * b[8] + a[4] * b[9] + a[8] * b[10] + a[12] * b[11],
				   a[1] * b[8] + a[5] * b[9] + a[9] * b[10] + a[13] * b[11],
				   a[2] * b[8] + a[6] * b[9] + a[10] * b[10] + a[14] * b[11],
				   a[3] * b[8] + a[7] * b[9] + a[11] * b[10] + a[15] * b[11],

				   a[0] * b[12] + a[4] * b[13] + a[8] * b[14] + a[12] * b[15],
				   a[1] * b[12] + a[5] * b[13] + a[9] * b[14] + a[13] * b[15],
				   a[2] * b[12] + a[6] * b[13] + a[10] * b[14] + a[14] * b[15],
				   a[3] * b[12] + a[7] * b[13] + a[11] * b[14] + a[15] * b[15] );
	}

	inline Vec4 operator * ( Vec4 v, Matr4 m )
	{
		return Vec4(
				   m[0] * v.X + m[1] * v.Y + m[2] * v.Z + m[3] * v.W,
				   m[4] * v.X + m[5] * v.Y + m[6] * v.Z + m[7] * v.W,
				   m[8] * v.X + m[9] * v.Y + m[10] * v.Z + m[11] * v.W,
				   m[12] * v.X + m[13] * v.Y + m[14] * v.Z + m[15] * v.W );
	}

	inline Vec4 operator * ( Matr4 m, Vec4 v )
	{
		return Vec4(
				   m[0] * v.X + m[4] * v.Y + m[8] * v.Z + m[12] * v.W,
				   m[1] * v.X + m[5] * v.Y + m[9] * v.Z + m[13] * v.W,
				   m[2] * v.X + m[6] * v.Y + m[10] * v.Z + m[14] * v.W,
				   m[3] * v.X + m[7] * v.Y + m[11] * v.Z + m[15] * v.W );
	}
}
#endif
