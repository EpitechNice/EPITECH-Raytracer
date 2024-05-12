/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

    #include "includes.hpp"
    #include "./Image/Image.hpp"
    #include "./Image/Colors.hpp"
    #include "./Math/Ray.hpp"
    #include "./Primitives/Sphere.hpp"

Math::Vector3D ray_color(const Raytracer::Objects::Sphere& sphere, const Math::Ray& r) {
    Math::Vector3D color;
    if (sphere.doesHit(r)) {
        color.set({0, 0}, 0xff);
        color.set({0, 1}, 0xff);
        color.set({0, 2}, 0xff);
        return color;
    }
    Math::Vector3D unit_direction = r.getDirection().normalised();
    auto a = 0.5 * (unit_direction[0][1] + 1.0);
    return Math::Vector3D(1.0, 1.0, 1.0) * (1.0 - a) + Math::Vector3D(0.5, 0.7, 1.0) * a;
}

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    Raytracer::Image img;
    Raytracer::Objects::Sphere s;
    return 0;
}

// int main()
// {
//     hittable_list world;

//     auto ground_material = make_shared<Matte>(color(0.5, 0.5, 0.5));
//     world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

//     for (int a = -11; a < 11; a++) {
//         for (int b = -11; b < 11; b++) {
//             auto choose_mat = random_double();
//             point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

//             if ((center - point3(4, 0.2, 0)).length() > 0.9) {
//                 shared_ptr<material> sphere_material;

//                 if (choose_mat < 0.8) {
//                     // diffuse
//                     auto albedo = color::random() * color::random();
//                     sphere_material = make_shared<Matte>(albedo);
//                     world.add(make_shared<sphere>(center, 0.2, sphere_material));
//                 } else if (choose_mat < 0.95) {
//                     // metal
//                     auto albedo = color::random(0.5, 1);
//                     auto fuzz = random_double(0, 0.5);
//                     sphere_material = make_shared<metal>(albedo, fuzz);
//                     world.add(make_shared<sphere>(center, 0.2, sphere_material));
//                 } else {
//                     // glass
//                     sphere_material = make_shared<dielectric>(1.5);
//                     world.add(make_shared<sphere>(center, 0.2, sphere_material));
//                 }
//             }
//         }
//     }

//     // auto material1 = make_shared<dielectric>(1.5);
//     // world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

//     // auto material2 = make_shared<Matte>(color(0.4, 0.2, 0.1));
//     // world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

//     // auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
//     // world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

//     camera cam;

//     cam.aspect_ratio      = 16.0 / 9.0;
//     cam.image_width       = 1200;
//     cam.samples_per_pixel = 500;
//     cam.max_depth         = 50;

//     cam.vfov     = 20;
//     cam.lookfrom = point3(13,2,3);
//     cam.lookat   = point3(0,0,0);
//     cam.vup      = Math::Vector3D(0,1,0);

//     cam.defocus_angle = 0.6;
//     cam.focus_dist    = 10.0;

//     cam.render(world);
// }