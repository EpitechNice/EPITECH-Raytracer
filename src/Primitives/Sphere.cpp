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


        float Sphere::doesHit(const Math::Ray& other) const
        {
            Math::Vector3D oc = other.getOrigin() - this->_origin;
            double a = other.getDirection().dot(other.getDirection());
            double h = oc.dot(other.getDirection());
            double c = oc.dot(oc) - this->_radius * this->_radius;
            double discriminant = h*h - a*c;
            if (discriminant > 0 ){
                return 1.0;
            } else {
                return (-h - sqrt(discriminant) / (2.0*a));
            }
        }

        Raytracer::Color Sphere::hitColor(const Math::Ray& other) const
        {
            float t = doesHit(other);

            if (t <= 0.0)
                throw Exceptions::InvalidRayError("The " + other.str() + " does not hit " + this->str(), EXCEPTION_INFOS);
            Math::Point3D intersectionPoint = other.getOrigin() + other.getDirection() * t;
            Math::Vector3D normal = (intersectionPoint - this->_origin).normalised();
            Math::Vector3D colorModifier = normal * 0.5 + Math::Vector3D(0.5, 0.5, 0.5);
            Raytracer::Color baseColor = this->_material.getPattern()[0][0];
            Raytracer::Color modifiedColor = baseColor * colorModifier[0][0];
            return modifiedColor;
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