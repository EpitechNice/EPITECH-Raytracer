#include "Objects/Sphere.hpp"

namespace Raytracer
{
    namespace Objects
    {
        Sphere::Sphere(Math::Point3D origin, Raytracer::Material material, double radius)
        {
            this->_origin = origin;
            this->_material = material;
            this->_radius = radius;
        }

        std::string Sphere::str() const
        {
            std::stringstream ss;
            ss <<   "<" << this->getClassName() << " at " <<
                    std::hex << this <<
                    ": origin=(" << std::to_string(this->_origin[0][0]) << ", " <<
                    std::to_string(this->_origin[0][1]) << ", " <<
                    std::to_string(this->_origin[0][2]) << "), radius=" <<
                    this->_radius << ", material=" <<
                    this->_material << ">";
            return ss.str();
        }


        //TODO: Simplification of sphere_intersection (source: tuto)
        bool Sphere::doesHit(const Ray& other) const
        {
            Math::Vector3D oc = this->_origin - other.getOrigin();
            double a = std::pow(other.getDirection().length(), 2);
            double h = other.getDirection().dot(oc);
            double c = std::pow(oc.length(), 2) - pow(this->_radius, 2);
            double discriminant = h*h - a*c;
            return (discriminant >= 0);
        }

        Ray Sphere::bounce(const Ray& other) const
        {
            (void)other;
            return Ray();
        }

        std::ostream& operator<<(std::ostream& os, const Sphere& obj)
        {
            os << obj.str();
            return os;
        }
    }
}