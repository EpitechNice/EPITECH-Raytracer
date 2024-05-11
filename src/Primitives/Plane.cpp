/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Plane                                                                           *
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


#include "Plane.hpp"

namespace Raytracer::Objects
{
    Plane::Plane(Math::Point3D origin, Raytracer::Material material, double size)
    {
        this->_origin = origin;
        this->_material = material;
        this->_size = size;
    }

    double Plane::getSize() const
    {
        return this->_size;
    }

    float Plane::doesHit(const Math::Ray& other) const
    {
        Math::Vector3D oc = this->_origin - other.getOrigin();
        double a = std::pow(other.getDirection().length(), 2);
        double h = other.getDirection().dot(oc);
        double c = std::pow(oc.length(), 2) - pow(this->_size, 2);
        double discriminant = h*h - a*c;
        return (discriminant >= 0);
    }

    Raytracer::Color Plane::hitColor(const Math::Ray& ray) const {
        (void)ray;
        return Raytracer::Color(0, 0, 0);
        //todo
    }

    Math::Ray Plane::bounce(const Math::Ray& other) const
    {
        (void)other;
        return  Math::Ray();
    }

    std::string Plane::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->getClassName() << " at " <<
                std::hex << this <<
                ": origin=(" << this->_origin << "), size=" <<
                this->_size << ", material=" <<
                this->_material << ">";
        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Raytracer::Objects::Plane& obj)
    {
        os << obj.str();
        return os;
    }
}
