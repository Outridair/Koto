cmake_minimum_required(VERSION 3.31)
project(koto)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

add_executable(koto src/main.cpp
        src/Game.cpp
        includes/Game.hpp
        src/Player.cpp
        includes/Player.hpp
        src/Tile.cpp
        includes/Tile.hpp
        src/Level.cpp
        includes/Level.hpp
        src/Enemy.cpp
        includes/Enemy.hpp
        includes/GameObject.hpp
        src/Camera.cpp
        includes/Camera.hpp
        src/Goal.cpp
        includes/Goal.hpp)

target_link_libraries(koto PRIVATE
        SDL2::SDL2            # brings in SDL2 headers & libs
        SDL2_ttf::SDL2_ttf    # brings in TTF headers & libs
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
)