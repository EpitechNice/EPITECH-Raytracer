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

            // Getter
            double getSize() const { return this->_size;};

            bool doesHit(const Math::Ray& ray) const;
            Math::Ray bounce(const Math::Ray& other) const;

            std::string str() const override;

            friend std::ostream& operator<<(std::ostream& os, const Plane& obj);
    };
}


#endif // PLANE_HPP
