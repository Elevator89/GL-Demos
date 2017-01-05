#include "Color.h"

Color::Color() :
	R( 1.0f ),
	G( 1.0f ),
	B( 1.0f ),
	A( 1.0f )
{}

Color::Color( float r, float g, float b ) :
	R( r ),
	G( g ),
	B( b ),
	A( 1.0f )
{}

Color::Color( float r, float g, float b, float a ) :
	R( r ),
	G( g ),
	B( b ),
	A( a )
{}

Color::Color( const Color& color ) :
	R( color.R ),
	G( color.G ),
	B( color.B ),
	A( color.A )
{}

Color::~Color() {}

Color& Color::operator=( const Color& other ) {
	if( this == &other ) return *this;

	R = other.R;
	G = other.G;
	B = other.B;
	A = other.A;

	return *this;
}
