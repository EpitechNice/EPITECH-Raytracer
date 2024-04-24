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

Image::Image()
{
    this->_colors = {};
}

Image::Image(std::pair<std::size_t, std::size_t> size)
{
    Image::color_t color;
    color._value = 0;
    this->fill(size, color);
}

Image::Image(std::pair<std::size_t, std::size_t> size, Image::color_t color)
{
    this->fill(size, color);
}

Image::Image(std::vector<std::vector<Image::color_t>> colors)
{
    this->_colors = colors;
    this->getSize();
}

Image::Image(const Image& other)
{
    this->_colors = other._colors;
    this->getSize();
}

std::pair<std::size_t, std::size_t> Image::getSize()
{
    if (!this->_colors.size())
        this->_size = {0, 0};
    else
        this->_size = {this->_colors[0].size(), this->_colors.size()};
    return this->_size;
}

void Image::fill(std::pair<std::size_t, std::size_t> size, Image::color_t color)
{
    this->_colors.clear();
    for (std::size_t i = 0; i < size.second; i++) {
        this->_colors.push_back({});
        for (std::size_t j = 0; j < size.first; j++)
            this->_colors[i].push_back(color);
    }
    this->getSize();
}

void Image::setPos(std::pair<std::size_t, std::size_t> position, Image::color_t color)
{
    if (position.first >= this->_size.first || position.second >= this->_size.second)
        throw Exceptions::InvalidSizeError("Trying to access position (" +
                                           std::to_string(position.first) + ", " +
                                           std::to_string(position.second) +
                                           ") while image is of size (" +
                                           std::to_string(this->_size.first) + ", " +
                                           std::to_string(this->_size.second) + ").",
            FILE_INFOS);
    this->_colors[position.second][position.first] = color;
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
        std::cerr << Exceptions::FileExtensionWarning("File extension should be \"ppm\", but it's \"" + ext + "\"") << std::endl;

    std::ofstream file(filename);

    if (!(file.is_open() && file.good()))
        return false;

    file << "P3" << std::endl;
    file << "# Generated using our Raytracer" << std::endl;
    file << this->_size.first << " " << this->_size.second << std::endl;
    file << "255" << std::endl;
    for (std::size_t i = 0; i < this->_colors.size(); i++) {
        file << "# ===== START LINE " << i << " =====" << std::endl;
        for (std::size_t j = 0; j < this->_colors[i].size(); j++)
            file << static_cast<int>(this->_colors[i][j].colors[0]) << "\t" <<
                    static_cast<int>(this->_colors[i][j].colors[1]) << "\t" <<
                    static_cast<int>(this->_colors[i][j].colors[2]) << "\t" << std::endl;
                    // this->_colors[i][j].colors[3] << "\t";
                    // Seems like alpha ain't used in PPM format
        file << "# ===== END LINE " << i << " =====" << std::endl;
    }
    return true;
}

Image& Image::operator=(const Image& other)
{
    this->_colors = other._colors;
    this->getSize();
    return *this;
}