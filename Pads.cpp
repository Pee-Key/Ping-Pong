#include "Pads.h"

Pads::Pads() {
    this->padThinkness = 10;
    this->padLength = 50;
    this->padspeed = 5.5;

    this->TL.x=padThinkness;
    this->TL.y=padLength;

    this->padL.setSize(sf::Vector2f(padThinkness,padLength));
    this->padL.setFillColor(sf::Color::White);
    this->padL.setPosition(55,375);

    this->padR.setSize(sf::Vector2f(padThinkness,padLength));
    this->padR.setFillColor(sf::Color::White);
    this->padR.setPosition(735,375);

}