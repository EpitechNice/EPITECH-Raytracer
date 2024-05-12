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
    Raytracer::Color Core::getColorRay(Math::Ray& ray, int depth)
    {
        (void) ray;
        (void) depth;
        // (void) record;
        // Math::Point3D intersectionPoint = ray.pointAt(2.0);
        Math::Vector3D color = (this->_record.normal + 1) * 0.5;

        int ir = color.getValues()[0][0]*255.99;
		int ig = color.getValues()[0][1]*255.99;
		int ib = color.getValues()[0][2]*255.99;
        return Raytracer::Color(ir, ig, ib);
    }

    // void Core::checkRayHit(Math::Ray& ray, std::pair<std::size_t, std::size_t> pos, double distMin, double distMax)
    Raytracer::Color Core::checkRayHit(Math::Ray& ray, double distMin, double distMax, bool& doesHit, Raytracer::hitRecord& record) const
    {
        Raytracer::Color color = this->_hitables.hitColor(ray, distMin, distMax, record);
        doesHit = color[0][0] != -1;
        // this->_image.set(pos, color);
        return color;
    }

    void Core::render(double screenWidth, double screenHeight)
    {
        // Math::Ray ray;
        // int maxColorSample = 0;
        // bool doesHit;
        // bool didHit;
        // Raytracer::Color currentColor;
        // Raytracer::Color color;
        // Raytracer::hitRecord record;

        // for (int y = (screenHeight - 1); y >= 0; y--) {
        //     for (int x = 0; x < screenWidth; x++) {
        //         double u = double(x) / double(screenWidth);
        //         double v = double(y) / double(screenHeight);
        //         // pixelPosition = lowerLeftCorner + horizontal * u + vertical * v;
        //         // Math::Vector3D direction = (pixelPosition - this->_camera->getPosition()).normalised();
        //         ray = Math::Ray(this->_camera->getPosition(), pixelPosition);
        //         this->checkRayHit(ray, 0.001, MAXFLOAT, doesHit, record);
        //     }
        // }

        std::size_t index = 0;
        Threads::ShowThread showThread((screenHeight * screenWidth), index, screenWidth, screenHeight);

        Math::Ray ray;
        int maxColorSample = 1;
        Raytracer::Color color;
        bool doesHit, didHit;
        Raytracer::hitRecord record;

        for (int y = (screenHeight - 1); y >= 0; y--) {
            for (int x = 0; x < screenWidth; x++) {

                ray = this->_camera->getRay(double(x) / double(screenWidth), double(y) / double(screenHeight));
                color = this->checkRayHit(ray, 0.001, MAXFLOAT, doesHit, record);
                didHit = doesHit;

                for (int colorSample = 0; colorSample < maxColorSample; colorSample++) {
                    double u = double(x + drand48()) / double(screenWidth);
                    double v = double(y + drand48()) / double(screenHeight);
                    ray = this->_camera->getRay(u, v);
                    color = this->checkRayHit(ray, 0.001, MAXFLOAT, doesHit, record);
                    if (doesHit) {
                        didHit = true;
                        color += this->getColorRay(ray, 10);
                    } else {
                        color += this->_image[x][y];
                    }
                }

                if (maxColorSample)
                    color /= double(maxColorSample);

                // color *= 255.99;
                if (didHit)
                    this->_image.set({x, y}, color);
                showThread.drawPoint(this->_image[x][y], x, y);
                index++;
            }
        }
        showThread.stop();
    }


    void Core::usage(std::string filename, int status)
    {
        std::cerr <<    "+---------------------+" << std::endl <<
                        "|   __                |" << std::endl <<
                        "|  /__)_  _/_ _ _ _ _ |" << std::endl <<
                        "| / ( (/(/// (/( (-/  |" << std::endl <<
                        "|       /             |" << std::endl <<
                        "+---------------------+" << std::endl <<
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
            throw Exceptions::InvalidParsingSettingInvalid("Incorrect type in configuration file. Error: " + std::string(e.getPath()) + std::string(e.what()), EXCEPTION_INFOS);
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
            this->_hitables.extend(objects);
        }
        if (primitiveSetting.exists("planes")) {
            objects = ObjectFactory::createPlanesSettings(primitiveSetting["planes"]);
            this->_hitables.extend(objects);
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
