/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Camera                                                                           *
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

#include "Camera.hpp"

namespace Raytracer
{
    Camera::Camera() : _resolution{1920, 1080}, _position{0, 0, 0}, _rotation{0, 0, 0}, _fieldOfView{70.0}{}

    Camera::Camera(const Resolution& resolution, Math::Point3D position, Math::Point3D rotation, double fieldOfView)
        : _resolution(resolution), _position(position), _rotation(rotation), _fieldOfView(fieldOfView)
    {
    }

    Camera::~Camera(){}

    void Camera::setResolution(const Resolution& resolution)
    {
        _resolution = resolution;
    }

    std::string Camera::getClassName() const
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

    // Setter pour la position
    void Camera::setPosition(const Math::Point3D& position)
    {
        _position = position;
    }

    // Setter pour le champ de vision
    void Camera::setFieldOfView(double fieldOfView)
    {
        _fieldOfView = fieldOfView;
    }

    const Resolution& Camera::getResolution() const
    {
        return _resolution;
    }

    const Math::Point3D& Camera::getPosition() const{
        return _position;
    }

    double Camera::getFieldOfView() const{
        return _fieldOfView;
    }

    std::string Camera::str() const
    {
        std::stringstream ss;
        ss << "<" << this->getClassName() <<
            " at " << std::hex << *this <<
            ": resolution=(" << this->_resolution.width << ", " <<
            this->_resolution.height << "), FOV=" << this->_fieldOfView <<
            ", position=" << this->_position << ", rotation=" <<
            this->_rotation << ">";

        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Camera& obj)
    {
        os << obj.str();
        return os;
    }
}
