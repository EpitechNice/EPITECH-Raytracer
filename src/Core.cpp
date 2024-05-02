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
        DEBUGPrintCameraInfo();
        createPrimitive();
        DEBUGPrintAllObject();
    }

    void Core::createCamera() {
        try {
            libconfig::Setting& cameraSetting = _config.lookup("camera");
            libconfig::Setting& resolutionSetting = cameraSetting.lookup("resolution");
            int width = resolutionSetting["width"];
            int height = resolutionSetting["height"];
            Raytracer::Resolution resolution{width, height};
            libconfig::Setting& positionSetting = cameraSetting["position"];
            double posX = positionSetting["x"];
            double posY = positionSetting["y"];
            double posZ = positionSetting["z"];
            libconfig::Setting& rotationSetting = cameraSetting["rotation"];
            double rotX = rotationSetting["x"];
            double rotY = rotationSetting["y"];
            double rotZ = rotationSetting["z"];
            double fieldOfView = cameraSetting["fieldOfView"];
            // Créer la Camera avec les paramètres extraits
            _camera = Raytracer::Camera(resolution, {posX, posY, posZ}, {rotX, rotY, rotZ}, fieldOfView);
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
                    double x = sphereSetting["x"];
                    double y = sphereSetting["y"];
                    double z = sphereSetting["z"];
                    double radius = sphereSetting["radius"];
                    // Créer une sphère avec les paramètres extraits
                    Raytracer::Objects::Sphere sphere({x, y, z}, Raytracer::Material(), radius);
                    _objectList.push_back(std::make_shared<Raytracer::Objects::Sphere>(sphere));
                }
            }
            if (primitiveSetting.exists("planes")) {
                libconfig::Setting& planesSetting = primitiveSetting["planes"];
                for (int i = 0; i < planesSetting.getLength(); ++i) {
                    libconfig::Setting& planeSetting = planesSetting[i];
                    double x = planeSetting["x"];
                    double y = planeSetting["y"];
                    double z = planeSetting["z"];
                    double size = planeSetting["size"];
                    // Créer un Plane avec les paramètres extraits
                    Raytracer::Objects::Plane plane({x, y, z}, Raytracer::Material(), size);
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

    // void Core::createLight() {
    //     try {
    //         libconfig::Setting& lightSetting = _config.lookup("lights");
    //         double ambient = lightSetting.lookup("ambient");
    //         double diffuse = lightSetting.lookup("diffuse");
    //         if (lightSetting.exists("point")) {
    //             libconfig::Setting& pointSetting = lightSetting["point"];
    //             for (int i = 0; i < pointSetting.getLength(); ++i) {
    //                 libconfig::Setting& pointSetting = pointSetting[i];
    //                 double x = pointSetting["x"];
    //                 double y = pointSetting["y"];
    //                 double z = pointSetting["z"];
    //                 double radius = pointSetting["radius"];
    //                 Raytracer::Objects::Light light(ambient, diffuse, {x, y, z});
    //                 _objectList.push_back(std::make_shared<Raytracer::Objects::Light>(light));
    //             }
    //         }
    //         // Créer la Camera avec les paramètres extraits
    //     } catch (const libconfig::SettingNotFoundException &nfex) {
    //         std::cerr << "Error: Setting not found in configuration file." << std::endl;
    //     } catch (const libconfig::SettingTypeException &tex) {
    //         std::cerr << "Error: Incorrect setting type in configuration file." << std::endl;
    //     } catch (const std::exception &ex) {
    //         std::cerr << "Error: " << ex.what() << std::endl;
    //     }
    // }

    void Core::DEBUGPrintAllObject() {
        for (const auto& objPtr : _objectList) {
            if (auto spherePtr = std::dynamic_pointer_cast<Raytracer::Objects::Sphere>(objPtr)) {
                const Raytracer::Objects::Sphere& sphere = *spherePtr;
                const Math::Point3D& center = sphere.getPosition();
                double radius = sphere.getRadius();
                std::cout << "Sphere - Center: (" << center.str() << "), Radius: " << radius << std::endl;
            } else if (auto planePtr = std::dynamic_pointer_cast<Raytracer::Objects::Plane>(objPtr)) {
                const Raytracer::Objects::Plane& plane = *planePtr;
                const Math::Point3D& origin = plane.getPosition();
                double size = plane.getSize();
                std::cout << "Plane - Origin: (" << origin.str() << "), Size: " << size << std::endl;
            } else {
                std::cerr << "Error: Object in _objectList is neither Sphere nor Plane." << std::endl;
            }
        }
    }

    void Core::DEBUGPrintCameraInfo() {
        try {
            const Resolution& resolution = _camera.getResolution();
            const Math::Point3D& position = _camera.getPosition();
            double fieldOfView = _camera.getFieldOfView();

            std::cout << "Camera Info: ";
            std::cout << "Resolution: " << resolution.width << "x" << resolution.height << ", ";
            std::cout << "Position: (" << position.str() << ")";
            std::cout << "Field of View: " << fieldOfView << " degrees" << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << "Error printing camera info: " << ex.what() << std::endl;
        }
    }
}
