cmake_minimum_required(VERSION 3.20)
project(jogo)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio window system)

add_executable(jogo main.cpp Game.cpp Game.h AssetManager.cpp AssetManager.h EventManager.cpp EventManager.h WindowManager.cpp WindowManager.h PlayState.cpp PlayState.h)

target_link_libraries(jogo sfml-graphics sfml-audio sfml-window sfml-system)
