cmake_minimum_required(VERSION 3.20)
project(jogo)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio window system)

add_executable(jogo main.cpp Game.cpp Game.h AssetManager.cpp AssetManager.h EventManager.cpp EventManager.h WindowManager.cpp WindowManager.h
        InputManager.cpp InputManager.h Player.cpp Player.h Entity.cpp Entity.h MovingEntity.cpp MovingEntity.h Being.cpp
        Being.h Projectile.cpp Projectile.h Element.h EntityList.cpp EntityList.h Level.cpp Level.h List.h Definitions.h HealthyForest.cpp
        HealthyForest.h InfectedForest.cpp InfectedForest.h Enemy.cpp Enemy.h WeakGoblin.cpp WeakGoblin.h StrongGoblin.cpp StrongGoblin.h
        BossGoblin.cpp BossGoblin.h StaticEntity.cpp StaticEntity.h Spikes.cpp Spikes.h FirePit.cpp FirePit.h PointyBush.cpp PointyBush.h Star.cpp Star.h DarkEnergyOrb.cpp DarkEnergyOrb.h EnergyOrb.cpp EnergyOrb.h SpriteLoader.cpp SpriteLoader.h CollisionManager.cpp CollisionManager.h PlayerCollision.cpp PlayerCollision.h)

target_link_libraries(jogo sfml-graphics sfml-audio sfml-window sfml-system)
