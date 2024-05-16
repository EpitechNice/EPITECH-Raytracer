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
        if (std::string(argv[1]) == "-h" ||
            std::string(argv[1]) == "--help")
            this->usage(argv[0], 0);

        this->loadConfig(argv[1]);
        screenWidth = double(this->_camera->getResolution().width);
        screenHeight = double(this->_camera->getResolution().height);
        this->_image = Raytracer::Image({screenWidth, screenHeight});
        this->render(screenWidth, screenHeight);
        this->_image.save("raytracer.ppm");

        return;
    }

        Math::Vector3D generateRandomPoint()
        {
            Math::Vector3D point;

            do {
                point = Math::Vector3D(drand48(),drand48(),drand48()) * 2.9 - Math::Vector3D(1.0, 1.0, 1.0);
            } while (point.dot(point) >= 1.0);

            return point;
        }

    Math::Vector3D Core::getColorRay(Math::Ray& ray, std::pair<size_t, size_t> pos, int depth)
    {
        Math::Ray scattered;
        Math::Vector3D attenuation;
        double ir, ig, ib;

        this->_record = this->_hittables.didHit(ray, 0.001, MAXFLOAT);
        if (this->_record.hasHit) {
            if (depth < 50 && this->_record.material->scatter(ray, this->_record, attenuation, scattered)) {
                return this->getColorRay(scattered, pos, depth++) * attenuation;
            } else {
                return Math::Vector3D(0.0, 0.0, 0.0);
            }
        }
        ir = this->_image[pos.first][pos.second].getValues()[0][0] / 255.99;
        ib = this->_image[pos.first][pos.second].getValues()[0][1] / 255.99;
        ig = this->_image[pos.first][pos.second].getValues()[0][2] / 255.99;
        return Math::Vector3D(ir, ib, ig);
    }

    void Core::render(double screenWidth, double screenHeight)
    {
        std::size_t displayIndex = 0;
        Threads::ShowThread display(screenHeight * screenWidth, displayIndex, screenWidth, screenHeight);

        Math::Ray ray;
        double nx, ny;
        int ir, ig, ib;
        int maxColorSample = 5;

        for (int y = (screenHeight - 1); y >= 0; y--) {
            for (int x = 0; x < screenWidth; x++) {
                Math::Vector3D color = Math::Vector3D();

                for (int colorSample = 0; colorSample < maxColorSample; colorSample++) {
                    nx = double(x + drand48());
                    ny = double(y + drand48());
                    double u = nx / double(screenWidth);
                    double v = ny / double(screenHeight);
                    ray = this->_camera->getRay(u, v);
                    color += this->getColorRay(ray, {nx, ny}, 0);
                }
                color /= double(maxColorSample);
                color = Math::Vector3D(sqrt(color.getValues()[0][0]), sqrt(color.getValues()[0][1]), sqrt(color.getValues()[0][2]));
                ir = int(color.getValues()[0][0] * 255.99);
		        ig = int(color.getValues()[0][1] * 255.99);
		        ib = int(color.getValues()[0][2] * 255.99);
                this->_image.set({x, y}, Raytracer::Color(ir, ig, ib));
                displayIndex++;
                display.drawPoint(this->_image[x][y], x, y);
            }
        }
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
        std::cerr << "Missing required config in configuration file: " << e.what() << std::endl;
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
            this->_hittables.extend(objects);
        }
        if (primitiveSetting.exists("planes")) {
            objects = ObjectFactory::createPlanesSettings(primitiveSetting["planes"]);
            this->_hittables.extend(objects);
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
