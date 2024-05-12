/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Mon, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     FileObserver                                                                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "FileObserver.hpp"
#include <sys/stat.h>

namespace Threads
{
    FileObserver::FileObserver(std::string filename):
        _filename(filename), _running(false)
    {
        this->_thread = std::thread(&FileObserver::watchThread, this);
    }

    FileObserver::~FileObserver()
    {
        this->_running = false;
        if (this->_thread.joinable())
            this->_thread.join();
    }

    void FileObserver::watchThread()
    {
        struct stat attr;
        if (stat(this->_filename.c_str(), &attr) == -1)
            throw Exceptions::FileNotFoundError("Could not find file \"" + this->_filename + "\"", EXCEPTION_INFOS);

        this->_lastModifiedTime = attr.st_mtime;
        this->_running = true;

        while (this->_running) {
            stat(this->_filename.c_str(), &attr);
            if (attr.st_mtime != this->_lastModifiedTime)
                this->_lastModifiedTime = attr.st_mtime;
            usleep(this->WAIT_TIME);
        }
    }

    void FileObserver::stop()
    {
        this->_running = false;
    }

    void FileObserver::wait() const
    {
        while (!this->_running)
            usleep(this->WAIT_TIME);
        time_t currentModTime = this->_lastModifiedTime;
        while (this->_lastModifiedTime == currentModTime && this->_running)
            usleep(this->WAIT_TIME);
    }
}