#include <iostream>
#include "Game.h"

int main()
{

    Game game;

    game.run();

    std::cout << "Plim plim plim o meu jogo faz assim" << std::endl;

    return 0;
}
float Player::moving_speed = 0.1;
float Player::jump_speed = 1;