cmake_minimum_required(VERSION 3.5)
project(
    PROJECT_NAME
)

set(
    CMAKE_CXX_STANDARD 20
)

add_compile_options(
    -Wall -Wextra -Werror
)


set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    ${PROJECT_SOURCE_DIR}/PROJECT_NAME
)

add_executable(PROJECT_NAME
    src/main.cpp
)

target_include_directories(PROJECT_NAME PUBLIC
    ./includes/
)

add_custom_command(TARGET PROJECT_NAME
    POST_BUILD
    COMMAND
        cp PROJECT_NAME ${PROJECT_SOURCE_DIR}/PROJECT_NAME
)