/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     BuildMaterials                                                                   *
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

#include "BuildMaterials.hpp"

namespace Raytracer
{
    void BuildMaterials::build()
    {
        this->_materials["metal"] = std::make_shared<Raytracer::Materials::Metal>();
        this->_materials["matte"] = std::make_shared<Raytracer::Materials::Matte>();
    }

    BuildMaterials::BuildMaterials()
    {
        this->build();
    }

    BuildMaterials& BuildMaterials::get()
    {
        static BuildMaterials instance;
        return instance;
    }

    std::shared_ptr<Raytracer::AMaterial> BuildMaterials::operator[](std::string key)
    {
        std::string lowerCaseKey = "";
        for (std::size_t i = 0; i < key.size(); i++)
            lowerCaseKey += std::tolower(key[i]);
        if (!this->_materials.contains(key))
            throw Exceptions::KeyError("No such material named " + key, EXCEPTION_INFOS);

        return this->_materials.at(lowerCaseKey);
    }
}