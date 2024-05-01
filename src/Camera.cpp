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
    Camera::Camera(int width, int height, Math::Point3D position, Math::Point3D rotation, double fieldOfView)
        : _position(position), _rotation(rotation), _fieldOfView(fieldOfView), _width(width), _height(height){}

    Camera::~Camera(){}

    int Camera::getWidth() const{
        return _width;
    }

    int Camera::getHeight() const{
        return _height;
    }

    const Math::Point3D& Camera::getPosition() const{
        return _position;
    }

    double Camera::getFieldOfView() const{
        return _fieldOfView;
    }
}
