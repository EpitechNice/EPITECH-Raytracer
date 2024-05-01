/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Material                                                                         *
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

#include "Materials/Material.hpp"

namespace Raytracer
{
    Material::Material()
    {
        this->_pattern = Image({10, 10}, Raytracer::Color(DEFAULT_COLOR));
    }

    Material::Material(Image pattern)
    {
        this->_pattern = pattern;
    }

    Material::Material(Raytracer::Color color)
    {
        this->_pattern = Image({10, 10}, color);
    }

    Material::Material(const Material& other)
    {
        this->_pattern = other._pattern;
    }

    std::string Material::getClassName() const
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

    std::string Material::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->getClassName() <<
                " at " << std::hex << this <<
                ": image=" << this->_pattern << ">";
        return ss.str();
    }

    Material& Material::operator=(const Material& other)
    {
        this->_pattern = other._pattern;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Material& obj)
    {
        os << obj.str();
        return os;
    }
}