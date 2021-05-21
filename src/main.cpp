#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <Windows.h>
#include "Controller.h"
int main() {
    Controller game;

    game.startGame();
    exit(EXIT_SUCCESS);
}