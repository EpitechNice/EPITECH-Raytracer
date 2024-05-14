/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Hittables                                                                        *
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

#ifndef INCLUDED_HITtABLES_HPP
    #define INCLUDED_HITtABLES_HPP

    #include "headers.hpp"
    #include "../Abstract/APrimitive.hpp"
    #include "../Math/Ray.hpp"
    #include "../Image/Colors.hpp"

namespace Raytracer
{
    class Hittables
    {
        private:
            std::vector<std::shared_ptr<Raytracer::APrimitive>> _hittables;
        public:
            ~Hittables() = default;
            Hittables();
            Hittables(std::initializer_list<std::shared_ptr<Raytracer::APrimitive>> list);

            std::size_t size() const;

            Raytracer::hitRecord didHit(const Math::Ray& ray, double distMin, double distMax) const;
            void add(std::shared_ptr<Raytracer::APrimitive> obj);
            void extend(std::vector<std::shared_ptr<Raytracer::APrimitive>> objs);

            std::shared_ptr<Raytracer::APrimitive> operator[](std::size_t index) const;
    };
}

#endif
