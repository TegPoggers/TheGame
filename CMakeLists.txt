cmake_minimum_required(VERSION 3.20)
project(jogo)

set(CMAKE_CXX_STANDARD 20)
find_package(SFML 2.5 COMPONENTS graphics audio window system)

add_executable(jogo main.cpp  State.cpp State.h StateMachine.cpp StateMachine.h AssetManager.cpp AssetManager.h InputManager.cpp InputManager.h Game.cpp Game.h Definitions.h SplashState.cpp SplashState.h)

target_link_libraries(jogo sfml-graphics sfml-audio sfml-window sfml-system)