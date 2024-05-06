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

    #include "../Abstract/AObject.hpp"
    #include "../Math/Vector3D.hpp"
    #include "../Math/Point3D.hpp"

namespace Raytracer::Objects
{
    class Light: public Raytracer::AObject
    {
        private:
            double _ambient;
            double _diffuse;
            double _angle;

        public:
            Light();
            Light(double ambient, double diffuse, const Math::Point3D& pointLights, const Math::Vector3D& directional, double angle);
            ~Light();

            std::string getClassName() const;

            // Getters
            double getAmbient() const;
            double getDiffuse() const;

            std::string str() const;

            friend std::ostream& operator<<(std::ostream& os, const Light& obj);
    };
}

#endif // LIGHTCONFIG_HPP