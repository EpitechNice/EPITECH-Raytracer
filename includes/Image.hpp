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

    #include "headers.hpp"
    #include "Exceptions.hpp"

class Image
{
    public:
        // Store a color in a not-too-ram-breaking way
        typedef union {
            unsigned int _value;
            unsigned char colors[4];
        } color_t;

    private:
        std::vector<std::vector<Image::color_t>> _colors;
        std::pair<std::size_t, std::size_t> _size;
    public:
        Image();
        Image(std::pair<std::size_t, std::size_t> size);
        Image(std::pair<std::size_t, std::size_t> size, color_t color);
        Image(std::vector<std::vector<Image::color_t>> colors);
        Image(const Image& other);
        ~Image() = default;

        std::pair<std::size_t, std::size_t> getSize();
        void fill(std::pair<std::size_t, std::size_t> size, Image::color_t color);
        void setPos(std::pair<std::size_t, std::size_t> position, Image::color_t color);
        bool save(std::string filename);

        Image& operator=(const Image& other);
};

#endif
