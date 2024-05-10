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

    bool Plane::doesHit(const Math::Ray& other) const
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


// bool Plane::doesHit(const Math::Ray& other) const
// {
//     // Vector from the ray origin to the plane origin
//     Math::Vector3D rayToPlane = this->_origin - other.getOrigin();

//     // Arbitrarily chosen vector on the plane (e.g., offset by half the size)
//     Math::Vector3D vectorOnPlane(this->_size / 2.0, 0.0, 0.0); // Adjust based on size

//     // Calculate another point on the plane by translating the plane origin by vectorOnPlane
//     Math::Point3D pointOnPlane = this->_origin + vectorOnPlane;

//     // Calculate vector1 and vector2 on the plane
//     Math::Vector3D vector1(pointOnPlane[0][0] - this->_origin[0][0],
//                            pointOnPlane[0][1] - this->_origin[0][1],
//                            pointOnPlane[0][2] - this->_origin[0][2]);

//     Math::Vector3D vector2(vectorOnPlane[0][0] - this->_origin[0][0],
//                            vectorOnPlane[0][1] - this->_origin[0][1],
//                            vectorOnPlane[0][2] - this->_origin[0][2]);

//     // Calculate the plane normal by taking the cross product of vector1 and vector2
//     Math::Vector3D planeNormal = vector1.cross(vector2).normalised();

//     // Calculate the distance from the ray origin to the plane
//     double distance = rayToPlane.dot(planeNormal) / other.getDirection().dot(planeNormal);

//     // Check if the distance is positive (intersection in front of the ray origin)
//     return (distance >= 0.0);
// }

//     Raytracer::Color Plane::hitColor(const Math::Ray& ray) const {
//         if (!this->doesHit(ray))
//             throw Exceptions::InvalidRayError("The " + ray.str() + " does not hit " + this->str(),
//                 EXCEPTION_INFOS);
//         return this->_material.getPattern()[0][0];
//     }