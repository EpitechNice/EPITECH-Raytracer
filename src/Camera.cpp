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
}
