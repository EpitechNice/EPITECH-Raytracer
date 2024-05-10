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

    Point3D Point3D::operator+(const Vector3D& other) const
    {
        return Point3D(this->_values[0][0] + other[0][0],
                       this->_values[0][1] + other[0][1],
                       this->_values[0][2] + other[0][2]);
    }

    Vector3D Point3D::operator-(const Point3D& other) const
    {
        return other.translation(*this);
    }

    Point3D Point3D::operator-(const Math::Vector3D& other) const
    {
        double dx = other[0][0];
        double dy = other[0][1];
        double dz = other[0][2];
        double newX = this->_values[0][0] - dx;
        double newY = this->_values[0][1] - dy;
        double newZ = this->_values[0][2] - dz;
        return Point3D(newX, newY, newZ);
    }

    Math::Vector3D Math::Point3D::normalised() const {
        // Calcul de la longueur du vecteur représenté par le point
        double length = std::sqrt(_values[0][0] * _values[0][0] +
                                  _values[0][1] * _values[0][1] +
                                  _values[0][2] * _values[0][2]);

        // Normalisation du vecteur (division de chaque composante par la longueur)
        double xNormalized = _values[0][0] / length;
        double yNormalized = _values[0][1] / length;
        double zNormalized = _values[0][2] / length;

        // Création et retour d'un nouveau vecteur normalisé
        return Math::Vector3D(xNormalized, yNormalized, zNormalized);
    }

    std::string Point3D::str() const
    {
        std::stringstream ss;
        ss << "<Math::Point3D" << " at " <<
            std::hex << *this << ": x=" << this->_values[0][0] <<
            ", y=" << this->_values[0][1] <<
            ", z=" << this->_values[0][2] << ">";

        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Math::Point3D& obj)
    {
        os << obj.str();
        return os;
    }
}
