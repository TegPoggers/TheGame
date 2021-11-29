//
// Created by segalle on 31/10/2021.
//

#ifndef JOGO_DEFINITIONS_H
#define JOGO_DEFINITIONS_H

//Fontes
#define FONT_1 "../Assets/Fonts/MagicSchoolOne.ttf"
#define FONT_2 "../Assets/Fonts/MagicSchoolTwo-4n5D.ttf"
#define FONT_3 "../Assets/Fonts/Metamorphous.ttf"

//Backgrounds
#define HEALTHY_FOREST "../Assets/Backgrounds/HealthyForest.png"
#define INFECTED_FOREST "../Assets/Backgrounds/InfectedForest.png"

//Obstáculos
#define FIRE_PIT "../Assets/Obstacles/FirePit.png"
#define POINTY_BUSH "../Assets/Obstacles/PointyBush.png"
#define SPIKES_PATH "../Assets/Obstacles/Spikes.png"

//Projéteis
#define DARK_ENERGY_ORB "../Assets/Projectiles/DarkEnergyOrb.png"
#define PLAYER_ORB "../Assets/Projectiles/PlayerOrb.png"
#define ENERGY_ORB "../Assets/Projectiles/BlueEnergyOrb.png"

//Player
#define PLAYER_1 "../Assets/Players/player1.png"
#define PLAYER_2 "../Assets/Players/player2.png"

//Inimigos
#define WEAK_GOBLIN "../Assets/Enemies/WeakGoblin.png"
#define STRONG_GOBLIN "../Assets/Enemies/StrongGoblin.png"
#define BOSS_GOBLIN "../Assets/Enemies/BossGoblin.png"

//Marcação de final
#define END_LEVEL_CASTLE "../Assets/LevelComplete/EndLevelCastle.png"

#define FAILED_TEXTURE "../Assets/Failed/FailedTexture.jpg"

#define MENU_BACKGROUND "../Assets/Backgrounds/Menu.png"

#define END_LEVEL_CASTLE "../Assets/LevelComplete/EndLevelCastle.png"

//O jogo roda em 1366 x 768 então toda textura em 1080p deve ser rodada nessa escala
#define GLOBAL_SCALE 0.7111111

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

//Para spawn de entidades no level
#define POSITION_MAX 13300
#define POSITION_MIN 800

#define RAND_ENTITIES 3

#define BOSS_POSITION 14100
#define DOOR_POSITION 15100

#define MENU_ITENS 4
#define GLOBAL_MENU_ITENS 4
#define PLAYER_MENU_ITENS 4
#define LEADERBOARD_ITEMS 2
#define SCORES_MAX 10

#define STATES_NUMBER 3

#endif //JOGO_DEFINITIONS_H
