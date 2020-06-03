#include <SFML/Graphics.hpp>
#include <iostream>
#include "Borders.h"
#include "Ball.h"
#include "Pads.h"
#include "Game.h"


int main() {

    Borders bordersCollisions;
    Pads pads;
    Ball ball(pads);
    Game game(pads,ball, bordersCollisions);

    game.gameplay();

    return 0;
}
