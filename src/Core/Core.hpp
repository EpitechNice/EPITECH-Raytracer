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
    #include "../Factory/ObjectFactory.hpp"
    #include "../Image/Colors.hpp"
    #include "../Image/Image.hpp"
    #include "../Math/Point3D.hpp"
    #include "../Math/Ray.hpp"
    #include "../Math/Ray.hpp"
    #include "../Math/Vector3D.hpp"
    #include "../MultiThreading/Thread.hpp"
    #include "../Objects/Camera.hpp"
    #include "../Objects/Camera.hpp"
    #include "../Objects/Hitables.hpp"
    #include "../Objects/Light.hpp"
    #include "../Primitives/Plane.hpp"
    #include "../Primitives/Sphere.hpp"

namespace Raytracer
{
    class Core
    {
        private:
            libconfig::Config _config;
            // std::vector<std::shared_ptr<Raytracer::APrimitive>> _primitiveList;
            Raytracer::Hitables _hitables;
            std::vector<std::shared_ptr<Raytracer::AObject>> _lightList;
            std::unique_ptr<Raytracer::Camera> _camera;

            // const std::map<std::string, ConfigBuilder> _acceptedPrimitives = {
            //     {"spheres", ConfigBuilder(ObjectFactory::createSpheresSettings)},
            //     {"planes", ConfigBuilder(ObjectFactory::createPlanesSettings)},
            // };

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
            Raytracer::Color getColorRay(Math::Ray& ray, int depth);
            Raytracer::Color checkRayHit(Math::Ray& ray, double distMin, double distMax, bool& doesHit, Raytracer::hitRecord& record) const;
            // bool checkRayHit(Math::Ray& ray, double distMin, double distMax) const;
            void render(double screenWidth, double screenHeight);
    };
}

#endif
