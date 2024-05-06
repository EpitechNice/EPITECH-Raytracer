/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Object                                                                           *
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

#include "Object.hpp"

namespace Raytracer
{
    std::string AObject::getClassName() const
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

    std::string AObject::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->getClassName() << " at " <<
                std::hex << this <<
                ": origin=" << this->_origin <<
                ", direction=" << this->_direction << ">";
        return ss.str();
    }

    void AObject::setPosition(const Math::Point3D& position)
    {
        this->_origin = position;
    }

    void AObject::setDirection(const Math::Vector3D& direction)
    {
        this->_direction = direction;
    }

    const Math::Point3D& AObject::getPosition() const
    {
        return this->_origin;
    }

    const Math::Vector3D& AObject::getDirection() const
    {
        return this->_direction;
    }

    // ==========

    void APrimitive::setMaterial(Raytracer::Material material)
    {
        this->_material = material;
    }

    const Raytracer::Material& APrimitive::getMaterial() const
    {
        return this->_material;
    }

    std::string APrimitive::str() const
    {
        std::stringstream ss;
        ss <<   "<" << AObject::getClassName() << " at " <<
                std::hex << this <<
                ": origin=" << AObject::_origin <<
                ", direction=" << AObject::_direction <<
                ", material=" << this->_material << ">";
        return ss.str();
    }
}

std::ostream& operator<<(std::ostream& os, const Raytracer::AObject& obj)
{
    os << obj.str();
    return os;
}
