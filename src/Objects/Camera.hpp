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

    #include "../Abstract/AObject.hpp"
    #include "../Math/Vector3D.hpp"
    #include "../Math/Point3D.hpp"
    #include <cmath>

namespace Raytracer
{
    typedef struct resolution_s
    {
        int width;
        int height;
    } Resolution;

    class Camera: public Raytracer::AObject
    {
        private:
            Resolution _resolution;
            double _fieldOfView;
            Math::Vector3D _lowerLeftCorner;
            Math::Vector3D _horizontal;
            Math::Vector3D _vertical;

        public:
            Camera();
            Camera(Math::Point3D origin, Math::Vector3D direction, Resolution resolution, double fieldOfView);
            ~Camera() = default;

            std::string getClassName() const;

            void setResolution(Resolution resolution);
            void setFieldOfView(double fieldOfView);

            const Resolution& getResolution() const;
            double getFieldOfView() const;
            const Math::Vector3D getLowerLeftCorner() const;
            const Math::Vector3D getHorizontal() const;
            const Math::Vector3D getVertical() const;
            Math::Ray getRay(double u, double v) const;

            std::string str() const;

            friend std::ostream& operator<<(std::ostream& os, const Camera& obj);
    };
}

#endif // INCLUDED_CAMERA_HPP
