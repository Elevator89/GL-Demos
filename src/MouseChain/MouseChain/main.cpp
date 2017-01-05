#include <GL/glfw.h>
#include <vector>
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Algebra/Vec4.h"
#include "Common.Math/Algebra/Matr4.h"
#include "Common.Math/Algebra/Transform.h"
#include "Common.Math/Geometry/Circle.h"
#include "CoordsTransformer.h"
#include "Color.h"
#include "Chains/Caterpillar.h"
#include "ChainDrawers/SolidCircleDrawer.h"
#include "ChainDrawers/OutlineCircleDrawer.h"

bool IsResized( int& width, int& height );
void DrawChain( const Chain& chain, const Color& color );
void DrawCircle( const math::Circle& circle, const Color& color );

int main()
{
	int     width, height;
	int     frame = 0;
	bool    running = true;

	glfwInit();

	GLFWvidmode vidMode;
	glfwGetDesktopMode( &vidMode );

	glfwOpenWindowHint( GLFW_FSAA_SAMPLES, 4 );

	if( !glfwOpenWindow( vidMode.Width, vidMode.Height, vidMode.RedBits, vidMode.GreenBits, vidMode.BlueBits, 0, 0, 0, GLFW_FULLSCREEN ) )
	{
		glfwTerminate();
		return 0;
	}

	CoordsTransformer transformer( math::Transform::Zero(), width, height );
	Caterpillar chain( 10, 0.2f, 0.01f );
	OutlineCircleDrawer drawer( Color( 0.5f, 0.0f, 0.0f ), Color( 1.0f, 0.0f, 0.0f ) );

	glfwSetWindowTitle( "GLFW Application" );

	while( running )
	{
		frame++;

		if( IsResized( width, height ) )
			transformer.Resize( width, height );

		glfwGetWindowSize( &width, &height );

		height = height > 0 ? height : 1;
		glViewport( 0, 0, width, height );

		glClearColor( 0.5f, 0.5f, 0.5f, 1.0f );
		glClear( GL_COLOR_BUFFER_BIT );

		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();

		GLfloat aspect = ( GLfloat )width / ( GLfloat )height;
		GLfloat scale = 1.0f;
		glOrtho( -aspect * scale, aspect * scale, -1.0f * scale, 1.0f * scale, 1.0f, 100.0f );
		gluLookAt( 0.0f, 0.0f, 1.0f,
				   0.0f, 0.0f, 0.0f,
				   0.0f, 1.0f, 0.0f );

		// Draw some rotating garbage
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();

		glLoadIdentity();

		int mouseX;
		int mouseY;
		glfwGetMousePos( &mouseX, &mouseY );

		if( mouseX > width ) mouseX = width;
		if( mouseX < 0.0f ) mouseX = 0.0f;

		if( mouseY > height ) mouseY = height;
		if( mouseY < 0.0f ) mouseY = 0.0f;

		glfwSetMousePos( mouseX, mouseY );

		math::Vec2 mousePos = transformer.ScreenToWorld( mouseX, mouseY );

		chain.Update( mousePos );

		drawer.Draw( chain );

		glfwSwapBuffers();

		// exit if ESC was pressed or window was closed
		running = !glfwGetKey( GLFW_KEY_ESC ) && glfwGetWindowParam( GLFW_OPENED );
	}

	glfwTerminate();

	return 0;
}

bool IsResized( int& width, int& height )
{
	int newWidth;
	int newHeight;
	glfwGetWindowSize( &newWidth, &newHeight );

	bool resized = newWidth != width || newHeight != height;

	if( resized )
	{
		width = newWidth;
		height = newHeight;
	}

	return resized;
}

void DrawChain( const Chain& chain, const Color& color )
{
	std::vector<math::Circle> links = chain.GetLinks();

	for( int i = 0; i < links.size(); ++i )
		DrawCircle( links[i], color );
}
