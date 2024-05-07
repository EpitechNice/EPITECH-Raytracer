/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     Factory                                                                       *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "ObjectFactory.hpp"

namespace Raytracer
{
    std::unique_ptr<Raytracer::Objects::Light> ObjectFactory::createLight(double ambient,
                                                            double diffuse,
                                                            Math::Point3D pointLights,
                                                            Math::Vector3D directional,
                                                            double angle)
    {
        return std::make_unique<Raytracer::Objects::Light>(ambient, diffuse, pointLights, directional, angle);
    }

    std::unique_ptr<Raytracer::Camera> ObjectFactory::createCamera(Raytracer::Resolution resolution,
                                                                   Math::Point3D origin,
                                                                   Math::Vector3D direction,
                                                                   double fieldOfView)
    {
        return std::make_unique<Raytracer::Camera>(origin, direction, resolution, fieldOfView);
    }

    std::unique_ptr<Raytracer::Objects::Sphere> ObjectFactory::createSphere(Math::Point3D origin,
                                                                Raytracer::Material material,
                                                                double radius)
    {
        return std::make_unique<Raytracer::Objects::Sphere>(origin, material, radius);
    }

    std::unique_ptr<Raytracer::Objects::Plane> ObjectFactory::createPlane(Math::Point3D origin,
                                                                Raytracer::Material material,
                                                                double size)
    {
        return std::make_unique<Raytracer::Objects::Plane>(origin, material, size);
    }
}
