#include "Ray.hpp"

namespace Raytracer
{
    Ray::Ray():
        _origin(Math::Point3D(0, 0, 0)), _direction(Math::Vector3D(0, 0, 0))
    {}

    Ray::Ray(Math::Point3D origin, Math::Vector3D direction):
        _origin(origin), _direction(direction)
    {}

    void Ray::setOrigin(Math::Point3D origin)
    {
        this->_origin = origin;
    }

    void Ray::setDirection(Math::Vector3D direction)
    {
        this->_direction = direction;
    }

    const Math::Point3D& Ray::getOrigin() const
    {
        return this->_origin;
    }

    const Math::Vector3D& Ray::getDirection() const
    {
        return this->_direction;
    }
}