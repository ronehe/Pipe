#include <SFML/Graphics.hpp>
#include "Board.h"
#include <Windows.h>
#include "Controller.h"
#pragma once
int main() {
    Controller game;

    game.startGame();
    exit(EXIT_SUCCESS);
}