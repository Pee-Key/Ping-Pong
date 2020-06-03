#include "Ball.h"

Ball::Ball(Pads &pads) : pads(pads) {

    this->ballX = -1;
    this->ballY = 1;
    this->ballSpeed = 5;
    this->ballRadius = 10;
    this->scoreL = 0;
    this->scoreR = 0;

    this->ballShape.setRadius(ballRadius);
    this->ballShape.setFillColor(sf::Color::White);
    this->ballShape.setPosition(390, 450);

    this->ballBound = ballShape.getGlobalBounds();
}

void Ball::BallMove() {
    ballShape.move(ballX * ballSpeed, ballY * ballSpeed);

    if (ballShape.getPosition().y + ballRadius == 740) {
        ballY = -1;
    }
    if (ballShape.getPosition().y + ballRadius == 50) {
        ballY = 1;
    }
    if (ballShape.getPosition().x == 50) {
        scoreR = scoreR + 1;
        ballShape.setPosition(400, 400);
        ballX = 1;
    }
    if (ballShape.getPosition().x + ballRadius == 750) {
        scoreL = scoreL + 1;
        ballShape.setPosition(400, 400);
        ballX = -1;
    }
}