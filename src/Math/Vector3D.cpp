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

#include "Vector3D.hpp"

namespace Math
{
    Vector3D::Vector3D():
        Matrix({0, 0, 0})
    {}

    Vector3D::Vector3D(double x, double y, double z):
        Matrix({x, y, z})
    {}

    Vector3D::Vector3D(std::vector<double> values)
    {
        if (values.size() != 3)
            throw Exceptions::InvalidSizeError("Awaiting 3 points but got " + values.size(),
                EXCEPTION_INFOS);
        this->_values = {values};
    }

    Vector3D::Vector3D(std::vector<std::vector<double>> values)
    {
        if (values.size() != 1 || values[0].size() != 3)
            throw Exceptions::InvalidSizeError("Awaiting 1x3 array but got " +
                                               std::to_string(values.size()) + "x" +
                                               std::to_string(values.size() ? values[0].size() : 0),
                EXCEPTION_INFOS);
        this->_values = values;
    }

    Vector3D::Vector3D(const Vector3D& other):
        Matrix(other._values)
    {}

    double Vector3D::length() const
    {
        return std::cbrt((std::pow(this->_values[0][0], 3) +
                          std::pow(this->_values[0][1], 3) +
                          std::pow(this->_values[0][2], 3)));
    }

    Vector3D Vector3D::normalised() const
    {
        double length = this->length();
        return Vector3D(this->_values[0][0] / length,
                        this->_values[0][1] / length,
                        this->_values[0][2] / length);
    }

    Vector3D Vector3D::makeFromNormalized(const Vector3D& obj, double length)
    {
        return obj.normalised() * length;
    }

    Vector3D& Vector3D::operator=(const Vector3D& other)
    {
        this->_values = other._values;
        return *this;
    }

    Point3D Vector3D::operator+(const Point3D& other) const
    {
        return Point3D(other[0][0] + this->_values[0][0],
                       other[0][1] + this->_values[0][1],
                       other[0][2] + this->_values[0][2]);
    }

    Vector3D Vector3D::operator+(const Vector3D& other) const
    {
        return Vector3D(other[0][0] + this->_values[0][0],
                       other[0][1] + this->_values[0][1],
                       other[0][2] + this->_values[0][2]);
    }

    Point3D Vector3D::operator-(const Point3D& other) const
    {
        return Point3D(other[0][0] - this->_values[0][0],
                       other[0][1] - this->_values[0][1],
                       other[0][2] - this->_values[0][2]);
    }

    Vector3D Vector3D::operator-(const Vector3D& other) const
    {
        return Vector3D(other[0][0] - this->_values[0][0],
                       other[0][1] - this->_values[0][1],
                       other[0][2] - this->_values[0][2]);
    }

    Vector3D Vector3D::operator+ (double other) const
    {
        return Vector3D(this->_values[0][0] + other,
                        this->_values[0][1] + other,
                        this->_values[0][2] + other);
    }

    Vector3D Vector3D::operator* (double other) const
    {
        return Vector3D(this->_values[0][0] * other,
                        this->_values[0][1] * other,
                        this->_values[0][2] * other);
    }

    Vector3D& Vector3D::operator*= (double other)
    {
        this->_values[0][0] *= other;
        this->_values[0][1] *= other;
        this->_values[0][2] *= other;
        return *this;
    }

    Vector3D Vector3D::operator/ (double other) const
    {
        return Vector3D(this->_values[0][0] / other,
                        this->_values[0][1] / other,
                        this->_values[0][2] / other);
    }

    Vector3D& Vector3D::operator/= (double other)
    {
        this->_values[0][0] /= other;
        this->_values[0][1] /= other;
        this->_values[0][2] /= other;
        return *this;
    }

    double Vector3D::dot(const Vector3D& other) const
    {
        return this->_values[0][0] * other._values[0][0] +
               this->_values[0][1] * other._values[0][1] +
               this->_values[0][2] * other._values[0][2];
    }

    Vector3D Vector3D::cross(const Vector3D& other) const
    {
        double _x =   this->_values[0][1] * other._values[0][2] - this->_values[0][2] * other._values[0][1];
        double _y = -(this->_values[0][0] * other._values[0][2] - this->_values[0][2] * other._values[0][0]);
        double _z =   this->_values[0][0] * other._values[0][1] - this->_values[0][1] * other._values[0][0];
        return Vector3D(_x, _y, _z);
    }

    std::string Vector3D::str() const
    {
        std::stringstream ss;
        ss << "<Math::Vector3D" << " at " <<
            std::hex << *this << ": x=" << this->_values[0][0] <<
            ", y=" << this->_values[0][1] <<
            ", z=" << this->_values[0][2] << ">";

        return ss.str();
    }

    Vector3D Vector3D::translation(const Vector3D& translationVector) const
    {
        return Vector3D(this->_values[0][0] + translationVector._values[0][0],
                        this->_values[0][1] + translationVector._values[0][1],
                        this->_values[0][2] + translationVector._values[0][2]);
    }

    std::ostream& operator<<(std::ostream& os, const Math::Vector3D& obj)
    {
        os << obj.str();
        return os;
    }
}

