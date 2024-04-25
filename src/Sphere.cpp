#include "Sphere.hpp"

namespace Raytracer
{
    namespace Objects
    {
        Sphere::Sphere(Math::Point3D origin, Raytracer::Material material, double radius)
        {
            this->_position = origin;
            this->_material = material;
            this->_radius = radius;
        }

        double Sphere::getRadius() const
        {
            return this->_radius;
        }

        std::string Sphere::str() const
        {
            std::stringstream ss;
            ss <<   "<" << this->getClassName() << " at " <<
                    std::hex << this <<
                    ": position=(" << std::to_string(this->_position.x) << ", " <<
                    std::to_string(this->_position.y) << ", " <<
                    std::to_string(this->_position.z) << "), radius=" <<
                    this->_radius << ", material=" <<
                    this->_material << ">";
            return ss.str();
        }

        bool Sphere::does_hit(const Ray& other) const
        {
            (void)other;
            return false;
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