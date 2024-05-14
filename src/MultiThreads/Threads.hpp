/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Thread                                                                           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_THREAD_HPP
    #define INCLUDED_THREAD_HPP

    #include "headers.hpp"
    #include "../Image/Image.hpp"

    #include <SDL2/SDL.h>

namespace Threads
{
    class ShowThread
    {
        private:
            std::size_t  _maxStatus;
            std::size_t& _currentStatus;

            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Rect _screensize;
            SDL_Texture *_screen;
            SDL_Event _event;

            int _width;
            int _height;

            bool _running;

            std::thread _thread;

            void run();

            std::mutex _usePoints;
            std::vector<std::pair<std::pair<std::size_t, std::size_t>, Raytracer::Color>> _pointsToSet;

            // * Feel free to add any fun phrases you can think of ;)
            // Please note : Do not add anything the is against the Geneva convention, or violent, or could lead to a missunderstanding
            // Also, make sure your phrases are at least 17 chars long (else, it will mess up the display)

            std::vector<std::string> _phrases = {
                "Building NVidia drivers...",
                "Compiling shaders...",
                "Threading display...",
                "Calculating ASCII display...",
                "Painting Mona Lisa...",
            };

        public:
            ~ShowThread();
            ShowThread(std::size_t maxStatus, std::size_t& currentStatus, int width, int height);

            void drawPoint(const Raytracer::Color& color, int x, int y);

            void stop();
            void loop();
            void fg();
    };
}

#endif