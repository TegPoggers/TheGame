cmake_minimum_required(VERSION 3.20)
project(jogo)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio window system)

add_executable(jogo main.cpp Game.cpp Game.h AssetManager.cpp AssetManager.h EventManager.cpp EventManager.h WindowManager.cpp WindowManager.h PlayState.cpp PlayState.h InputManager.cpp InputManager.h Player.cpp Player.h Entity.cpp Entity.h MovingEntity.cpp MovingEntity.h Being.cpp Being.h Projectile.cpp Projectile.h Element.h EntityList.cpp EntityList.h Level.cpp Level.h List.h Definitions.h HealthyForest.cpp HealthyForest.h InfectedForest.cpp InfectedForest.h)

target_link_libraries(jogo sfml-graphics sfml-audio sfml-window sfml-system)
