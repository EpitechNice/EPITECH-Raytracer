/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Sphere                                                                           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */


#include "Sphere.hpp"

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
                    ": origin=(" << this->_origin << "), radius=" <<
                    this->_radius << ", material=" <<
                    this->_material << ">";
            return ss.str();
        }


         bool Sphere::doesHit(const Math::Ray& other) const
        {
            Math::Vector3D oc = other.getOrigin() - this->_origin;
            double a = other.getDirection().dot(other.getDirection());
            double h = other.getDirection().dot(oc);
            double c = oc.dot(oc) - this->_radius * this->_radius;
            double discriminant = h*h - a*c;
            return (discriminant >= 0);
            // Math::Vector3D oc = this->_origin - other.getOrigin();
            // double a = std::pow(other.getDirection().length(), 2);
            // double h = other.getDirection().dot(oc);
            // double c = std::pow(oc.length(), 2) - pow(this->_radius, 2);
            // double discriminant = h*h - a*c;
            // return (discriminant >= 0);
        }

        Raytracer::Color Sphere::hitColor(const Math::Ray& other) const
        {
            if (!this->doesHit(other))
                throw Exceptions::InvalidRayError("The " + other.str() + " does not hit " + this->str(),
                    EXCEPTION_INFOS);
            return this->_material.getPattern()[0][0];
        }

        Math::Ray Sphere::bounce(const Math::Ray& other) const
        {
            (void)other;
            return Math::Ray();
        }

        std::ostream& operator<<(std::ostream& os, const Sphere& obj)
        {
            os << obj.str();
            return os;
        }
    }
}