#include "Ray.hpp"

namespace Math
{
    Ray::Ray():
        _origin(Math::Point3D(0, 0, 0)), _direction(Math::Vector3D(0, 0, 0))
    {}

    Ray::Ray(Math::Point3D origin, Math::Vector3D direction):
        _origin(origin), _direction(direction)
    {}

    std::string Ray::getClassName() const
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

    void Ray::setOrigin(Math::Point3D origin)
    {
        this->_origin = origin;
    }

    void Ray::setDirection(Math::Vector3D direction)
    {
        this->_direction = direction;
    }

    const Math::Point3D& Ray::getOrigin() const
    {
        return this->_origin;
    }

    const Math::Vector3D& Ray::getDirection() const
    {
        return this->_direction;
    }

    std::string Ray::str() const
    {
        std::stringstream ss;
        ss << "<" << this->getClassName() << " at " <<
            std::hex << *this << ": origin=" << this->_origin <<
            ", direction=" << this->_direction << ">";

        return ss.str();
    }

    Math::Point3D Ray::pointAt(double t) const
    {
        return this->_origin + this->_direction * t;
    }

    std::ostream& operator<<(std::ostream& os, const Ray& obj)
    {
        os << obj.str();
        return os;
    }
}