/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Sphere                                                                           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_SPHERE_HPP
    #define INCLUDED_SPHERE_HPP

#include "headers.hpp"
#include "Object.hpp"
#include "Math.hpp"
#include "Ray.hpp"

namespace Raytracer::Objects
{
    class Sphere:
       public Raytracer::APrimitive
    {
        private:
            double _radius;

        public:
            Sphere(Math::Point3D origin = Math::Point3D(0, 0, 0),
                Raytracer::Material material = Raytracer::Material(),
                double radius = 1);
            ~Sphere() = default;

            std::string str() const override;

            double getRadius() const { return this->_radius; }

            bool doesHit(const Raytracer::Ray& other) const;
            const Raytracer::Ray& bounce(const Raytracer::Ray& other) const;
    };
}

std::ostream& operator<<(std::ostream& os, const Raytracer::Objects::Sphere& obj);

#endif
