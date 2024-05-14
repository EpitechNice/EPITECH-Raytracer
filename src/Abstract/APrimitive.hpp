/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     APrimitive                                                                       *
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

#ifndef APRIMITIVE_HPP
    #define APRIMITIVE_HPP

    #include "includes.hpp"
    #include "AObject.hpp"

    #include "../Abstract/AMaterial.hpp"
    #include "../Math/Ray.hpp"

namespace Raytracer
{
    class APrimitive: public Raytracer::IPrimitive, public Raytracer::AObject
    {
        protected:
            std::shared_ptr<Raytracer::AMaterial> _material;
        public:
            virtual void setMaterial(std::shared_ptr<Raytracer::AMaterial> material);
            virtual std::shared_ptr<Raytracer::AMaterial> getMaterial() const;

            virtual std::string str() const;
    };

}

#endif
