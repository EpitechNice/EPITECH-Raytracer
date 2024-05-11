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

    std::vector<std::shared_ptr<Raytracer::APrimitive>> ObjectFactory::createSpheresSettings(libconfig::Setting& settings)
    {
        std::vector<std::shared_ptr<Raytracer::APrimitive>> out;

        for (int i = 0; i < settings.getLength(); ++i) {
            libconfig::Setting& sphereSetting = settings[i];
            Math::Point3D origin(sphereSetting["position"]["x"], sphereSetting["position"]["y"], sphereSetting["position"]["z"]);
            Raytracer::Color c(sphereSetting["color"]["r"], sphereSetting["color"]["g"], sphereSetting["color"]["b"]);
            out.push_back(ObjectFactory::createSphere(Math::Point3D(origin), Raytracer::Material(c), sphereSetting["radius"]));
        }

        return out;
    }

    std::unique_ptr<Raytracer::Objects::Plane> ObjectFactory::createPlane(Math::Point3D origin,
                                                                Raytracer::Material material,
                                                                double size)
    {
        return std::make_unique<Raytracer::Objects::Plane>(origin, material, size);
    }

    std::vector<std::shared_ptr<Raytracer::APrimitive>> ObjectFactory::createPlanesSettings(libconfig::Setting& settings)
    {
        std::vector<std::shared_ptr<Raytracer::APrimitive>> out;

        for (int i = 0; i < settings.getLength(); ++i) {
            libconfig::Setting& planeSetting = settings[i];
            Math::Point3D origin(planeSetting["position"]["x"], planeSetting["position"]["y"], planeSetting["position"]["z"]);
            Raytracer::Color c(planeSetting["color"]["r"], planeSetting["color"]["g"], planeSetting["color"]["b"]);
            // Créer un Plane avec les paramètres extraits
            out.push_back(ObjectFactory::createPlane(Math::Point3D(origin), Raytracer::Material(c), planeSetting["size"]));
        }

        return out;
    }

    std::vector<std::shared_ptr<Raytracer::AObject>> ObjectFactory::createLightsSettings(double ambient, double diffuse, libconfig::Setting& settings)
    {
        std::vector<std::shared_ptr<Raytracer::AObject>> out;

        for (int i = 0; i < settings.getLength(); ++i) {
            libconfig::Setting& lightSetting = settings[i];
            Math::Point3D point(lightSetting["point"]["x"], lightSetting["point"]["y"], lightSetting["point"]["z"]);
            Math::Vector3D direction(lightSetting["direction"]["x"], lightSetting["direction"]["y"], lightSetting["direction"]["z"]);
            double angle = lightSetting["angle"];
            // Créer une lumière avec les paramètres extraits
            out.push_back(ObjectFactory::createLight(ambient, diffuse, point, direction, angle));
        }

        return out;
    }
}
