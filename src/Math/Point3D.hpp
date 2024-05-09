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

#ifndef POINT3D_HPP
    #define POINT3D_HPP

    #include "headers.hpp"
    #include "Matrix.hpp"
    #include "Vector3D.hpp"
    #include "../Exceptions/Exceptions.hpp"

namespace Math
{
    class Vector3D;

    class Point3D: public Math::Matrix<double>
    {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(std::vector<double> values);
            Point3D(std::vector<std::vector<double>> values);
            Point3D(const Point3D& other);

            Math::Vector3D translation(const Point3D& other) const;

            Point3D& operator=(const Point3D& other);
            Point3D operator-(const Math::Vector3D& other) const;
            Math::Vector3D operator+(const Point3D& other) const;
            Math::Vector3D operator-(const Point3D& other) const;

            std::string str() const;

            friend std::ostream& operator<<(std::ostream& os, const Math::Point3D& obj);
    };
}

#endif
