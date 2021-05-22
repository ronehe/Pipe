#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <Windows.h>
#include "Controller.h"
#include <fstream>
#include <iostream>
int main() {
    try {
        Controller game;

        game.startGame();
    }
    catch(std::exception& e){
        std::ofstream file("log.txt");
        file << e.what();
    }
    exit(EXIT_SUCCESS);
}