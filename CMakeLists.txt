cmake_minimum_required(VERSION 3.20)
project(
    raytracer
)

set(
    CMAKE_CXX_STANDARD 20
)

set(
    CMAKE_CXX_ABI_COMPILED ON
)

add_compile_options(
    -Wall -Wextra -Werror
)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    ${PROJECT_SOURCE_DIR}/raytracer
)

add_executable(raytracer
    # src/main.cpp
    src/Core.cpp
    src/Exceptions/Exceptions.cpp
    src/Image.cpp
    src/Materials/Material.cpp
    src/Math/Math.cpp
    src/mmain.cpp
    src/Raytracer/Camera.cpp
    src/Raytracer/Colors.cpp
    src/Raytracer/Objects/Light.cpp
    src/Raytracer/Objects/Object.cpp
    src/Raytracer/Objects/Plane.cpp
    src/Raytracer/Objects/Sphere.cpp
    src/Raytracer/Ray.cpp
)

# target_include_directories(raytracer PUBLIC
#     ./includes/
#     ./includes/Exceptions/
#     ./includes/Materials/
#     ./includes/Math/
#     ./includes/Raytracer/
#     ./includes/Raytracer/Objects/
# )

target_link_libraries(raytracer
    config++
)

add_custom_command(TARGET raytracer
    POST_BUILD
    COMMAND
        cp raytracer ${PROJECT_SOURCE_DIR}/raytracer
)