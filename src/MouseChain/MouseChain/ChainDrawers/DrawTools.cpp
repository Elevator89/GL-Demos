#include <GL/glfw.h>
#include "DrawTools.h"

void DrawCircle( const math::Circle& circle, const Color& color )
{
	const float segmentsCount = 16.0f;
	const float increment = 2.0f * math::Pi / segmentsCount;
	float theta = 0.0f;

	glColor4f( color.R, color.G, color.B, color.A );
	glBegin( GL_TRIANGLE_FAN );

	for( int i = 0; i < segmentsCount; ++i )
	{
		math::Vec2 v = circle.Center + circle.Radius * math::Vec2( cos( theta ), sin( theta ) );
		glVertex2f( v.X, v.Y );
		theta += increment;
	}

	glEnd();
}
