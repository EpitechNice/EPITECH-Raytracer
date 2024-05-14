/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

    #include "includes.hpp"
    #include "./Core/Core.hpp"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    try {
        Raytracer::Core core(argc, argv);
    } catch (const Exceptions::Exception& e) {
        std::cerr << e << std::endl;
        return 84;
    }
    return 0;
}
