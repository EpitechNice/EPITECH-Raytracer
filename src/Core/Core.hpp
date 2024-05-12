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

            // * Feel free to add any fun phrases you can think of ;)
            // Please note : Do not add anything the is against the Geneva convention, or violent, or could lead to a missunderstanding
            // Also, make sure your phrases are at least 14 chars long (else, it will mess up the display)

            std::vector<std::string> _motivations = {
                "Building NVidia drivers...",
                "Compiling shaders...",
                "Threading display...",
                "Calculating ASCII display...",
                "Painting Mona Lisa...",
            };
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
            Math::Vector3D getColorRay(Math::Ray& ray, int depth);
            Raytracer::Color checkRayHit(Math::Ray& ray, double distMin, double distMax, bool& doesHit, Raytracer::hitRecord& record) const;
            // bool checkRayHit(Math::Ray& ray, double distMin, double distMax) const;
            void render(double screenWidth, double screenHeight);
    };
}

#endif
