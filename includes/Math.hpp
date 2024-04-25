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
    class Point3D;
    class Vector3D;

    class Point3D
    {
        private:
            std::string getClassName() const;

        public:
            double x = 0;
            double y = 0;
            double z = 0;
            Point3D();
            Point3D(double _zx, double _y, double _z);
            Point3D(const Point3D& other);

            std::string str() const;
            Vector3D translation(const Point3D& other) const;

            Point3D& operator=(const Point3D& other);

            Point3D operator-() const;

            Point3D operator+(const Vector3D& other) const;
            Point3D operator-(const Vector3D& other) const;

            Point3D& operator+=(const Vector3D& other);
            Point3D& operator-=(const Vector3D& other);

            Vector3D operator+(const Point3D& other) const;
            Vector3D operator-(const Point3D& other) const;

    };

    class Vector3D
    {
        private:
            std::string getClassName() const;

        public:
            double x = 0;
            double y = 0;
            double z = 0;
            Vector3D();
            Vector3D(double _x, double _y, double _z);
            Vector3D(const Vector3D& other);

            std::string str() const;
            double length() const;
            Vector3D normalised() const;

            static Vector3D makeFromNormalized(const Vector3D& obj, double length);

            Vector3D& operator=(const Vector3D& other);

            Vector3D operator-() const;

            Vector3D operator+(const Vector3D& other) const;
            Vector3D operator-(const Vector3D& other) const;

            Vector3D& operator+=(const Vector3D& other);
            Vector3D& operator-=(const Vector3D& other);

            Point3D operator+(const Point3D& other) const;
            Point3D operator-(const Point3D& other) const;

            Vector3D operator*(double value) const;
            Vector3D operator/(double value) const;

            Vector3D& operator*=(double value);
            Vector3D& operator/=(double value);

            Vector3D cross(const Vector3D& other) const;
    };
};

std::ostream& operator<<(std::ostream& os, const Math::Point3D& obj);
std::ostream& operator<<(std::ostream& os, const Math::Vector3D& obj);

#endif
