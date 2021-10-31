#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "Game.h"

#include "Definitions.h"
int main(){
    //Esse height precisará ser mudado pra static pra aceitar diferentes tamanhos
    GameName::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Name");
    std::cout << "Hello, World!" << std::endl;
    return 0;
//Teste de comit com o clion
}
