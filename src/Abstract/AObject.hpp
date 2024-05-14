/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     AObject                                                                          *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#ifndef AOBJECT_HPP
    #define AOBJECT_HPP

    #include "includes.hpp"

    #include "../Abstract/AMaterial.hpp"
    #include "../Math/Ray.hpp"

namespace Raytracer
{
    class AObject: virtual public Raytracer::IObject
    {
        protected:
            Math::Point3D _origin;
            Math::Vector3D _direction;
        public:
            ~AObject() = default;

            std::string getClassName() const;
            std::string str() const;

            void setPosition(const Math::Point3D& position) override;
            void setDirection(const Math::Vector3D& direction) override;

            const Math::Point3D& getPosition() const;
            const Math::Vector3D& getDirection() const;

            friend std::ostream& operator<<(std::ostream& os, const AObject& obj);
    };
}

#endif
