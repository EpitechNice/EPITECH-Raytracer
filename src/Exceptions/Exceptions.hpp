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

#define EXCEPTION_INFOS {std::string(__FUNCTION__), {std::string(__FILE__), __LINE__}}

namespace Exceptions
{
    class Exception: public std::exception
    {
        protected:
            std::string _what;
            std::pair<std::string, std::pair<std::string, std::size_t>> _position;
        public:
            Exception(std::string what = "An exception occured !",
                      std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}});
            std::string getClassName() const;
            std::pair<std::string, std::pair<std::string, std::size_t>> getInfos() const;
            const char* what() const noexcept override;
            friend std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj);
    };


    // ========== Errors ==========

    class InvalidSizeError: public Exceptions::Exception
    {
        public:
            InvalidSizeError(std::string what = "Provided position is not valid !",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class LogicError: public Exceptions::Exception
    {
        public:
            LogicError(std::string what = "Asked action is not logical",
                       std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class InvalidPositionError: public Exceptions::Exception
    {
        public:
            InvalidPositionError(std::string what = "The position does not belong in the matrix",
                       std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class MatrixSizeError: public Exceptions::Exception
    {
        public:
            MatrixSizeError(std::string what = "The Matrix sizes doesn't match for the asked operation",
                       std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class InvalidParsingSettingNotFound: public Exceptions::Exception
    {
        public:
            InvalidParsingSettingNotFound(std::string what = "Setting not found in configuration file.",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class InvalidParsingSettingInvalid: public Exceptions::Exception
    {
        public:
            InvalidParsingSettingInvalid(std::string what = "Incorrect setting type in configuration file.",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class OtherParsingError: public Exceptions::Exception
    {
        public:
            OtherParsingError(std::string what = "Error at line",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class CantOpenConfigFile: public Exceptions::Exception
    {
        public:
            CantOpenConfigFile(std::string what = "I/O error while reading file.",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    class InvalidRayError: public Exceptions::Exception
    {
        public:
            InvalidRayError(std::string what = "The ray does not belong here !",
                             std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };

    // ========== Warnings ==========

    class FileExtensionWarning: public Exceptions::Exception
    {
        public:
            FileExtensionWarning(std::string what = "Provided file have an unexpected extension.",
                                 std::pair<std::string, std::pair<std::string, std::size_t>> position = {"", {"", 0}}):
            Exceptions::Exception(what, position)
            {}
    };
}

#endif
