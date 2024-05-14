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

    std::unique_ptr<Raytracer::Objects::Sphere> ObjectFactory::createSphere(std::shared_ptr<Raytracer::AMaterial> material,
                                                                            Math::Point3D origin,
                                                                            double radius)
    {
        return std::make_unique<Raytracer::Objects::Sphere>(material, origin, radius);
    }

    std::vector<std::shared_ptr<Raytracer::APrimitive>> ObjectFactory::createSpheresSettings(libconfig::Setting& settings)
    {
        std::vector<std::shared_ptr<Raytracer::APrimitive>> out;

        for (int i = 0; i < settings.getLength(); ++i) {
            libconfig::Setting& sphereSetting = settings[i];
            Math::Point3D origin(sphereSetting["position"]["x"], sphereSetting["position"]["y"], sphereSetting["position"]["z"]);
            std::shared_ptr<Raytracer::AMaterial> c = BuildMaterials::get()[sphereSetting["material"]];
            out.push_back(ObjectFactory::createSphere(c, Math::Point3D(origin), sphereSetting["radius"]));
        }

        return out;
    }

    std::unique_ptr<Raytracer::Objects::Plane> ObjectFactory::createPlane(std::shared_ptr<Raytracer::AMaterial> material,
                                                                          Math::Point3D origin,
                                                                          double size)
    {
        return std::make_unique<Raytracer::Objects::Plane>(material, origin, size);
    }

    std::vector<std::shared_ptr<Raytracer::APrimitive>> ObjectFactory::createPlanesSettings(libconfig::Setting& settings)
    {
        std::vector<std::shared_ptr<Raytracer::APrimitive>> out;

        for (int i = 0; i < settings.getLength(); ++i) {
            libconfig::Setting& planeSetting = settings[i];
            Math::Point3D origin(planeSetting["position"]["x"], planeSetting["position"]["y"], planeSetting["position"]["z"]);
            std::shared_ptr<Raytracer::AMaterial> c = BuildMaterials::get()[planeSetting["material"]];
            // Créer un Plane avec les paramètres extraits
            out.push_back(ObjectFactory::createPlane(c, Math::Point3D(origin), planeSetting["size"]));
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
