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
}

Image::Image(const Image& other)
{
    this->_colors = other._colors;
}

std::string Image::getClassName() const
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

std::string Image::str() const
{
    std::pair<std::size_t, std::size_t> size = this->getSize();
    Image::color_t color = this->getMedianColor();
    std::stringstream ss;
    ss <<   "<" << this->getClassName() <<
            " at " << std::hex << this <<
            ": size=(" << size.first <<
            ", " << size.second << "), ratio=" << this->ratio() <<
            ", medium_color=(" <<
            static_cast<int>(color.colors[0]) << ", " <<
            static_cast<int>(color.colors[1]) << ", " <<
            static_cast<int>(color.colors[2]) << ", " <<
            static_cast<int>(color.colors[3]) <<")>";
    return ss.str();
}

Image::color_t Image::getMedianColor() const
{
    Image::color_t out;
    std::pair<std::size_t, std::size_t> size = this->getSize();

    out._value = 0;
    for (std::size_t i = 0; i < size.second; i++) {
        for (std::size_t j = 0; j < size.first; j++) {
            out.colors[0] = ((out.colors[0] * i * j) + (this->_colors[i][j].colors[0])) / ((i * j) + 1);
            out.colors[1] = ((out.colors[1] * i * j) + (this->_colors[i][j].colors[1])) / ((i * j) + 1);
            out.colors[2] = ((out.colors[2] * i * j) + (this->_colors[i][j].colors[2])) / ((i * j) + 1);
            out.colors[3] = ((out.colors[3] * i * j) + (this->_colors[i][j].colors[3])) / ((i * j) + 1);
        }
    }

    return out;
}

std::pair<std::size_t, std::size_t> Image::getSize() const
{
    if (!this->_colors.size())
        return {0, 0};
    else
        return {this->_colors[0].size(), this->_colors.size()};
}

void Image::fill(std::pair<std::size_t, std::size_t> size, Image::color_t color)
{
    this->_colors.clear();
    for (std::size_t i = 0; i < size.second; i++) {
        this->_colors.push_back({});
        for (std::size_t j = 0; j < size.first; j++)
            this->_colors[i].push_back(color);
    }
}

void Image::setPos(std::pair<std::size_t, std::size_t> position, Image::color_t color)
{
    std::pair<std::size_t, std::size_t> size = this->getSize();
    if (position.first >= size.first || position.second >= size.second)
        throw Exceptions::InvalidSizeError("Trying to access position (" +
                                           std::to_string(position.first) + ", " +
                                           std::to_string(position.second) +
                                           ") while image is of size (" +
                                           std::to_string(size.first) + ", " +
                                           std::to_string(size.second) + ").",
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
        std::cerr << Exceptions::FileExtensionWarning("File extension should be \".ppm\", but it's \"" + ext + "\"") << std::endl;

    std::ofstream file(filename);

    if (!(file.is_open() && file.good()))
        return false;

    std::pair<std::size_t, std::size_t> size = this->getSize();

    file << "P3" << std::endl;
    file << "# Generated using our Raytracer" << std::endl;
    file << size.first << " " << size.second << std::endl;
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

double Image::ratio() const
{
    std::pair<std::size_t, std::size_t> size = this->getSize();
    return double(size.first) / double(size.second);
}

Image& Image::operator=(const Image& other)
{
    this->_colors = other._colors;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Image& obj)
{
    os << obj.str();
    return os;
}