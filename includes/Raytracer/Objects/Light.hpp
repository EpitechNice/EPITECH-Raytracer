/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Light                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */


#ifndef LIGHTCONFIG_HPP
    #define LIGHTCONFIG_HPP

#include "Object.hpp"

namespace Raytracer::Objects
{
    class Light:
        public Raytracer::AObject
    {
        private:
            double _ambient;
            double _diffuse;
            Math::Point3D _pointLights;
            Math::Vector3D _directional;
            double _angle;

        public:
            Light();
            Light(double ambient, double diffuse, const Math::Point3D& pointLights, const Math::Vector3D& directional, double angle);
            ~Light();

            // Getters
            double getAmbient() const;
            double getDiffuse() const;
            const Math::Point3D& getPointLights() const;
            const Math::Vector3D& getDirectional() const;
    };
}

#endif // LIGHTCONFIG_HPP