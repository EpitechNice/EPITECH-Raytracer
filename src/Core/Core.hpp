/*                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Visual Studio Live Share (Workspace)                               *
 * Description     -                                                                    *
 *     Core                                                                             *
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

#ifndef INCLUDED_CORE_HPP
    #define INCLUDED_CORE_HPP

    #include "includes.hpp"

    #include "../Abstract/AObject.hpp"
    #include "../Abstract/APrimitive.hpp"
    #include "../Image/Colors.hpp"
    #include "../Image/Image.hpp"
    #include "../Math/Ray.hpp"
    #include "../Objects/Camera.hpp"
    #include "../Objects/Camera.hpp"
    #include "../Objects/Hittables.hpp"
    #include "../Objects/Light.hpp"
    #include "../Primitives/Plane.hpp"
    #include "../Primitives/Sphere.hpp"
    #include "../Factory/ObjectFactory.hpp"
    #include "../Math/Ray.hpp"
    #include "../Math/Point3D.hpp"
    #include "../Math/Vector3D.hpp"
    #include "../MultiThreads/Threads.hpp"

namespace Raytracer
{
    class Core
    {
        private:
            libconfig::Config _config;
            Raytracer::Hittables _hittables;
            std::vector<std::shared_ptr<Raytracer::AObject>> _lightList;
            std::unique_ptr<Raytracer::Camera> _camera;
            Image _image;
            hitRecord _record;
        protected:
        public:
            Core(int argc, char** argv);
            ~Core() = default;

            //Config
            void usage(std::string filename = "./raytracer", int status = 0);
            void setConfig(const std::string sceneFilePath);
            void loadConfig(const std::string sceneFilePath);
            void loadCamera();
            void loadPrimitive();
            void loadLight();

            //Renderer
            Math::Vector3D getColorRay(Math::Ray& ray, std::pair<size_t, size_t> pos, int depth);
            void render(double screenWidth, double screenHeight);
    };
}

#endif
