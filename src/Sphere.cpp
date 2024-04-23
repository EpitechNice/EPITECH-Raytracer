#include "Sphere.hpp"

namespace Raytracer
{
    Sphere::Sphere()
    {
        this->_radius = 1;
        this->_origin = Math::Point3D(0, 0, 0);
    }

    Sphere::Sphere(Math::Point3D origin, double radius)
    {
        this->_radius = radius;
        this->_origin = origin;
    }

    Sphere::~Sphere()
    {}

    //GETTER
    Sphere::getRadius()
    {
        return this->_radius;
    }
    

}