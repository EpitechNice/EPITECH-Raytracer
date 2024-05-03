/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Plane                                                                           *
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

#ifndef PLANE_HPP
    #define PLANE_HPP

#include "Object.hpp"
#include "Math.hpp"

namespace Raytracer::Objects
{
    class Plane:
        public Raytracer::APrimitive
    {
        private:
            double _size;

        public:
            Plane(Math::Point3D origin = Math::Point3D(0, 1, 0),
                Raytracer::Material material = Raytracer::Material(),
                double size = 0.0);
            ~Plane() = default;

            std::string str() const override;

            // Getter
            double getSize() const { return this->_size;};

            bool doesHit(const Raytracer::Ray& ray) const;
            const Raytracer::Ray& bounce(const Raytracer::Ray& other) const;
    };
}

std::ostream& operator<<(std::ostream& os, const Raytracer::Objects::Plane& obj);

#endif // PLANE_HPP
