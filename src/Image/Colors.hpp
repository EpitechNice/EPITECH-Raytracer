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

#ifndef INCLUDED_COLORS_HPP
    #define INCLUDED_COLORS_HPP

    #include "headers.hpp"

    #include "../Exceptions/Exceptions.hpp"
    #include "../Math/Matrix.hpp"

namespace Raytracer
{
    class Color: public Math::Matrix<unsigned int>
    {
        public:
            Color();
            Color(std::vector<unsigned int> values);
            Color(std::vector<std::vector<unsigned int>> values);
            Color(unsigned int r, unsigned int g, unsigned int b);
            Color(const Color& other);
            ~Color() = default;

            Color& operator=(const Color& other);

            Color operator*(double scalar) const;

            std::string str() const;
            friend std::ostream& operator<<(std::ostream& os, const Raytracer::Color& obj);
    };
}


#endif
