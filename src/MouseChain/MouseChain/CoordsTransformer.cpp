#include "CoordsTransformer.h"

using math::Vec2;
using math::Vec4;
using math::Matr4;
using math::Transform;

CoordsTransformer::CoordsTransformer( const Transform& camera, int width, int height ) :
	m_projectionMatr(),
	m_width( width ),
	m_height( height ),
	m_camera( camera )
{
	Resize( m_width, m_height );
}

CoordsTransformer::~CoordsTransformer() {}

void CoordsTransformer::Frustum( float left, float right, float top, float bottom )
{
	float r_l = right - left;
	float t_b = top - bottom;

	float near1 = -1.0f;
	float far1 = 1.0f;

	float f_n = far1 - near1;

	m_projectionMatr = Matr4::Identity();
	m_projectionMatr( 0, 0 ) = 2.0f / r_l;
	m_projectionMatr( 1, 1 ) = - 2.0f / t_b;
	m_projectionMatr( 2, 2 ) = - 2.0f / f_n;
	m_projectionMatr( 0, 3 ) = - ( right + left ) / r_l;
	m_projectionMatr( 1, 3 ) = - ( top + bottom ) / t_b;
	m_projectionMatr( 2, 3 ) = - ( far1 + near1 ) / f_n;
	m_projectionMatr( 3, 3 ) = 1.0f;
}

int GetScreenCoord( float c, int size )
{
	return int ( ( c + 1.0f ) * float( size ) / 2.0f );
}

float GetProjectionCoord( int c, int size )
{
	return ( float )( 2 * c ) / ( float ) size - 1.0f;
}

Vec4 CoordsTransformer::WorldToCam( const Vec4& world ) const
{
	return world * m_camera.GetInvMatrix();
}

Vec4 CoordsTransformer::CamToProjecion( const Vec4& cam ) const
{
	return cam * m_projectionMatr;
}

void CoordsTransformer::ProjecionToScreen( const Vec4& projecion, int& screenX, int& screenY ) const
{
	screenX = GetScreenCoord( projecion.X / projecion.W, m_width );
	screenY = GetScreenCoord( -projecion.Y / projecion.W, m_height );
}

Vec4 CoordsTransformer::ScreenToProjecion( int screenX, int screenY ) const
{
	return Vec4( GetProjectionCoord( screenX, m_width ), -GetProjectionCoord( screenY, m_height ), 0.0f, 1.0f );
}

Vec4 CoordsTransformer::ProjecionToCam( const Vec4& projecion ) const
{
	return projecion * m_projectionMatr.GetInverted();
}

Vec4 CoordsTransformer::CamToWorld( const Vec4& cam ) const
{
	return cam * m_camera.GetMatrix();
}

Vec2 CoordsTransformer::ScreenToWorld( int screenX, int screenY ) const
{
	Vec4 projection = ScreenToProjecion( screenX, screenY );
	Vec4 cam = ProjecionToCam( projection );
	Vec4 world = CamToWorld( cam );
	return Vec2( world.X / world.W, world.Y / world.W );
}

void CoordsTransformer::WorldToScreen( const Vec2& world, int& screenX, int& screenY ) const
{
	Vec4 cam = WorldToCam( Vec4( world.X, world.Y, 0.0f, 1.0f ) );
	Vec4 projection = CamToProjecion( cam );
	ProjecionToScreen( projection, screenX, screenY );
}

void CoordsTransformer::Resize( int width, int height )
{
	m_width = width;
	m_height = height;
	float aspect = float( m_width ) / float( m_height );
	Frustum( -aspect, aspect, -1.0f, 1.0f );  //пирамида отсечения сцены, генерация проекционной матрицы
}

Transform CoordsTransformer::GetCamera() const
{
	return m_camera;
}

void CoordsTransformer::SetCamera( const Transform& camera )
{
	m_camera = camera;
}

