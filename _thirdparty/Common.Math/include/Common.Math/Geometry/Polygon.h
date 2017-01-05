#ifndef MATH_POLYGON_H
#define MATH_POLYGON_H

#include "Common.Collections/ICollection.h"
#include "Common.Collections/Vector.h"
#include "Common.Collections/IterableOperations.h"
#include "Common.Math/Algebra/Vec2.h"

namespace math
{

	class Polygon
	{
	public:
		Polygon() {}

		Polygon( const Polygon& polygon )
		{
			polygon.GetVertices( m_vertices );
		}

		~Polygon() {}

		inline Polygon& operator=( const Polygon& polygon )
		{
			polygon.GetVertices( m_vertices );
			return *this;
		}

		inline void AddVertex( const Vec2& vertex ) { m_vertices.Add( vertex ); }
		inline void RemoveVertex( const Vec2& vertex ) { m_vertices.Remove( vertex ); }

		inline void GetVertices( collections::ICollection<Vec2>& vertices ) const
		{
			for( collections::IteratorPtr<Vec2> verticesIter( m_vertices ); !verticesIter.IsEnd(); verticesIter.Next() )
				vertices.Add( verticesIter.Current() );
		}

		inline Vec2& operator[]( int index )
		{
			return m_vertices[index];
		}

		inline const Vec2& operator[]( int index ) const
		{
			return m_vertices[index];
		}

		inline int GetVerticesCount() const { return m_vertices.GetLength(); }

	private:
		collections::Vector<Vec2> m_vertices;
	};

	inline bool operator == ( const Polygon& a, const Polygon& b )
	{
		int countA = a.GetVerticesCount();
		int countB = b.GetVerticesCount();

		if( countA != countB ) return false;

		for( int i = 0; i < countA; ++i )
		{
			if( a[i] != b[i] ) return false;
		}

		return true;
	}

	inline bool operator != ( const Polygon& a, const Polygon& b )
	{
		return !( a == b );
	}
}
#endif
