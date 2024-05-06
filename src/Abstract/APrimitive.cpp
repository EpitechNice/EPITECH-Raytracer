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

#include "APrimitive.hpp"

namespace Raytracer
{
    void APrimitive::setMaterial(Raytracer::Material material)
    {
        this->_material = material;
    }

    const Raytracer::Material& APrimitive::getMaterial() const
    {
        return this->_material;
    }

    std::string APrimitive::str() const
    {
        std::stringstream ss;
        ss <<   "<" << AObject::getClassName() << " at " <<
                std::hex << this <<
                ": origin=" << this->_origin <<
                ", direction=" << this->_direction <<
                ", material=" << this->_material << ">";
        return ss.str();
    }

}
