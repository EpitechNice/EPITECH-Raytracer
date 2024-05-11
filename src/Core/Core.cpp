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
#include "includes.hpp"

namespace Raytracer
{
    Core::Core(int argc, char** argv)
    {
        double screenWidth;
        double screenHeight;

        if (argc != 2)
            this->usage(argv[0], 1);
        if (std::string(argv[0]) == "-h" ||
            std::string(argv[0]) == "--help")
            this->usage(argv[0], 0);

        this->loadConfig(argv[1]);
        screenWidth = double(this->_camera->getResolution().width);
        screenHeight = double(this->_camera->getResolution().height);
        this->_image = Raytracer::Image({screenWidth, screenHeight});
        this->render(screenWidth, screenHeight);
        this->_image.save("raytracer.ppm");

        return;
    }

    void Core::checkAllHits(Math::Ray& ray, int x, int y)
    {
        size_t len = this->_primitiveList.size();

        for (size_t i = 0; i < len; i++) {
            std::shared_ptr<APrimitive> primitive = std::dynamic_pointer_cast<APrimitive>(_primitiveList[i]);
            float discriminant = primitive->doesHit(ray);
            if (discriminant >= 0.0) {
                _image.set({x, y}, primitive->hitColor(ray));
                return;
            }
        }
    }

    void Core::render(double screenWidth, double screenHeight)
    {
        double aspectRatio = screenWidth / screenHeight;
        Math::Vector3D lowerLeftCorner(-2.0, -2.0 / aspectRatio, -2.0 / aspectRatio);
        Math::Vector3D horizontal(4.0, 0.0, 0.0);
        Math::Vector3D vertical(0.0, 4.0 / aspectRatio, 0.0);
        Math::Vector3D pixelPosition;
        Math::Vector3D direction;
        Math::Ray ray;

        for (int y = (screenHeight - 1); y >= 0; y--) {
            for (int x = 0; x < screenWidth; x++) {
                double u = double(x) / double(screenWidth);
                double v = double(y) / double(screenHeight);
                pixelPosition = lowerLeftCorner + horizontal * u + vertical * v;
                Math::Vector3D direction = (pixelPosition - this->_camera->getPosition()).normalised();
                ray = Math::Ray(this->_camera->getPosition(), direction);
                checkAllHits(ray, x, y);
            }
        }
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
            throw Exceptions::CantOpenConfigFile("I/O error while reading file. " + std::string(fioex.what()), EXCEPTION_INFOS);
        }
    }

    void Core::loadConfig(const std::string sceneFilePath)
    {
        try {
            this->setConfig(sceneFilePath);
            this->createCamera();
            this->createPrimitive();
            this->createLight();

        } catch (const libconfig::SettingNotFoundException &ex) {
            throw Exceptions::InvalidParsingSettingNotFound("Setting not found in configuration file. Error: " + std::string(ex.what()), EXCEPTION_INFOS);
        } catch (const libconfig::SettingTypeException &ex) {
            throw Exceptions::InvalidParsingSettingInvalid("Incorrect setting type in configuration file. Error: " + std::string(ex.what()), EXCEPTION_INFOS);
        } catch (const libconfig::ParseException& e) {
            throw Exceptions::OtherParsingError("Error at line  " + std::to_string(e.getLine()) + ": " + e.getError());
        } catch (const std::exception &ex) {
            throw Exceptions::OtherParsingError("Error at line " + std::string(ex.what()) + " : Invalid syntax", EXCEPTION_INFOS);
        }
    }

    void Core::createCamera()
    {
        libconfig::Setting& cameraSetting = _config.lookup("camera");
        libconfig::Setting& resolutionSetting = cameraSetting.lookup("resolution");
        Raytracer::Resolution resolution{resolutionSetting["width"], resolutionSetting["height"]};
        Math::Point3D origin(cameraSetting["position"]["x"], cameraSetting["position"]["y"], cameraSetting["position"]["z"]);
        Math::Vector3D rotation(cameraSetting["rotation"]["x"], cameraSetting["rotation"]["y"], cameraSetting["rotation"]["z"]);
        // Créer la Camera avec les paramètres extraits
        this->_camera = ObjectFactory::createCamera(resolution, origin, rotation, cameraSetting["fieldOfView"]);
    }

    void Core::createPrimitive()
    {
        libconfig::Setting& primitiveSetting = _config.lookup("primitives");
        if (primitiveSetting.exists("spheres")) {
            libconfig::Setting& spheresSetting = primitiveSetting["spheres"];
            for (int i = 0; i < spheresSetting.getLength(); ++i) {
                libconfig::Setting& sphereSetting = spheresSetting[i];
                Math::Point3D origin(sphereSetting["position"]["x"], sphereSetting["position"]["y"], sphereSetting["position"]["z"]);
                Raytracer::Color c(sphereSetting["color"]["r"], sphereSetting["color"]["g"], sphereSetting["color"]["b"]);
                // Créer une sphère avec les paramètres extraits
                _primitiveList.push_back(ObjectFactory::createSphere(Math::Point3D(origin), Raytracer::Material(c), sphereSetting["radius"]));
            }
        }
        if (primitiveSetting.exists("planes")) {
            libconfig::Setting& planesSetting = primitiveSetting["planes"];
            for (int i = 0; i < planesSetting.getLength(); ++i) {
                libconfig::Setting& planeSetting = planesSetting[i];
                Math::Point3D origin(planeSetting["position"]["x"], planeSetting["position"]["y"], planeSetting["position"]["z"]);
                Raytracer::Color c(planeSetting["color"]["r"], planeSetting["color"]["g"], planeSetting["color"]["b"]);
                // Créer un Plane avec les paramètres extraits
                _primitiveList.push_back(ObjectFactory::createPlane(Math::Point3D(origin), Raytracer::Material(c), planeSetting["size"]));
            }
        }
    }

    void Core::createLight() {
        libconfig::Setting& lightSetting = _config.lookup("lights");
        double ambient = lightSetting.lookup("ambient");
        double diffuse = lightSetting.lookup("diffuse");
        if (lightSetting.exists("light")) {
            libconfig::Setting& pointSettings = lightSetting["light"];
            for (int i = 0; i < pointSettings.getLength(); ++i) {
                libconfig::Setting& lightSetting = pointSettings[i];
                Math::Point3D point(lightSetting["point"]["x"], lightSetting["point"]["y"], lightSetting["point"]["z"]);
                Math::Vector3D direction(lightSetting["direction"]["x"], lightSetting["direction"]["y"], lightSetting["direction"]["z"]);
                double angle = lightSetting["angle"];
                // Créer une lumière avec les paramètres extraits
                _lightList.push_back(ObjectFactory::createLight(ambient, diffuse, point, direction, angle));
            }
        }
    }
}
