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

    #include "../Abstract/APrimitive.hpp"
    #include "../Math/Vector3D.hpp"
    #include "../Math/Point3D.hpp"

namespace Raytracer::Objects
{
    class Plane: public Raytracer::APrimitive
    {
        private:
            double _size;

        public:
            Plane(Math::Point3D origin = Math::Point3D(0, 1, 0),
                Raytracer::Material material = Raytracer::Material(),
                double size = 0.0);
            ~Plane() = default;

            double getSize() const;

            bool doesHit(const Math::Ray& other, double distMin, double distMax, hitRecord& record) const override;
            Raytracer::Color hitColor(const Math::Ray& ray) const override;
            Math::Ray bounce(const Math::Ray& other) const override;
            std::string str() const override;

            friend std::ostream& operator<<(std::ostream& os, const Plane& obj);
    };
}


#endif // PLANE_HPP
