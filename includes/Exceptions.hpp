/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Wed, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Exceptions                                                                       *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_EXCEPTIONS_HPP
    #define INCLUDED_EXCEPTIONS_HPP

#include "headers.hpp"

#define FILE_INFOS {std::string(__FILE__), __LINE__}

namespace Exceptions
{
    class Exception: public std::exception
    {
        protected:
            std::string _what;
            std::pair<std::string, std::size_t> _position;
        public:
            Exception(std::string what = "An exception occured !",
                      std::pair<std::string, std::size_t> position = {"", 0});
            std::string get_class_name() const;
            std::pair<std::string, std::size_t> get_position() const;
            const char* what() const noexcept override;
    };

    std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj);

    class InvalidSizeError: public Exceptions::Exception
    {
        public:
            InvalidSizeError(std::string what = "Provided position is not valid !",
                               std::pair<std::string, std::size_t> position = {"", 0}):
            Exceptions::Exception(what, position)
            {}
    };

    class FileExtensionWarning: public Exceptions::Exception
    {
        public:
            FileExtensionWarning(std::string what = "Provided file have an unexpected extension.",
                               std::pair<std::string, std::size_t> position = {"", 0}):
            Exceptions::Exception(what, position)
            {}
    };
}

#endif
