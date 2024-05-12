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

//TODO : Scattered, attenuation from record.material
    Math::Vector3D Core::getColorRay(Math::Ray& ray, int depth)
    {
        (void) ray;
        (void) depth;
        // Math::Point3D intersectionPoint = ray.pointAt(2.0);
        Math::Vector3D color = (this->_record.normal + 1) * 0.5;

        return color;
    }

    bool Core::checkRayHit(Math::Ray& ray, double distMin, double distMax)
    {
        hitRecord tmpRec;
        double closestSoFar = distMax;
        bool hasHit = false;
        size_t len = this->_primitiveList.size();

        for (size_t i = 0; i < len; i++) {
            if (_primitiveList[i]->doesHit(ray, distMin, closestSoFar, tmpRec)) {
                hasHit = true;
                closestSoFar = tmpRec.distance;
                this->_record = tmpRec;
            }
        }
        return hasHit;
    }

    void Core::render(double screenWidth, double screenHeight)
    {
        Math::Ray ray;
        int maxColorSample;
        int ir, ig, ib;

        for (int y = (screenHeight - 1); y >= 0; y--) {
            for (int x = 0; x < screenWidth; x++) {
                Math::Vector3D color(0.0, 0.0, 0.0);
//Decrease this value to accelerate render/Increase this value to better render (antialiasing)
                maxColorSample = 5;
//Antialiasing process
                for (int colorSample = 0; colorSample < maxColorSample; colorSample++) {
                    double u = double(x + drand48()) / double(screenWidth);
                    double v = double(y + drand48()) / double(screenHeight);
                    ray = this->_camera->getRay(u, v);
                    if (checkRayHit(ray, 0.001, MAXFLOAT)) {
                        color += getColorRay(ray, 10);
                    } else {
//TODO: Instead of this, getBackgroundColor() already set in Image constructor
                        Math::Vector3D defaultColor(1.0,1.0,1.0);
                        color += defaultColor;
                    }
                }
                color /= double(maxColorSample);
//TODO: Stdout to debug, to delete before end of project
                std::cout << "{ " << x << ", " << y << " }\t" << color.getValues()[0][0] << "\t" << color.getValues()[0][1] << "\t" << color.getValues()[0][2] << std::endl;
                ir = color.getValues()[0][0] * 255.99;
		        ig = color.getValues()[0][1] * 255.99;
		        ib = color.getValues()[0][2] * 255.99;
                this->_image.set({x, y}, Raytracer::Color(ir, ig, ib));
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

    void Core::loadConfig(const std::string configFilePath)
    {
        try {
            this->_config.readFile(configFilePath.c_str());
            this->loadCamera();
            this->loadPrimitive();
            this->loadLight();
        } catch (const libconfig::FileIOException &e) {
            throw Exceptions::CantOpenConfigFile(std::string("I/O Error while reading file: ") + e.what(), EXCEPTION_INFOS);
        } catch (const libconfig::SettingNotFoundException &e) {
            throw Exceptions::InvalidParsingSettingNotFound("Missing required config in configuration file: " + std::string(e.what()), EXCEPTION_INFOS);
        } catch (const libconfig::SettingTypeException &e) {
            throw Exceptions::InvalidParsingSettingInvalid("Incorrect type in configuration file. Error: " + std::string(e.what()), EXCEPTION_INFOS);
        } catch (const libconfig::ParseException& e) {
            throw Exceptions::OtherParsingError("Error in configuration file, at line " + std::to_string(e.getLine()) + ": " + e.getError(), EXCEPTION_INFOS);
        } catch (const std::exception &e) {
            throw Exceptions::OtherParsingError("Another error was raised when parsing the config file: " + std::string(e.what()), EXCEPTION_INFOS);
        }
    }

    void Core::loadCamera()
    {
        libconfig::Setting& cameraSetting = _config.lookup("camera");
        libconfig::Setting& resolutionSetting = cameraSetting.lookup("resolution");
        Raytracer::Resolution resolution{resolutionSetting["width"], resolutionSetting["height"]};
        Math::Point3D origin(cameraSetting["position"]["x"], cameraSetting["position"]["y"], cameraSetting["position"]["z"]);
        Math::Vector3D rotation(cameraSetting["rotation"]["x"], cameraSetting["rotation"]["y"], cameraSetting["rotation"]["z"]);
        this->_camera = ObjectFactory::createCamera(resolution, origin, rotation, cameraSetting["fieldOfView"]);
    }

    void Core::loadPrimitive()
    {
        libconfig::Setting& primitiveSetting = _config.lookup("primitives");
        std::vector<std::shared_ptr<Raytracer::APrimitive>> objects;

        if (primitiveSetting.exists("spheres")) {
            objects = ObjectFactory::createSpheresSettings(primitiveSetting["spheres"]);
            for (std::size_t i = 0; i < objects.size(); i++)
                this->_primitiveList.push_back(objects[i]);
        }
        if (primitiveSetting.exists("planes")) {
            objects = ObjectFactory::createPlanesSettings(primitiveSetting["planes"]);
            for (std::size_t i = 0; i < objects.size(); i++)
                this->_primitiveList.push_back(objects[i]);
        }
    }

    void Core::loadLight() {
        libconfig::Setting& lightSetting = _config.lookup("lights");
        double ambient = lightSetting.lookup("ambient");
        double diffuse = lightSetting.lookup("diffuse");
        std::vector<std::shared_ptr<Raytracer::AObject>> objects;

        if (lightSetting.exists("light")) {
            objects = ObjectFactory::createLightsSettings(ambient, diffuse, lightSetting["light"]);
            for (std::size_t i = 0; i < objects.size(); i++)
                this->_lightList.push_back(objects[i]);
        }
    }
}
