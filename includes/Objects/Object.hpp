/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Object                                                                           *
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

#ifndef INCLUDED_OBJECT_HPP
    #define INCLUDED_OBJECT_HPP

#include "headers.hpp"
#include "Math.hpp"
#include "Ray.hpp"
#include "../Materials/Material.hpp"

namespace Raytracer
{
    class IObject
    {
        protected:
            Math::Point3D _origin;
            Raytracer::Material _material;
        public:
            virtual std::string getClassName() const = 0;
            virtual std::string str() const = 0;
            virtual bool doesHit(const Raytracer::Ray& other) const = 0;
            virtual Raytracer::Ray bounce(const Raytracer::Ray& other) const = 0;
            virtual void setPosition(Math::Point3D position) = 0;
            virtual void setMaterial(Raytracer::Material material) = 0;
            virtual const Math::Point3D& getPosition() const = 0;
            virtual const Raytracer::Material& getMaterial() const = 0;
    };

    class AObject: public IObject
    {
        public:
            ~AObject() = default;

            std::string getClassName() const final;
            virtual std::string str() const;

            void setPosition(Math::Point3D position);
            void setMaterial(Raytracer::Material material);

            const Math::Point3D& getPosition() const;
            const Raytracer::Material& getMaterial() const;
    };

    std::ostream& operator<<(std::ostream& os, const AObject& obj);
}

#endif

/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * MIT License                                                                          *
 * Copyright (c) 2024 Tech0ne                                                           *
 *                                                                                      *
 * Permission is hereby granted, free of charge, to any person obtaining a copy         *
 * of this software and associated documentation files (the "Software"), to deal        *
 * in the Software without restriction, including without limitation the rights         *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell            *
 * copies of the Software, and to permit persons to whom the Software is                *
 * furnished to do so, subject to the following conditions:                             *
 *                                                                                      *
 * The above copyright notice and this permission notice shall be included in all       *
 * copies or substantial portions of the Software.                                      *
 *                                                                                      *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR           *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,             *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE          *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER               *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,        *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE        *
 * SOFTWARE.                                                                            *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */
