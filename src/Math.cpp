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

    std::string Point3D::get_class_name() const
    {
        int status = -4;
        const char* name = typeid(*this).name();
        char* _out = abi::__cxa_demangle(name, NULL, NULL, &status);
        if (status != 0 && _out)
            free(_out);
        if (status != 0)
            return std::string(name);
        std::string out(_out);
        free(_out);
        return out;
    }

    std::string Point3D::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->get_class_name() << " at " <<
                std::hex << this <<
                " (" << std::to_string(this->x) << ", " <<
                std::to_string(this->y) << ", " <<
                std::to_string(this->z) << ")>";
        return ss.str();
    }

    Vector3D Point3D::translation(const Point3D& other) const
    {
        return Vector3D(other.x - this->x, other.y - this->y, other.z - this->z);
    }

    Vector3D Point3D::operator+(const Point3D& other) const
    {
        return this->translation(other);
    }

    Vector3D Point3D::operator-(const Point3D& other) const
    {
        return other.translation(*this);
    }

    Point3D& Point3D::operator+=(const Vector3D& other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Point3D& Point3D::operator-=(const Vector3D& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Point3D Point3D::operator+(const Vector3D& other) const
    {
        return Point3D(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    Point3D Point3D::operator-(const Vector3D& other) const
    {
        return Point3D(this->x - other.x, this->y - other.y, this->z - other.z);
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

    // Feels like shit to write the same code again and again, but it's either that or make a "Class" abstract class, as yall don't seem in the mood for a Utils namespace
    // No worries love, I'll make the "Class" abstract for the Zappy
    std::string Vector3D::get_class_name() const
    {
        int status = -4;
        const char* name = typeid(*this).name();
        char* _out = abi::__cxa_demangle(name, NULL, NULL, &status);
        if (status != 0 && _out)
            free(_out);
        if (status != 0)
            return std::string(name);
        std::string out(_out);
        free(_out);
        return out;
    }

    std::string Vector3D::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->get_class_name() << " at " <<
                std::hex << this <<
                " ((" << std::to_string(this->x) << ", " <<
                std::to_string(this->y) << ", " <<
                std::to_string(this->z) << "), length=" <<
                std::to_string(this->length()) << ")>";
        return ss.str();
    }

    double Vector3D::length() const
    {
        return std::cbrt((std::pow(this->x, 3) + std::pow(this->y, 3) + std::pow(this->z, 3)));
    }

    Vector3D Vector3D::normalised()
    {
        double length = this->length();
        return Vector3D(this->x / length, this->y / length, this->z / length);
    }

    Vector3D Vector3D::operator+(const Vector3D& other) const
    {
        return Vector3D(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    Vector3D Vector3D::operator-(const Vector3D& other) const
    {
        return Vector3D(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    Vector3D& Vector3D::operator+=(const Vector3D& other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    Vector3D& Vector3D::operator-=(const Vector3D& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    Point3D Vector3D::operator+(const Point3D& other) const
    {
        return Point3D(other.x + this->x, other.y + this->y, other.z + this->z);
    }

    Point3D Vector3D::operator-(const Point3D& other) const
    {
        return Point3D(other.x - this->x, other.y - this->y, other.z - this->z);
    }

    Vector3D Vector3D::operator*(double value) const
    {
        return Vector3D(this->x * value, this->y * value, this->z * value);
    }

    Vector3D Vector3D::operator/(double value) const
    {
        return Vector3D(this->x / value, this->y / value, this->z / value);
    }

    Vector3D& Vector3D::operator*=(double value)
    {
        this->x *= value;
        this->y *= value;
        this->z *= value;
        return *this;
    }

    Vector3D& Vector3D::operator/=(double value)
    {
        this->x /= value;
        this->y /= value;
        this->z /= value;
        return *this;
    }

    Vector3D Vector3D::cross(const Vector3D& other) const
    {
        double _x =   this->y * other.z - this->z * other.y;
        double _y = -(this->x * other.z - this->z * other.x);
        double _z =   this->x * other.y - this->y * other.x;
        return Vector3D(_x, _y, _z);
    }
}

std::ostream& operator<<(std::ostream& os, const Math::Point3D& obj)
{
    os << obj.str();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Math::Vector3D& obj)
{
    os << obj.str();
    return os;
}