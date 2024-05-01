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


#ifndef CAMERA_HPP
    #define CAMERA_HPP

#include "Math.hpp"

namespace Raytracer
{
    class Camera {
    private:
        typedef struct {
            int width;
            int height;
        } resolution;

        Math::Point3D _position;
        Math::Point3D _rotation;
        double _fieldOfView;

    public:
//TODO: width and height to delete for _res
//TODO: make private attribut => Make Setter
        int _width;
        int _height;
        resolution _res;
        Camera(int width, int height, Math::Point3D position, Math::Point3D rotation, double fieldOfView);
        ~Camera();

        // Getter
        int getWidth() const;
        int getHeight() const;
        const Math::Point3D& getPosition() const;

        // Getter pour l'angle de champ
        double getFieldOfView() const;
    };
}

#endif // INCLUDED_CAMERA_HPP
