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
    Plane::Plane(std::shared_ptr<Raytracer::AMaterial> material, Math::Point3D origin, double size)
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
        Math::Vector3D normal = _direction + Math::Vector3D(0, -90, 0);
        double denom = normal.dot(other.getDirection());
    
        if (denom > 1e-6) {
            Math::Vector3D p0l0 = _origin - other.getOrigin();
            double t = p0l0.dot(normal) / denom;
            Math::Point3D p = other.getOrigin() + (other.getDirection());
            Math::Vector3D v = p.translation(_origin);
            double dist = v.dot(v);
            if (t >= 0 && distMin < dist && dist < distMax) {
                record.distance = dist;
                record.intersectionPoint = other.pointAt(record.distance);
                record.normal = normal;
                record.material = this->_material;
                return (true);
            }
        }
        return false;
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
