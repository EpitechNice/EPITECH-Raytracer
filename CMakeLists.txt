cmake_minimum_required(VERSION 3.20)
project(
    raytracer
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

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
    src/Abstract/AObject.cpp
    src/Abstract/APrimitive.cpp
    src/Core/Core.cpp
    src/Exceptions/Exceptions.cpp
    src/Factory/ObjectFactory.cpp
    src/Image/Colors.cpp
    src/Image/Image.cpp
    src/Material/Material.cpp
    src/Math/Point3D.cpp
    src/Math/Ray.cpp
    src/Math/Vector3D.cpp
    src/mmain.cpp
    src/MultiThreading/Thread.cpp
    src/Objects/Camera.cpp
    src/Objects/Hitables.cpp
    src/Objects/Light.cpp
    src/Observer/FileObserver.cpp
    src/Primitives/Plane.cpp
    src/Primitives/Sphere.cpp
)


target_include_directories(raytracer PUBLIC
./includes/
)

target_link_libraries(raytracer
    config++
)

target_link_libraries(raytracer
    ${SDL2_LIBRARIES}
)

add_custom_command(TARGET raytracer
    POST_BUILD
    COMMAND
        cp raytracer ${PROJECT_SOURCE_DIR}/raytracer
)