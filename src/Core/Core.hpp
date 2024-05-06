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
    #include "../Objects/Light.hpp"
    #include "../Primitives/Plane.hpp"
    #include "../Primitives/Sphere.hpp"

namespace Raytracer
{
    class Core
    {
        private:
            libconfig::Config _config;
            std::vector<std::shared_ptr<Raytracer::AObject>> _objectList;
            std::vector<std::shared_ptr<Raytracer::AObject>> _lightList;
            Raytracer::Camera _camera;
        protected:
        public:
            Core(int argc, char** argv);
            ~Core() = default;

            //Config
            void usage(std::string filename = "./raytracer", int status = 0);
            void setConfig(const std::string sceneFilePath);
            void loadConfig(const std::string sceneFilePath);
            void createCamera();
            void createPrimitive();
            void createLight();
            void DEBUGPrintAllObject();
            void DEBUGPrintCameraInfo();
            void DEBUGPrintAllLight();
    };
}

#endif

/*                                                                                      *
 * MIT License                                                                          *
 * Copyright (c) 2024 Anonymous                                                         *
 *                                                                                      *
 * Permission is hereby granted, free of charge, to any person obtaining a copy         *
 * of this software and associated documentation files (the "Software"), to deal        *
 * in the Software without restriction, including without limitation the rights         *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell            *
 * copies of the Software, and to permit persons to whom the Software is                *
 * furnished to do so, subject to the following conditions:                             *
 *                                                                                      *
 * The above copyright notice and this permission notice shall be included in all       *
 * copies or substantial portions of the Software.                                      *
 *                                                                                      *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR           *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,             *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE          *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER               *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,        *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE        *
 * SOFTWARE.                                                                            *
 *                                                                                      */
