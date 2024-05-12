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


        bool Sphere::doesHit(const Math::Ray& other, double distMin, double distMax, hitRecord& record) const
        {
            Math::Vector3D oc = other.getOrigin() - this->_origin;
            double a = other.getDirection().dot(other.getDirection());
            double h = oc.dot(other.getDirection());
            double c = oc.dot(oc) - this->_radius * this->_radius;
            double discriminant = h * h - a * c;
            double tmp;

            if (discriminant > 0 ) {
                // Cmon, never write your code twice ;)
                for (int i = 0; i < 2; i++) {
                    tmp = (-h - sqrt(h * h - a * c)) / a;
                    if (tmp > distMin && tmp < distMax) {
                        record.distance = tmp;
                        record.intersectionPoint = other.pointAt(record.distance);
                        record.normal = (record.intersectionPoint - this->_origin) / this->_radius;
                        record.material = this->_material;
                        return true;
                    }
                }
            }
            return false;
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