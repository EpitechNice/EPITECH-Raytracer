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
    #include "../Material/BuildMaterials.hpp"
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

            static std::vector<std::shared_ptr<Raytracer::AObject>> createLightsSettings(double ambient,
                                                                                         double diffuse,
                                                                                         libconfig::Setting& settings);

            static std::unique_ptr<Raytracer::Camera> createCamera(Raytracer::Resolution resolution = {1920, 1080},
                                                                   Math::Point3D origin = Math::Point3D(0, 0, 0),
                                                                   Math::Vector3D direction = Math::Vector3D(0, 0, 0),
                                                                   double fieldOfView = 90.0);

            static std::unique_ptr<Raytracer::Objects::Sphere> createSphere(std::shared_ptr<Raytracer::AMaterial> material,
                                                                            Math::Point3D origin,
                                                                            double radius);

            static std::vector<std::shared_ptr<Raytracer::APrimitive>> createSpheresSettings(libconfig::Setting& settings);

            static std::unique_ptr<Raytracer::Objects::Plane> createPlane(std::shared_ptr<Raytracer::AMaterial> material,
                                                                          Math::Point3D origin,
                                                                          double size);

            static std::vector<std::shared_ptr<Raytracer::APrimitive>> createPlanesSettings(libconfig::Setting& settings);
    };
}

#endif