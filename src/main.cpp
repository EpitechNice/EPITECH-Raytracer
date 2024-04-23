/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

#include "includes.hpp"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    Math::Point3D p(1, 1, 1);
    p += Math::Vector3D(1, 1, 1);
    std::cout << p << std::endl;
    p -= Math::Vector3D(2, 2, 2);
    std::cout << p << std::endl;
    std::cout << Math::Vector3D(1, 2, 3) << std::endl;
    return 0;
}
