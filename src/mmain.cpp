/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

#include "includes.hpp"

int main(int argc, char** argv) {
    std::string sceneConfigFile = argv[1];
    Raytracer::Core core(sceneConfigFile);
    return 0;
}
