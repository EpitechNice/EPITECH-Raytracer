/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Light                                                                            *
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

#include "Light.hpp"

namespace Raytracer::Objects
{
    Light::Light():
        _ambient(0.0), _diffuse(0.0)
    {
        this->_origin = Math::Point3D(0, 0, 0);
        this->_direction = Math::Vector3D(0, 0, 0);
    }

    Light::Light(double ambient, double diffuse, const Math::Point3D& pointLights, const Math::Vector3D& directional, double angle):
        _ambient(ambient), _diffuse(diffuse), _angle(angle)
    {
        this->_origin = pointLights;
        this->_direction = directional;
    }

    Light::~Light()
    {}

    std::string Light::getClassName() const
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

    double Light::getAmbient() const {
        return _ambient;
    }

    double Light::getDiffuse() const {
        return _diffuse;
    }

    std::string Light::str() const
    {
        std::stringstream ss;
        ss << "<" << this->getClassName() << " at " <<
            std::hex << *this << ": position=" << this->_origin <<
            ", direction=" << this->_direction << ", difuse=" <<
            this->_diffuse << ", ambient=" << this->_ambient <<
            ", angle=" << this->_angle << ">";
        
        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Light& obj)
    {
        os << obj.str();
        return os;
    }
}
