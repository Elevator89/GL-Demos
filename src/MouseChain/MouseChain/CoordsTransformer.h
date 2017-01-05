#ifndef COORDSTRANSFORMER_H
#define COORDSTRANSFORMER_H

#include <stack>
#include "Common.Math/Algebra/Vec2.h"
#include "Common.Math/Algebra/Vec4.h"
#include "Common.Math/Algebra/Matr4.h"
#include "Common.Math/Algebra/Transform.h"

class CoordsTransformer
{
public:
	CoordsTransformer( const math::Transform& camera, int width, int height );
	~CoordsTransformer();

	void Resize( int width, int height );

	math::Transform GetCamera() const;
	void SetCamera( const math::Transform& camera );

	math::Vec2 ScreenToWorld( int screenX, int screenY ) const;
	void WorldToScreen( const math::Vec2& world, int& screenX, int& screenY ) const;

private:
	void Frustum( float left, float right, float top, float bottom );

	math::Vec4 WorldToCam( const math::Vec4& world ) const;
	math::Vec4 CamToProjecion( const math::Vec4& cam ) const;
	void ProjecionToScreen( const math::Vec4& projecion, int& screenX, int& screenY ) const;

	math::Vec4 ScreenToProjecion( int screenX, int screenY ) const;
	math::Vec4 ProjecionToCam( const math::Vec4& projecion ) const;
	math::Vec4 CamToWorld( const math::Vec4& cam ) const;

private:
	math::Matr4 m_projectionMatr;

	int m_width;
	int m_height;

	math::Transform m_camera;
};

#endif
