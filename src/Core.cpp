/*                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Visual Studio Live Share (Workspace)                               *
 * Description     -                                                                    *
 *     Core                                                                             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "Core.hpp"

namespace Raytracer {

    Core::Core(const std::string sceneFilePath)
    {
        loadConfig(sceneFilePath);
    }

    void Core::setConfig(const std::string sceneFilePath)
    {
        try {
            this->_config.readFile(sceneFilePath.c_str());
        } catch (const libconfig::FileIOException &fioex) {
            std::cerr << "I/O error while reading file." << std::endl;
        } catch (const libconfig::ParseException &pex) {
                std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                          << " - " << pex.getError() << std::endl;
        }
    }

//TODO: try/catch pour les cas d'erreurs
//TODO: classes (architecture)
//TODO: NEW object (ex : spheres)
    void Core::loadConfig(const std::string sceneFilePath)
    {
        setConfig(sceneFilePath);

        libconfig::Setting& camera = this->_config.lookup("camera");
        this->_camera._width = camera["resolution"]["width"];
        this->_camera._height = camera["resolution"]["height"];

        libconfig::Setting& spheres = this->_config.lookup("primitives.spheres");
        for (int i = 0; i < spheres.getLength(); i++) {
            libconfig::Setting& sphere = spheres[i];
            int x = sphere["x"];
            int y = sphere["y"];
            int z = sphere["z"];
            int r = sphere["r"];
            //couleurs
        }

        libconfig::Setting& lights = this->_config.lookup("lights");
        double ambient = lights["ambient"];
        double diffuse = lights["diffuse"];

        libconfig::Setting& pointLights = lights["point"];
        for (int i = 0; i < pointLights.getLength(); ++i)
        {
            libconfig::Setting& pointLight = pointLights[i];
            int x = pointLight["x"];
            int y = pointLight["y"];
            int z = pointLight["z"];
            //etc
        }



    }

}