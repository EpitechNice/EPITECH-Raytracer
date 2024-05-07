/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

    #include "includes.hpp"
    #include "./Core/Core.hpp"


// color ray_color(const ray& r) {
    // vec3 unit_direction = unit_vector(r.direction());
    // auto a = 0.5*(unit_direction.y() + 1.0);
    // return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
// }

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
