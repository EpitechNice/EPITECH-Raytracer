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
    }

    Camera::Camera(Math::Point3D origin, Math::Vector3D direction, Resolution resolution, double fieldOfView):
        _resolution(resolution), _fieldOfView(fieldOfView)
    {
        this->_origin = origin;
        this->_direction = direction;
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

    // Setter pour le champ de vision
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

    Math::Vector3D Camera::computeRayDirection(double x, double y) const
    {
        //auto aspectRatio = _resolution.width / _resolution.height;
        // double halfHeight = std::tan(_fieldOfView * 0.5 * M_PI / 180.0);
        // double halfWidth = aspectRatio * halfHeight;

        // Math::Vector3D right = _direction.cross(Math::Vector3D(0, 1, 0)).normalised();
        // Math::Vector3D up = right.cross(_direction).normalised();
        // Math::Vector3D rayDirection = _direction + (right * (2.0 * x * halfWidth)) + (up * (2.0 * y * halfHeight));

        Math::Vector3D rayDirection(0, 0, 0);
        Math::Point3D screenPosition = _origin;
        screenPosition += _direction;
        double worldUnit = _fieldOfView / 100;

        screenPosition -= Math::Vector3D(_resolution.width * worldUnit, _resolution.height * worldUnit, -2) / 2;

        screenPosition += Math::Vector3D(x * worldUnit, y * worldUnit, 0);
        rayDirection = _origin.translation(screenPosition);

        return rayDirection.normalised();
    }

}
