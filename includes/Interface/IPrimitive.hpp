/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     IPrimitive                                                                       *
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

#ifndef IPRIMITIVE_HPP
    #define IPRIMITIVE_HPP

    #include "IObject.hpp"

    #include "../../src/Image/Image.hpp"
    #include "../../src/Material/Material.hpp"
    #include "../../src/Math/Ray.hpp"

namespace Raytracer
{
    typedef struct {
        double distance;
        Math::Point3D intersectionPoint;
        Math::Vector3D normal;
        Raytracer::Material material;
        Raytracer::Color color;
    } hitRecord;

    class IPrimitive: virtual public Raytracer::IObject
    {
        public:
            virtual void setMaterial(Raytracer::Material material) = 0;
            virtual const Raytracer::Material& getMaterial() const = 0;

            virtual bool doesHit(const Math::Ray& other, double distMin, double distMax, hitRecord& record) const = 0;
            virtual Math::Ray bounce(const Math::Ray& ray) const = 0;
    };
}

#endif
