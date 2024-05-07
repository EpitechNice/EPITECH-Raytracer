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

#include "Factory.hpp"
#include "../Objects/Light.hpp"
#include "../Objects/Camera.hpp"
#include "../Primitives/Sphere.hpp"
#include "../Primitives/Plane.hpp"

namespace Factory
{
    std::unique_ptr<Raytracer::Objects::Light> createLights(double ambient, double diffuse,
                                                            const Math::Point3D& pointLights,
                                                            const Math::Vector3D& directional,
                                                            double angle)
    {
        return std::make_unique<Raytracer::Objects::Light>(ambient, diffuse, pointLights, directional, angle);
    }

    std::unique_ptr<Raytracer::Camera> createCameras(const Raytracer::Resolution& resolution,
                                                     Math::Point3D position,
                                                     Math::Point3D rotation,
                                                     double fieldOfView)
    {
        return std::make_unique<Raytracer::Camera>(resolution, position, rotation, fieldOfView);
    }

    std::unique_ptr<Raytracer::Objects::Sphere> createSpheres(Math::Point3D origin,
                                                              Raytracer::Material material,
                                                              double radius)
    {
        return std::make_unique<Raytracer::Objects::Sphere>(origin, material, radius);
    }

    std::unique_ptr<Raytracer::Objects::Plane> createPlanes(Math::Point3D origin,
                                                            Raytracer::Material material,
                                                            double size)
    {
        return std::make_unique<Raytracer::Objects::Plane>(origin, material, size);
    }
}
