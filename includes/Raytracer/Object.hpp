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
#include "Material.hpp"

namespace Raytracer
{
    class IObject
    {
        protected:
            Math::Point3D _origin;
            Math::Vector3D _direction;
        public:
            virtual std::string getClassName() const = 0;
            virtual std::string str() const = 0;

            virtual void setPosition(const Math::Point3D& position) = 0;
            virtual void setDirection(const Math::Vector3D& direction) = 0;

            virtual const Math::Point3D& getPosition() const = 0;
            virtual const Math::Vector3D& getDirection() const = 0;
    };

    class IPrimitive:
        virtual public Raytracer::IObject
    {
        protected:
            Raytracer::Material _material;
        public:
            virtual void setMaterial(Raytracer::Material material) = 0;
            virtual const Raytracer::Material& getMaterial() const = 0;

            virtual bool doesHit(const Raytracer::Ray& ray) const = 0;
            virtual const Raytracer::Ray& bounce(const Raytracer::Ray& ray) const = 0;
    };

    class AObject:
        virtual public Raytracer::IObject
    {
        public:
            ~AObject() = default;

            std::string getClassName() const;
            std::string str() const;

            void setPosition(const Math::Point3D& position) override;
            void setDirection(const Math::Vector3D& direction) override;

            const Math::Point3D& getPosition() const;
            const Math::Vector3D& getDirection() const;
    };

    class APrimitive:
        public Raytracer::IPrimitive,
        public Raytracer::AObject
    {
        public:
            virtual void setMaterial(Raytracer::Material material);
            virtual const Raytracer::Material& getMaterial() const;

            virtual std::string str() const;
    };
}

#endif
