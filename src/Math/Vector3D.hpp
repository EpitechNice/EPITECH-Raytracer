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

#ifndef MATH_HPP
    #define MATH_HPP

    #include "headers.hpp"
    #include "Matrix.hpp"
    #include "Point3D.hpp"
    #include "../Exceptions/Exceptions.hpp"

namespace Math
{
    class Point3D;

    class Vector3D: public Math::Matrix<double>
    {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(std::vector<double> values);
            Vector3D(std::vector<std::vector<double>> values);
            Vector3D(const Vector3D& other);

            std::string str() const;
            double length() const;
            Vector3D normalised() const;

            static Vector3D makeFromNormalized(const Vector3D& obj, double length);

            friend std::ostream& operator<<(std::ostream& os, const Math::Vector3D& obj);
            Vector3D& operator=(const Vector3D& other);
            Point3D operator+ (const Point3D& other) const;
            Point3D operator- (const Point3D& other) const;
            Vector3D operator* (double other) const;
            Vector3D& operator*= (double other);

            double dot(const Vector3D& other) const;

            Vector3D cross(const Vector3D& other) const;

            friend std::ostream& operator<<(std::ostream& os, const Math::Vector3D& obj);
    };
}

#endif
