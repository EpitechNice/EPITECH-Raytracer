/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Math                                                                             *
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

#ifndef INCLUDED_MATH_HPP
    #define INCLUDED_MATH_HPP

    #include "headers.hpp"

namespace Math
{
    class Point3D
    {
        public:
            double x = 0;
            double y = 0;
            double z = 0;
            Point3D();
            Point3D(double x, double y, double z);

            std::string str();
    };

    class Vector3D
    {
        public:
            double x = 0;
            double y = 0;
            double z = 0;
            Vector3D();
            Vector3D(double x, double y, double z);

            std::string str();
            inline double length();
    };
};

#endif
