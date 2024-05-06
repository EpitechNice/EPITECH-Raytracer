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

    #include "../Math/Vector3D.hpp"
    #include "../Math/Point3D.hpp"

namespace Raytracer
{
    typedef struct resolution_s
    {
        int width;
        int height;
    } Resolution;

    class Camera
    {
        private:
            Resolution _resolution;
            Math::Point3D _position;
            Math::Point3D _rotation;
            double _fieldOfView;

        public:
            Camera();
            Camera(const Resolution& resolution, Math::Point3D position, Math::Point3D rotation, double fieldOfView);
            ~Camera();

            std::string getClassName() const;

            //Setter
            void setResolution(const Resolution& resolution);
            void setPosition(const Math::Point3D& position);
            void setRotation(const Math::Point3D& rotation);
            void setFieldOfView(double fieldOfView);

            // Getter
            const Resolution& getResolution() const;
            const Math::Point3D& getPosition() const;
            double getFieldOfView() const;

            std::string str() const;

            friend std::ostream& operator<<(std::ostream& os, const Camera& obj);
    };
}

#endif // INCLUDED_CAMERA_HPP
