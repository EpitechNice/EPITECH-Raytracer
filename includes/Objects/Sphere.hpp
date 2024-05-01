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

namespace Raytracer::Objects {

    class Sphere : public Raytracer::AObject {
    private:
        Math::Point3D _origin;
        double _radius;

    public:
        Sphere(Math::Point3D origin = Math::Point3D(0, 0, 0),
               Raytracer::Material material = Raytracer::Material(),
               double radius = 1);
        ~Sphere() = default;

        std::string str() const override;

        // Getter
        double getRadius() const;
        const Math::Point3D& getPosition() const override { return _origin;}

        bool doesHit(const Raytracer::Ray& other) const override;
        Raytracer::Ray bounce(const Raytracer::Ray& other) const override;
    };

}

#endif
