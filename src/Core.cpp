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

namespace Raytracer
{
    Core::Core(int argc, char** argv)
    {
        if (argc != 2)
            this->usage(argv[0], 1);
        if (std::string(argv[0]) == "-h" ||
            std::string(argv[0]) == "--help")
            this->usage(argv[0], 0);
        // if ()
        this->loadConfig(argv[1]);
    }

    void Core::usage(std::string filename, int status)
    {
        std::cerr <<    "--------------------" << std::endl <<
                        "  __                " << std::endl <<
                        " /__)_  _/_ _ _ _ _ " << std::endl <<
                        "/ ( (/(/// (/( (-/  " << std::endl <<
                        "      /             " << std::endl <<
                        "--------------------" << std::endl <<
                        "Usage:" << std::endl <<
                        "\t" << filename << " [-h|--help] [config_file]" << std::endl <<
                        "\t\t-h | --help  Show this help and exit" << std::endl <<
                        "\t\tconfig_file  Load the config file and render the scene." << std::endl <<
                        "\t\t             Please visit https://github.com/EpitechNice/EPITECH-Raytracer for more infos." << std::endl;
        std::exit(status);

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
        this->setConfig(sceneFilePath);

        this->createCamera();
        this->DEBUGPrintCameraInfo();
        this->createPrimitive();
        this->DEBUGPrintAllObject();
        this->createLight();
        this->DEBUGPrintAllLight();
    }

    void Core::createCamera() {
        try {
            libconfig::Setting& cameraSetting = _config.lookup("camera");
            libconfig::Setting& resolutionSetting = cameraSetting.lookup("resolution");
            Raytracer::Resolution resolution{resolutionSetting["width"], resolutionSetting["height"]};
            Math::Point3D origin(cameraSetting["position"]["x"], cameraSetting["position"]["y"], cameraSetting["position"]["z"]);
            Math::Point3D rotation(cameraSetting["rotation"]["x"], cameraSetting["rotation"]["y"], cameraSetting["rotation"]["z"]);
            // Créer la Camera avec les paramètres extraits
            _camera = Raytracer::Camera(resolution, Math::Point3D(origin), Math::Point3D(rotation), cameraSetting["fieldOfView"]);
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Error: Setting not found in configuration file." << std::endl;
        } catch (const libconfig::SettingTypeException &tex) {
            std::cerr << "Error: Incorrect setting type in configuration file." << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }
    void Core::createPrimitive() {
        try {
            libconfig::Setting& primitiveSetting = _config.lookup("primitives");
            if (primitiveSetting.exists("spheres")) {
                libconfig::Setting& spheresSetting = primitiveSetting["spheres"];
                for (int i = 0; i < spheresSetting.getLength(); ++i) {
                    libconfig::Setting& sphereSetting = spheresSetting[i];
                    Math::Point3D origin(sphereSetting["position"]["x"], sphereSetting["position"]["y"], sphereSetting["position"]["z"]);
                    Raytracer::Color c(sphereSetting["color"]["r"], sphereSetting["color"]["g"], sphereSetting["color"]["b"]);
                    // Créer une sphère avec les paramètres extraits
                    Raytracer::Objects::Sphere sphere(Math::Point3D(origin), Raytracer::Material(c), sphereSetting["radius"]);
                    _objectList.push_back(std::make_shared<Raytracer::Objects::Sphere>(sphere));
                }
            }
            if (primitiveSetting.exists("planes")) {
                libconfig::Setting& planesSetting = primitiveSetting["planes"];
                for (int i = 0; i < planesSetting.getLength(); ++i) {
                    libconfig::Setting& planeSetting = planesSetting[i];
                    Math::Point3D origin(planeSetting["position"]["x"], planeSetting["position"]["y"], planeSetting["position"]["z"]);
                    Raytracer::Color c(planeSetting["color"]["r"], planeSetting["color"]["g"], planeSetting["color"]["b"]);
                    // Créer un Plane avec les paramètres extraits
                    Raytracer::Objects::Plane plane(Math::Point3D(origin), Raytracer::Material(c), planeSetting["size"]);
                    _objectList.push_back(std::make_shared<Raytracer::Objects::Plane>(plane));
                }
            }
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Error: Setting not found in configuration file." << std::endl;
        } catch (const libconfig::SettingTypeException &tex) {
            std::cerr << "Error: Incorrect setting type in configuration file." << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    void Core::createLight() {
        try {
            libconfig::Setting& lightSetting = _config.lookup("lights");
            double ambient = lightSetting.lookup("ambient");
            double diffuse = lightSetting.lookup("diffuse");

            if (lightSetting.exists("point_and_direction")) {
                libconfig::Setting& pointSettings = lightSetting["point_and_direction"];
                for (int i = 0; i < pointSettings.getLength(); ++i) {
                    libconfig::Setting& lightSetting = pointSettings[i];
                    Math::Point3D point(lightSetting["point"]["x"], lightSetting["point"]["y"], lightSetting["point"]["z"]);
                    Math::Vector3D direction(lightSetting["direction"]["x"], lightSetting["direction"]["y"], lightSetting["direction"]["z"]);
                    double angle = lightSetting["angle"];
                    // Créer une lumière avec les paramètres extraits
                    Raytracer::Objects::Light light(ambient, diffuse, point, direction, angle);
                    _lightList.push_back(std::make_shared<Raytracer::Objects::Light>(light));
                }
            }
        } catch (const libconfig::SettingNotFoundException &nfex) {
            std::cerr << "Error: Setting not found in configuration file." << std::endl;
        } catch (const libconfig::SettingTypeException &tex) {
            std::cerr << "Error: Incorrect setting type in configuration file." << std::endl;
        } catch (const std::exception &ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
        }
    }

    void Core::DEBUGPrintAllObject() {
        for (const auto& objPtr : _objectList) {
            if (auto spherePtr = std::dynamic_pointer_cast<Raytracer::Objects::Sphere>(objPtr)) {
                const Raytracer::Objects::Sphere& sphere = *spherePtr;
                std::cout << &sphere << std::endl;
            } else if (auto planePtr = std::dynamic_pointer_cast<Raytracer::Objects::Plane>(objPtr)) {
                Raytracer::Objects::Plane plane = *planePtr;
                std::cout << &plane << std::endl;
            } else {
                std::cerr << "Error: Object in _objectList is neither Sphere nor Plane." << std::endl;
            }
        }
    }

    void Core::DEBUGPrintCameraInfo() {
        try {
            const Resolution& resolution = _camera.getResolution();
            Math::Point3D position = _camera.getPosition();
            double fieldOfView = _camera.getFieldOfView();

            std::cout << "Camera Info: " << std::endl;
            std::cout << "Resolution: " << resolution.width << "x" << resolution.height << ", " << std::endl;
            std::cout << "Position: (" << &position << ")" << std::endl;
            std::cout << "Field of View: " << fieldOfView << " degrees" << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Error printing camera info: " << ex.what() << std::endl;
        }
    }

    void Core::DEBUGPrintAllLight() {
        for (const auto& light : _lightList) {
            std::cout << light << std::endl;
        }
    }
}
