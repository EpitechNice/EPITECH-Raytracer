/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     Factory                                                                          *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */


#ifndef FACTORY_HPP
    #define FACTORY_HPP

    #include <memory>
    #include "../Abstract/AObject.hpp"
    #include "../Objects/Light.hpp"
    #include "../Objects/Camera.hpp"
    #include "../Primitives/Sphere.hpp"
    #include "../Primitives/Plane.hpp"

namespace Raytracer
{
    class ObjectFactory
    {
        public:
            static std::unique_ptr<Raytracer::Objects::Light> createLight(double ambient = 10.0,
                                                                          double diffuse = 10.0,
                                                                          Math::Point3D origin = Math::Point3D(0, 0, 0),
                                                                          Math::Vector3D direction = Math::Vector3D(0, 0, 0),
                                                                          double angle = 10.0);

            static std::unique_ptr<Raytracer::Camera> createCamera(Raytracer::Resolution resolution = {1920, 1080},
                                                                   Math::Point3D origin = Math::Point3D(0, 0, 0),
                                                                   Math::Vector3D direction = Math::Vector3D(0, 0, 0),
                                                                   double fieldOfView = 90.0);

            static std::unique_ptr<Raytracer::Objects::Sphere> createSphere(Math::Point3D origin = Math::Point3D(0, 0, 0),
                                                                      Raytracer::Material material = Raytracer::Material(),
                                                                      double radius = 1);

            static std::unique_ptr<Raytracer::Objects::Plane> createPlane(Math::Point3D origin = Math::Point3D(0, 1, 0),
                                                                    Raytracer::Material material = Raytracer::Material(),
                                                                    double size = 0.0);
    };
}

#endif