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
    src/Exceptions.cpp
    src/Math.cpp
    src/Colors.cpp
    src/Image.cpp
    src/Ray.cpp
    src/Core.cpp
    # src/main.cpp
    src/mmain.cpp
    src/Materials/Material.cpp
    src/Objects/Object.cpp
    src/Objects/Sphere.cpp
)

target_include_directories(raytracer PUBLIC
    ./includes/Materials/
    ./includes/Objects/
    ./includes/
)

target_link_libraries(raytracer
    config++
)

add_custom_command(TARGET raytracer
    POST_BUILD
    COMMAND
        cp raytracer ${PROJECT_SOURCE_DIR}/raytracer
)