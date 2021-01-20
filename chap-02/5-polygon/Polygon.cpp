#include "Polygon.h"
#include "realloc.h"

void Polygon::add_vertex(int x, int y)
{
    const auto old_size = _size;
    ++_size;

    _vertices = realloc(_vertices, old_size, _size);
    _vertices[old_size] = Vertex { x, y };
}

Polygon::~Polygon()
{
    delete[] _vertices;
}

const Vertex& Polygon::get_vertex(size_t idx) const
{
    return _vertices[idx];
}

std::ostream& operator<<(std::ostream& stream, const Polygon& poly)
{
    for (size_t i = 0; i < poly._size; ++i)
    {
        const auto& v = poly._vertices[i];
        stream << "(" << v.first << "," << v.second << ") ";
    }
    return stream;
}