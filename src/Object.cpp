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
                ": position=(" << std::to_string(this->_position.x) << ", " <<
                std::to_string(this->_position.y) << ", " <<
                std::to_string(this->_position.z) << "), material=" <<
                this->_material << ">";
        return ss.str();
    }

    void AObject::setPosition(Math::Point3D position)
    {
        this->_position = position;
    }

    void AObject::setMaterial(Raytracer::Material material)
    {
        this->_material = material;
    }

    const Math::Point3D& AObject::getPosition() const
    {
        return this->_position;
    }

    const Raytracer::Material& AObject::getMaterial() const
    {
        return this->_material;
    }

    std::ostream& operator<<(std::ostream& os, const AObject& obj)
    {
        os << obj.str();
        return os;
    }
}