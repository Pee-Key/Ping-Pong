#ifndef PINGPONGGAME_BALL_H
#define PINGPONGGAME_BALL_H

#include "Pads.h"

class Ball {
public:

    sf::CircleShape ballShape;
    sf::FloatRect ballBound;

    void BallMove();

    int ballX;
    int ballY;
    float ballSpeed;
    float ballRadius;
    int scoreL;
    int scoreR;

    Ball(Pads &pads);

private:
    Pads &pads;
};

#include "Ball.cpp"

#endif //PINGPONGGAME_BALL_H
