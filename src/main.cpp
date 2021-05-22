#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <Windows.h>
#include "Controller.h"
int main() {
    try {
        Controller game;

        game.startGame();
    }
    catch(std::exception& e){
        std::cout << e.what();
    }
    exit(EXIT_SUCCESS);
}