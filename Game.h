#ifndef PINGPONGGAME_GAME_H
#define PINGPONGGAME_GAME_H


class Game {
public:

    sf::Clock clock;

    void gameplay();

    void leftPadMove();

    void rightPadMove();

    void scoreShow(sf::RenderWindow &window);

    void botPadMove(sf::RenderWindow &window);

    void mainMenu(sf::RenderWindow &window);

    Game(Pads &pads, Ball &ball, Borders &bordersCollisions);

private:
    Pads &pads;
    Ball &ball;
    Borders &bordersCollisions;

    bool gamemode ; // true = player vs. comp
    int menuAction;
    bool isMenuNeed;


};

#include "Game.cpp"

#endif //PINGPONGGAME_GAME_H
