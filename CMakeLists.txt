cmake_minimum_required(VERSION 3.20)
project(
    raytracer
)

set(
    CMAKE_CXX_STANDARD 20
)

add_compile_options(
    -Wall -Wextra -Werror
)


set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    ${PROJECT_SOURCE_DIR}/raytracer
)

add_executable(raytracer
    src/main.cpp
)

target_include_directories(raytracer PUBLIC
    ./includes/
)

add_custom_command(TARGET raytracer
    POST_BUILD
    COMMAND
        cp raytracer ${PROJECT_SOURCE_DIR}/raytracer
)