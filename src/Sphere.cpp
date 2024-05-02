#include "Sphere.hpp"

namespace Raytracer
{
    Sphere::Sphere(): _radius(1), _origin(Math::Point3D(0, 0, 10))
    {
    }

    Sphere::Sphere(Math::Point3D origin, double radius) : _radius(radius), _origin(origin)
    {
    }

    Sphere::~Sphere()
    {
    }

    //GETTER
    double Sphere::getRadius()
    {
        return this->_radius;
    }
}