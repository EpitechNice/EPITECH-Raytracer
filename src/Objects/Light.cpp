/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Light                                                                            *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Light.hpp"

namespace Raytracer::Objects {

    Light::Light() : _ambient(0.0), _diffuse(0.0), _pointLights(0, 0, 0), _directional(0, 0, 0) {}

    Light::Light(double ambient, double diffuse, const Math::Point3D& pointLights, const Math::Vector3D& directional)
        : _ambient(ambient), _diffuse(diffuse), _pointLights(pointLights), _directional(directional) {}

    Light::~Light() {}

    double Light::getAmbient() const {
        return _ambient;
    }

    double Light::getDiffuse() const {
        return _diffuse;
    }

    const Math::Point3D& Light::getPointLights() const {
        return _pointLights;
    }

    const Math::Vector3D& Light::getDirectional() const {
        return _directional;
    }
}
