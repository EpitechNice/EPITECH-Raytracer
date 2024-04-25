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
    public:
        Image();
        Image(std::pair<std::size_t, std::size_t> size);
        Image(std::pair<std::size_t, std::size_t> size, color_t color);
        Image(std::vector<std::vector<Image::color_t>> colors);
        Image(const Image& other);
        ~Image() = default;

        std::string getClassName() const;
        std::string str() const;

        Image::color_t getMedianColor() const;

        std::pair<std::size_t, std::size_t> getSize() const;
        void fill(std::pair<std::size_t, std::size_t> size, Image::color_t color);
        void setPos(std::pair<std::size_t, std::size_t> position, Image::color_t color);
        void resize(std::pair<std::size_t, std::size_t> size, Image::color_t background);
        bool save(std::string filename);
        double ratio() const;
        void setRatio(double ratio);

        Image& operator=(const Image& other);
};

std::ostream& operator<<(std::ostream& os, const Image& obj);

#endif
