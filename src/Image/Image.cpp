/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Image                                                                            *
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

#include "Image.hpp"

namespace Raytracer
{
    Image::Image():
        Matrix()
    {}

    Image::Image(std::pair<std::size_t, std::size_t> size)
    {
        this->fill(size, Raytracer::Color(DEFAULT_COLOR));
        Raytracer::Color endValue(0x45, 0xa8, 0xff);
        Raytracer::Color   startValue(0x9d, 0xd1, 0xff);
        Raytracer::Color currentValue;

        for (std::size_t j = 0; j < size.second; j++) {
            double a = double(j) / double(size.second);
            currentValue = Raytracer::Color((1.0 - a) * startValue[0][0] + a * endValue[0][0],
                                            (1.0 - a) * startValue[0][1] + a * endValue[0][1],
                                            (1.0 - a) * startValue[0][2] + a * endValue[0][2]);
            for (std::size_t i = 0; i < size.first; i++)
                this->set({i, j}, currentValue);
        }
    }

    Image::Image(std::pair<std::size_t, std::size_t> size, Raytracer::Color color)
    {
        this->fill(size, color);
    }

    Image::Image(std::vector<std::vector<Raytracer::Color>> colors):
        Matrix(colors)
    {}

    Image::Image(const Image& other):
        Matrix(other._values)
    {}

    std::string Image::str() const
    {
        std::pair<std::size_t, std::size_t> size = this->getSize();
        Raytracer::Color color = this->getMedianColor();
        std::stringstream ss;
        ss <<   "<" << this->getClassName() <<
                " at " << std::hex << this <<
                ": size=(" << size.first <<
                ", " << size.second << "), ratio=" << this->ratio() <<
                ", medium_color=(" <<
                color[0][0] << ", " <<
                color[0][1] << ", " <<
                color[0][2] << ")>";
        return ss.str();
    }

    Raytracer::Color Image::getMedianColor() const
    {
        Raytracer::Color out;
        std::pair<std::size_t, std::size_t> size = this->getSize();

        for (std::size_t i = 0; i < size.second; i++) {
            for (std::size_t j = 0; j < size.first; j++) {
                out.set({0, 0}, ((out[0][0] * i * j) + (this->_values[i][j][0][0])) / ((i * j) + 1));
                out.set({0, 1}, ((out[0][1] * i * j) + (this->_values[i][j][0][1])) / ((i * j) + 1));
                out.set({0, 2}, ((out[0][2] * i * j) + (this->_values[i][j][0][2])) / ((i * j) + 1));
            }
        }

        return out;
    }

    void Image::resize(std::pair<std::size_t, std::size_t> size, Raytracer::Color background)
    {
        std::vector<std::vector<Raytracer::Color>> colors = this->_values;

        this->fill(size, background);
        for (std::size_t i = 0; i < colors.size(); i++) {
            for (std::size_t j = 0; j < colors[i].size(); j++) {
                try {
                    this->set({j, i}, colors[i][j]);
                } catch (const Exceptions::Exception& e)
                {}
            }
        }
    }

    bool Image::save(std::string filename)
    {
        std::size_t ext_pos = filename.find_last_of('.');
        std::string ext;
        if (ext_pos == std::string::npos)
            ext = "";
        else
            ext = filename.substr(ext_pos);

        if (ext != ".ppm")
            std::cerr << Exceptions::FileExtensionWarning("File extension should be \".ppm\", but it's \"" + ext + "\"") << std::endl;

        std::ofstream file(filename);

        if (!(file.is_open() && file.good()))
            return false;

        std::pair<std::size_t, std::size_t> size = this->getSize();

        file << "P3" << std::endl;
        file << "# Generated using our Raytracer" << std::endl;
        file << size.first << " " << size.second << std::endl;
        file << "255" << std::endl;
        for (std::size_t i = 0; i < size.second; i++) {
            file << "# ===== /LINE " << i << "/ =====" << std::endl;
            for (std::size_t j = 0; j < size.first; j++)
                file << this->_values[j][size.second - i - 1][0][0] << "\t" <<
                        this->_values[j][size.second - i - 1][0][1] << "\t" <<
                        this->_values[j][size.second - i - 1][0][2] << "\t" << std::endl;
        }
        return true;
    }

    double Image::ratio() const
    {
        std::pair<std::size_t, std::size_t> size = this->getSize();
        return double(size.first) / double(size.second);
    }

    void Image::setRatio(double ratio)
    {
        std::pair<std::size_t, std::size_t> size = this->getSize();
        int height = int(size.first / ratio);
        Raytracer::Color color(DEFAULT_COLOR);

        height = (height < 1) ? 1 : height;
        this->resize({size.first, height}, color);
    }

    Image& Image::operator=(const Image& other)
    {
        this->_values = other._values;
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Raytracer::Image& obj)
    {
        os << obj.str();
        return os;
    }
}