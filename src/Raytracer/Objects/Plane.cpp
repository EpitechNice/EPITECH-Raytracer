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


#include "Objects/Primitives/Plane.hpp"

namespace Raytracer::Objects
{
    Plane::Plane(Math::Point3D origin, Raytracer::Material material, double size)
    {
        this->_origin = origin;
        this->_material = material;
        this->_size = size;
    }

    std::string Plane::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->getClassName() << " at " <<
                std::hex << this <<
                ": origin=(" << std::to_string(this->_origin[0][0]) << ", " <<
                std::to_string(this->_origin[0][1]) << ", " <<
                std::to_string(this->_origin[0][2]) << "), size=" <<
                this->_size << ", material=" <<
                this->_material << ">";
        return ss.str();
    }

    bool Plane::doesHit(const Ray& other) const
    {
        Math::Vector3D oc = this->_origin - other.getOrigin();
        double a = std::pow(other.getDirection().length(), 2);
        double h = other.getDirection().dot(oc);
        double c = std::pow(oc.length(), 2) - pow(this->_size, 2);
        double discriminant = h*h - a*c;
        return (discriminant >= 0);
    }

    Ray Plane::bounce(const Ray& other) const
    {
        (void)other;
        return Ray();
    }
}

std::ostream& operator<<(std::ostream& os, const Raytracer::Objects::Plane& obj)
{
    os << obj.str();
    return os;
}