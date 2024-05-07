/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Image                                                                            *
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

#ifndef INCLUDED_IMAGE_HPP
    #define INCLUDED_IMAGE_HPP

    #include "configs.hpp"
    #include "headers.hpp"
    #include "Colors.hpp"

    #include "../Math/Matrix.hpp"
    #include "../Exceptions/Exceptions.hpp"

namespace Raytracer
{
    class Image: public Math::Matrix<Raytracer::Color>
    {
        public:
            Image();
            Image(std::pair<std::size_t, std::size_t> size);
            Image(std::pair<std::size_t, std::size_t> size, Raytracer::Color color);
            Image(std::vector<std::vector<Raytracer::Color>> colors);
            Image(const Image& other);
            ~Image() = default;

            std::string str() const;

            Raytracer::Color getMedianColor() const;

            void resize(std::pair<std::size_t, std::size_t> size, Raytracer::Color background);
            bool save(std::string filename);
            double ratio() const;
            void setRatio(double ratio);

            Image& operator=(const Image& other);

            friend std::ostream& operator<<(std::ostream& os, const Image& obj);
    };
}

#endif
