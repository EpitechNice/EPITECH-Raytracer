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
#include "../Abstract/AMaterial.hpp"

namespace Raytracer
{
    namespace Objects
    {
        Sphere::Sphere(std::shared_ptr<Raytracer::AMaterial> material, Math::Point3D origin, double radius)
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
                tmp = (-h - sqrt(h * h - a * c)) / a;
                if (tmp > distMin && tmp < distMax) {
                    record.distance = tmp;
                    record.intersectionPoint = other.pointAt(record.distance);
                    record.normal = (record.intersectionPoint - this->_origin) / this->_radius;
                    record.material = this->_material;
                    record.color = record.material.get()->getPattern()[0][0];
                    return true;
                }
                tmp = (-h + sqrt(h * h - a * c)) / a;
                if (tmp > distMin && tmp < distMax) {
                    record.distance = tmp;
                    record.intersectionPoint = other.pointAt(record.distance);
                    record.normal = (record.intersectionPoint - this->_origin) / this->_radius;
                    record.material = this->_material;
                    record.color = record.material.get()->getPattern()[0][0];
                    return true;
                }
            }
            return false;
        }

//TODO : variables
        Raytracer::Color Sphere::hitColor(const Math::Ray& other) const
        {
            double t = 1;
            // double distMin;
            // double distMax;
            // hitRecord rec;
//
            // if (doesHit(other) <= 0.0)
                // throw Exceptions::InvalidRayError("The " + other.str() + " does not hit " + this->str(), EXCEPTION_INFOS);
            Math::Point3D intersectionPoint = other.getOrigin() + other.getDirection() * t;
            Math::Vector3D normal = (intersectionPoint - this->_origin).normalised();
            Math::Vector3D colorModifier = normal * 0.5 + Math::Vector3D(0.5, 0.5, 0.5);
            Raytracer::Color baseColor = this->_material.get()->getPattern()[0][0];
            Raytracer::Color modifiedColor = baseColor * colorModifier[0][0];
            return modifiedColor;
        }

        Math::Vector3D Sphere::generateRandomPoint()
        {
            Math::Vector3D point;

            do {
                point = Math::Vector3D(drand48(),drand48(),drand48()) * 2.0 - Math::Vector3D(1.0, 1.0, 1.0);
            } while (point.dot(point) >= 1.0);

            return point;
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