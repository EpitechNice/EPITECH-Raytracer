/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Colors                                                                           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Colors.hpp"

namespace Raytracer
{
    Color::Color():
        Matrix({0, 0, 0})
    {}

    Color::Color(std::vector<unsigned int> values)
    {
        if (values.size() != 3)
            throw Exceptions::InvalidSizeError("Awaiting 3 points but got " + values.size(),
                EXCEPTION_INFOS);
        this->_values = {values};
    }

    Color::Color(std::vector<std::vector<unsigned int>> values)
    {
        if (values.size() != 1 || values[0].size() != 3)
            throw Exceptions::InvalidSizeError("Awaiting 1x3 array but got " +
                                               std::to_string(values.size()) + "x" +
                                               std::to_string(values.size() ? values[0].size() : 0),
                EXCEPTION_INFOS);
        this->_values = values;
    }

    Color::Color(unsigned int r, unsigned int g, unsigned int b):
        Matrix({r, g, b})
    {}

    Color::Color(const Color& other):
        Matrix(other._values)
    {}

    Color& Color::operator=(const Color& other)
    {
        this->_values = other._values;
        return *this;
    }

    std::string Color::str() const
    {
        std::stringstream ss;
        ss <<   "<" << this->getClassName() << " at " <<
                std::hex << this <<
                ": color=(" <<
                std::to_string(this->_values[0][0]) << ", " <<
                std::to_string(this->_values[0][1]) << ", " <<
                std::to_string(this->_values[0][2]) << ")>";
        return ss.str();
    }

    Color Color::operator*(double scalar) const
    {
        Color result(*this);
        result._values[0][0] = static_cast<unsigned int>(result._values[0][0] * scalar);
        result._values[0][1] = static_cast<unsigned int>(result._values[0][1] * scalar);
        result._values[0][2] = static_cast<unsigned int>(result._values[0][2] * scalar);
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Raytracer::Color& obj)
    {
        os << obj.str();
        return os;
    }
}

