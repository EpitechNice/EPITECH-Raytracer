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
    #include "AObject.hpp"
    #include "../Objects/Light.hpp"
    #include "../Objects/Camera.hpp"
    #include "../Primitives/Sphere.hpp"
    #include "../Primitives/Plane.hpp"

namespace Factory
{
    std::unique_ptr<Raytracer::Objects::Light> createLights(double ambient, double diffuse,
                                                            const Math::Point3D& pointLights,
                                                            const Math::Vector3D& directional,
                                                            double angle);

    std::unique_ptr<Raytracer::Camera> createCameras(const Raytracer::Resolution& resolution,
                                                    Math::Point3D position,
                                                    Math::Point3D rotation,
                                                    double fieldOfView);

    std::unique_ptr<Raytracer::Objects::Sphere> createSpheres(Math::Point3D origin = Math::Point3D(0, 0, 0),
                                                                Raytracer::Material material = Raytracer::Material(),
                                                                double radius = 1);
    std::unique_ptr<Raytracer::Objects::Plane> createPlanes(Math::Point3D origin = Math::Point3D(0, 1, 0),
                                                            Raytracer::Material material = Raytracer::Material(),
                                                            double size = 0.0);
}

#endif