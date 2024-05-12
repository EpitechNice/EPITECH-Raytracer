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

    bool Plane::doesHit(const Math::Ray& other, double distMin, double distMax, hitRecord& record) const
    {
        (void)other;
        (void)distMin;
        (void)distMax;
        (void)record;
        return false;
        // double denominator = other.getDirection().dot(record.normal);
        // return denominator != 0;
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
