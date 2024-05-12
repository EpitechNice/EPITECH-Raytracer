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
    Camera::Camera():
        _resolution({1920, 1080}), _fieldOfView(70.0)
    {
        this->_origin = Math::Point3D(0, 0, 0);
        this->_direction = Math::Vector3D(0, 0, 0);
        this->_lowerLeftCorner = Math::Vector3D(-2.0, -1.0, -1.0);
        this->_horizontal = Math::Vector3D(4.0, 0.0, 0.0);
        this->_vertical = Math::Vector3D(0.0, 2.0, 0.0);
    }

    Camera::Camera(Math::Point3D origin, Math::Vector3D direction, Resolution resolution, double fieldOfView):
        _resolution(resolution), _fieldOfView(fieldOfView)
    {
        this->_origin = origin;
        this->_direction = direction;
        this->_lowerLeftCorner = Math::Vector3D(-2.0, -1.0, -1.0);
        this->_horizontal = Math::Vector3D(4.0, 0.0, 0.0);
        this->_vertical = Math::Vector3D(0.0, 2.0, 0.0);
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

    void Camera::setResolution(Resolution resolution)
    {
        _resolution = resolution;
    }

    void Camera::setFieldOfView(double fieldOfView)
    {
        _fieldOfView = fieldOfView;
    }

    const Resolution& Camera::getResolution() const
    {
        return _resolution;
    }

    double Camera::getFieldOfView() const{
        return _fieldOfView;
    }

    const Math::Vector3D Camera::getLowerLeftCorner() const
    {
        return this->_lowerLeftCorner;
    }

    const Math::Vector3D Camera::getHorizontal() const
    {
        return this->_horizontal;
    }

    const Math::Vector3D Camera::getVertical() const
    {
        return this->_vertical;
    }

    Math::Ray Camera::getRay(double u, double v) const
    {
        return {this->_origin, this->_lowerLeftCorner + this->_horizontal * u + this->_vertical * v + this->_origin.toVector3D()};
    }

    std::string Camera::str() const
    {
        std::stringstream ss;
        ss << "<" << this->getClassName() <<
            " at " << std::hex << *this <<
            ": resolution=(" << this->_resolution.width << ", " <<
            this->_resolution.height << "), FOV=" << this->_fieldOfView <<
            ", position=" << this->_origin << ", rotation=" <<
            this->_direction << ">";

        return ss.str();
    }

    std::ostream& operator<<(std::ostream& os, const Camera& obj)
    {
        os << obj.str();
        return os;
    }
}
