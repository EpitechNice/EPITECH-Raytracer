#include "Ray.hpp"

namespace Raytracer
{
    Ray::Ray()
    {
        this->_origin = Math::Point3D(0, 0, 0);
        this->_direction = Math::Vector3D(0, 0, 0);
    }

    Ray::Ray(Math::Point3D origin, Math::Vector3D direction)
    {
        this->_origin = origin;
        this->_direction = direction;
    }

    Ray::~Ray()
    {}
}