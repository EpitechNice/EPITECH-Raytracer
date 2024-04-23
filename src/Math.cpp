/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Math                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Math.hpp"

namespace Math
{
    Point3D::Point3D()
    {}

    Point3D::Point3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    std::string Point3D::str()
    {
        std::stringstream ss;
        ss << std::hex << this;
        return "<Point3D at " + ss.str() + " (" + std::to_string(this->x) + ", " + std::to_string(this->y), ", " + std::to_string(this->z) + ")>";
    }

    // ==========

    Vector3D::Vector3D()
    {}

    Vector3D::Vector3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    std::string Vector3D::str()
    {
        std::stringstream ss;
        ss << std::hex << this;
        return "<Vector3D at " + ss.str() + " ((" + std::to_string(this->x) + ", " + std::to_string(this->y), ", " + std::to_string(this->z) + "), length=" + std::to_string(this->length()) + ")>";
    }

    inline double Vector3D::length()
    {
        return std::cbrt((std::pow(this->x, 3) + std::pow(this->y, 3) + std::pow(this->z, 3)));
    }
}

std::ostream& operator<<(std::ostream& os, Math::Point3D& obj)
{
    os << obj.str();
    return os;
}