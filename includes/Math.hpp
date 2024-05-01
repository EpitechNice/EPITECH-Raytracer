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
    #include "Exceptions.hpp"
    #include "Matrix.hpp"

namespace Math
{
    class Point3D;
    class Vector3D;

    class Point3D: public Math::Matrix<double>
    {
        public:
            Point3D();
            Point3D(double x, double y, double z);
            Point3D(std::vector<double> values);
            Point3D(std::vector<std::vector<double>> values);
            Point3D(const Point3D& other);

            Vector3D translation(const Point3D& other) const;

            Point3D& operator=(const Point3D& other);

            Point3D operator-(const Vector3D& other) const;

            Vector3D operator+(const Point3D& other) const;
            Vector3D operator-(const Point3D& other) const;
    };

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

            Vector3D& operator=(const Vector3D& other);

            Point3D operator+ (const Point3D& other) const;
            Point3D operator- (const Point3D& other) const;

            Vector3D operator* (double other) const;
            Vector3D& operator*= (double other);

            double dot(const Vector3D& other) const;

            Vector3D cross(const Vector3D& other) const;
    };
};

std::ostream& operator<<(std::ostream& os, const Math::Point3D& obj);
std::ostream& operator<<(std::ostream& os, const Math::Vector3D& obj);
template <typename T>
std::ostream& operator<<(std::ostream& os, const Math::Matrix<T>& obj);

#endif
