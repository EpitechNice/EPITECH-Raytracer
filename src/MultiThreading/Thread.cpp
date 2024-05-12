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

#include "Thread.hpp"

namespace Threads
{
    ShowThread::ShowThread(std::size_t maxStatus, std::size_t& currentStatus, int width, int height):
        _maxStatus(maxStatus),
        _currentStatus(currentStatus),
        _width(width),
        _height(height),
        _running(false)
    {
        this->_thread = std::thread(&ShowThread::run, this);
    }

    ShowThread::~ShowThread()
    {
        this->stop();
        if (this->_thread.joinable())
            this->_thread.join();
    }

    void ShowThread::run()
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
        SDL_Init(SDL_INIT_EVERYTHING);
        this->_window = SDL_CreateWindow("Live display", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                         this->_width, this->_height, SDL_WINDOW_SHOWN);
        this->_renderer = SDL_CreateRenderer(this->_window,
                                             -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawBlendMode(this->_renderer, SDL_BLENDMODE_BLEND);
        this->_running = true;

        this->_screensize.x = 0;
        this->_screensize.y = 0;

        this->_screensize.w = this->_width;
        this->_screensize.h = this->_height;

        this->_screen = SDL_CreateTexture(this->_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->_width, this->_height);
        SDL_SetRenderTarget(this->_renderer, NULL);
        SDL_RenderCopy(this->_renderer, this->_screen, &this->_screensize, &this->_screensize);
        SDL_RenderPresent(this->_renderer);
        SDL_SetRenderTarget(this->_renderer, this->_screen);

        std::stringstream display;

        while (this->_running) {
            usleep(10000);

            this->_usePoints.lock();
            if (this->_pointsToSet.size()) {
                for (std::size_t i = 0; i < this->_pointsToSet.size(); i++) {
                    SDL_SetRenderDrawColor(this->_renderer, this->_pointsToSet[i].second[0][0], this->_pointsToSet[i].second[0][1], this->_pointsToSet[i].second[0][2], SDL_ALPHA_OPAQUE);
                    SDL_RenderDrawPoint(this->_renderer, this->_width - this->_pointsToSet[i].first.first, this->_height - this->_pointsToSet[i].first.second);
                }
                this->_pointsToSet.clear();
            }
            this->_usePoints.unlock();

            if (!(rand() % 300) && this->_phrases.size()) {
                std::size_t index = rand() % this->_phrases.size();
                std::cout << "\r[======] " << this->_phrases[index] << std::endl;
                this->_phrases.erase(this->_phrases.begin() + index);
            }

            display << "\r[" << std::setw(3) << std::setfill(' ') << (this->_currentStatus * 100 / this->_maxStatus) << "%] Building image...";

            std::cout << display.str() << std::flush;
            display.clear();
            ShowThread::loop();
        }
    }

    void ShowThread::drawPoint(const Raytracer::Color& color, int x, int y)
    {
        this->_usePoints.lock();
        this->_pointsToSet.push_back({{x, y}, color});
        this->_usePoints.unlock();
    }

    void ShowThread::stop()
    {
        this->_running = false;
        SDL_DestroyRenderer(this->_renderer);
        SDL_DestroyTexture(this->_screen);
        SDL_DestroyWindow(this->_window);
        SDL_Quit();
    }

    void ShowThread::loop()
    {
        SDL_SetRenderTarget(this->_renderer, nullptr);
        SDL_RenderCopy(this->_renderer, this->_screen, &this->_screensize, &this->_screensize);
        SDL_RenderPresent(this->_renderer);

        while (SDL_PollEvent(&this->_event))
            if (this->_event.type == SDL_QUIT)
                this->_running = false;
        SDL_SetRenderTarget(this->_renderer, this->_screen);
    }

    void ShowThread::fg()
    {
        this->_thread.join();
    }
}