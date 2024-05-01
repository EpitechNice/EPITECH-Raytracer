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

    void Core::loadConfig(const std::string sceneFilePath) {
        setConfig(sceneFilePath);

        createCamera();
    }

    void Core::createCamera() {
        try {
            libconfig::Setting& cameraSetting = _config.lookup("camera");
            libconfig::Setting& resolutionSetting = cameraSetting.lookup("resolution");
            int width = resolutionSetting["width"];
            int height = resolutionSetting["height"];
            Raytracer::Resolution resolution{width, height};
            std::cout << "Resolution Width: " << width << ", Height: " << height << std::endl;
            // Position de la caméra
            libconfig::Setting& positionSetting = cameraSetting["position"];
            double posX = positionSetting["x"];
            double posY = positionSetting["y"];
            double posZ = positionSetting["z"];
            std::cout << "Camera Position X: " << posX << ", Y: " << posY << ", Z: " << posZ << std::endl;
            // Rotation de la caméra
            libconfig::Setting& rotationSetting = cameraSetting["rotation"];
            double rotX = rotationSetting["x"];
            double rotY = rotationSetting["y"];
            double rotZ = rotationSetting["z"];
            std::cout << "Camera Rotation X: " << rotX << ", Y: " << rotY << ", Z: " << rotZ << std::endl;
            // Champ de vision de la caméra
            double fieldOfView = cameraSetting["fieldOfView"];
            std::cout << "Field of View: " << fieldOfView << std::endl;
            // Créer l'objet Camera avec les paramètres extraits
            _camera = Raytracer::Camera(resolution, {posX, posY, posZ}, {rotX, rotY, rotZ}, fieldOfView);
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Error: Setting not found in configuration file." << std::endl;
        } catch (const libconfig::SettingTypeException &tex) {
            std::cerr << "Error: Incorrect setting type in configuration file." << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
}
