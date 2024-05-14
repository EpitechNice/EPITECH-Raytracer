/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     AMaterial                                                                         *
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

#ifndef AMATERIAL_HPP
    #define AMATERIAL_HPP

    #include "configs.hpp"
    #include "headers.hpp"
    #include "includes.hpp"
    #include "../Image/Image.hpp"
    #include "../Image/Colors.hpp"
    #include "../Math/Point3D.hpp"
    #include "../Math/Vector3D.hpp"
    #include "../Math/Ray.hpp"

namespace Raytracer
{
    class AMaterial: public Raytracer::IMaterial
    {
        private:
            Raytracer::Image _pattern;
            double _albedo;

        public:
            AMaterial();
            AMaterial(Raytracer::Image pattern);
            AMaterial(Raytracer::Color color, std::pair<std::size_t, std::size_t> size = {10, 10});
            AMaterial(const AMaterial& other);
            ~AMaterial() = default;


            const Raytracer::Image& getPattern() const override;
            void setPattern(Raytracer::Image pattern);
            bool scatter(const Math::Ray& ray, const Raytracer::hitRecord& record, Math::Vector3D& attenuation, Math::Ray& scattered) const override;
    };
}

#endif
