#include <SFML/Graphics.hpp>
#include "Board.h"
#include <Windows.h>
#include "Controller.h"
#pragma once
int main() {
    Controller game;

    game.start_Game();
    //std::cout << "hello world";
    exit(EXIT_SUCCESS);
}