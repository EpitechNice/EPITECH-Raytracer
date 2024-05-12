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
    #include "../Abstract/APrimitive.hpp"

    #include "../Math/Vector3D.hpp"
    #include "../Math/Point3D.hpp"
    #include "../Math/Ray.hpp"

namespace Raytracer::Objects
{
    class Sphere:
       public Raytracer::APrimitive
    {
        private:
            double _radius;

        public:
            Sphere(Math::Point3D origin = Math::Point3D(0, 0, -1),
                Raytracer::Material material = Raytracer::Material(),
                double radius = 1);
            ~Sphere() = default;

            std::string str() const override;

            double getRadius() const { return this->_radius; }

            bool doesHit(const Math::Ray& other, double distMin, double distMax, hitRecord& record) const;
            Raytracer::Color hitColor(const Math::Ray& ray) const;

            static Math::Vector3D generateRandomPoint();
            Math::Ray bounce(const Math::Ray& other) const;
    };
}

std::ostream& operator<<(std::ostream& os, const Raytracer::Objects::Sphere& obj);

#endif
