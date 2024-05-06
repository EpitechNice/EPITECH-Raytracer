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

#include "Point3D.hpp"

namespace Math
{
    Point3D::Point3D():
        Matrix({0, 0, 0})
    {}

    Point3D::Point3D(double x, double y, double z):
        Matrix({x, y, z})
    {}

    Point3D::Point3D(std::vector<double> values)
    {
        if (values.size() != 3)
            throw Exceptions::InvalidSizeError("Awaiting 3 points but got " + values.size(),
                EXCEPTION_INFOS);
        this->_values = {values};
    }

    Point3D::Point3D(std::vector<std::vector<double>> values)
    {
        if (values.size() != 1 || values[0].size() != 3)
            throw Exceptions::InvalidSizeError("Awaiting 1x3 array but got " +
                                               std::to_string(values.size()) + "x" +
                                               std::to_string(values.size() ? values[0].size() : 0),
                EXCEPTION_INFOS);
        this->_values = values;
    }

    Point3D::Point3D(const Point3D& other):
        Matrix(other._values)
    {}

    Vector3D Point3D::translation(const Point3D& other) const
    {
        return Vector3D(other._values[0][0] - this->_values[0][0],
                        other._values[0][1] - this->_values[0][1],
                        other._values[0][2] - this->_values[0][2]);
    }

    Point3D& Point3D::operator=(const Point3D& other)
    {
        this->_values = other._values;
        return *this;
    }

    Vector3D Point3D::operator-(const Point3D& other) const
    {
        return other.translation(*this);
    }

    std::ostream& operator<<(std::ostream& os, const Math::Point3D& obj)
    {
        os << obj.str();
        return os;
    }
}
