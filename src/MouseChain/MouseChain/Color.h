#ifndef COLOR_H
#define COLOR_H

struct Color
{
	float R, G, B, A;

	Color();
	Color( float r, float g, float b );
	Color( float r, float g, float b, float a );
	Color( const Color& color );

	~Color();

	Color& operator=( const Color& other );

	static Color Black() { return Color( 0.0f, 0.0f, 0.0f ); }
	static Color Grey() { return Color( 0.5f, 0.5f, 0.5f ); }
	static Color White() { return Color( 1.0f, 1.0f, 1.0f ); }
	static Color Red() { return Color( 1.0f, 0.0f, 0.0f ); }
	static Color Green() { return Color( 0.0f, 1.0f, 0.0f ); }
	static Color Blue() { return Color( 0.0f, 0.0f, 1.0f ); }
};
#endif
