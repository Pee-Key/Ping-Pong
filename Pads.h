#ifndef PINGPONGGAME_PADS_H
#define PINGPONGGAME_PADS_H


class Pads {
public:

    sf::RectangleShape padL;
    sf::RectangleShape padR;

    sf::Vector2i TL;

    float padspeed;

    Pads();

private:
    int padThinkness;
    int padLength;

};

#include "Pads.cpp"

#endif //PINGPONGGAME_PADS_H
