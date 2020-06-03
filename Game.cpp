#include "Game.h"

Game::Game(Pads &pads, Ball &ball, Borders &bordersCollisions) : pads(pads), ball(ball),
                                                                 bordersCollisions(bordersCollisions) {
    this->gamemode = true;
    this->menuAction = 0;
    this->isMenuNeed = true;
}

void Game::gameplay() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "PING-PONG");
    window.setFramerateLimit(60);


    while (window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 400;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        if (isMenuNeed == true) {
            mainMenu(window);
        }

        if(gamemode == true){
            leftPadMove();
            botPadMove(window);
        } else{
            leftPadMove();
            rightPadMove();
        }

        if (ball.scoreL == 11 || ball.scoreR == 11){
            isMenuNeed = true;
            ball.scoreL = 0;
            ball.scoreR = 0;
        }


        sf::IntRect rectL(pads.padL.getPosition().x, pads.padL.getPosition().y, 10, 50);
        sf::IntRect rectR(pads.padR.getPosition().x, pads.padR.getPosition().y, 10, 50);

        if (rectL.contains(ball.ballShape.getPosition().x, ball.ballShape.getPosition().y)) {
            ball.ballX = 1;
        }
        if (rectR.contains(ball.ballShape.getPosition().x + ball.ballRadius, ball.ballShape.getPosition().y)) {
            ball.ballX = -1;
        }

        ball.BallMove();

        window.clear();

        window.draw(bordersCollisions.fieldBorder);
        scoreShow(window);
        window.draw(pads.padL);
        window.draw(pads.padR);
        window.draw(ball.ballShape);

        window.display();
    }

}

void Game::botPadMove(sf::RenderWindow &window) {
    if (ball.ballShape.getPosition().x > window.getSize().x / 2) {
        if (ball.ballShape.getPosition().y - ball.ballRadius < pads.padR.getPosition().y &&
            pads.padR.getPosition().y > 50) {
            pads.padR.move(0, -1 * pads.padspeed);
        }
        if (ball.ballShape.getPosition().y - ball.ballRadius > pads.padR.getPosition().y &&
            pads.padR.getPosition().y < 700) {
            pads.padR.move(0, 1 * pads.padspeed);
        }
    }
}

void Game::leftPadMove() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && pads.padL.getPosition().y < 700) {
        pads.padL.move(0, 1 * pads.padspeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pads.padL.getPosition().y > 50) {
        pads.padL.move(0, -1 * pads.padspeed);
    }
}

void Game::rightPadMove() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pads.padR.getPosition().y < 700) {
        pads.padR.move(0, 1 * pads.padspeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pads.padR.getPosition().y > 50) {
        pads.padR.move(0, -1 * pads.padspeed);
    }
}

void Game::scoreShow(sf::RenderWindow &window) {
    sf::Texture score;
    score.loadFromFile("C:/Users/USER/CLionProjects/po/PingPongGame/segment_povorot.png");
    sf::Sprite scoreL;
    scoreL.setTexture(score);
    sf::Sprite scoreR;
    scoreR.setTexture(score);

    sf::Sprite dash;
    dash.setTexture(score);
    dash.setTextureRect(sf::IntRect(1450, 2, 100, 216));

    switch (ball.scoreL) {
        case 1:
            scoreL.setTextureRect(sf::IntRect(1194, 2, 104, 216));
            break;
        case 2:
            scoreL.setTextureRect(sf::IntRect(1080, 2, 104, 216));
            break;
        case 3:
            scoreL.setTextureRect(sf::IntRect(968, 2, 104, 216));
            break;
        case 4:
            scoreL.setTextureRect(sf::IntRect(860, 2, 104, 216));
            break;
        case 5:
            scoreL.setTextureRect(sf::IntRect(750, 2, 104, 216));
            break;
        case 6:
            scoreL.setTextureRect(sf::IntRect(639, 2, 104, 216));
            break;
        case 7:
            scoreL.setTextureRect(sf::IntRect(530, 2, 104, 216));
            break;
        case 8:
            scoreL.setTextureRect(sf::IntRect(418, 2, 104, 216));
            break;
        case 9:
            scoreL.setTextureRect(sf::IntRect(308, 2, 104, 216));
            break;
        case 10:
            scoreL.setTextureRect(sf::IntRect(150, 2, 158, 216));
            break;
        case 11:
            scoreL.setTextureRect(sf::IntRect(35, 2, 115, 216));
            break;
        default:
            scoreL.setTextureRect(sf::IntRect(1301, 2, 115, 213));

    }
    switch (ball.scoreR) {
        case 1:
            scoreR.setTextureRect(sf::IntRect(1194, 2, 104, 216));
            break;
        case 2:
            scoreR.setTextureRect(sf::IntRect(1080, 2, 104, 216));
            break;
        case 3:
            scoreR.setTextureRect(sf::IntRect(968, 2, 104, 216));
            break;
        case 4:
            scoreR.setTextureRect(sf::IntRect(860, 2, 104, 216));
            break;
        case 5:
            scoreR.setTextureRect(sf::IntRect(750, 2, 104, 216));
            break;
        case 6:
            scoreR.setTextureRect(sf::IntRect(639, 2, 104, 216));
            break;
        case 7:
            scoreR.setTextureRect(sf::IntRect(530, 2, 104, 216));
            break;
        case 8:
            scoreR.setTextureRect(sf::IntRect(418, 2, 104, 216));
            break;
        case 9:
            scoreR.setTextureRect(sf::IntRect(308, 2, 104, 216));
            break;
        case 10:
            scoreR.setTextureRect(sf::IntRect(150, 2, 158, 216));
            break;
        case 11:
            scoreR.setTextureRect(sf::IntRect(35, 2, 115, 216));
            break;
        default:
            scoreR.setTextureRect(sf::IntRect(1301, 2, 115, 213));

    }
    scoreL.setPosition(224, 50);
    dash.setPosition(350, 50);
    scoreR.setPosition(450, 50);

    window.draw(scoreL);
    window.draw(dash);
    window.draw(scoreR);

}

void Game::mainMenu(sf::RenderWindow &window) {
    sf::Texture PVP;
    PVP.loadFromFile("C:/Users/USER/CLionProjects/po/PingPongGame/PVP.png");
    sf::Sprite PVPs;
    PVPs.setTexture(PVP);
    sf::Texture PVC;
    PVC.loadFromFile("C:/Users/USER/CLionProjects/po/PingPongGame/PVC.png");
    sf::Sprite PVCs;
    PVCs.setTexture(PVC);
    sf::Texture QUIT;
    QUIT.loadFromFile("C:/Users/USER/CLionProjects/po/PingPongGame/QUIT.png");
    sf::Sprite QUITs;
    QUITs.setTexture(QUIT);
    PVPs.setPosition(248, 400);
    PVCs.setPosition(161, 119);
    QUITs.setPosition(276, 621);

    while (isMenuNeed == true) {
        PVPs.setColor(sf::Color::White);
        PVCs.setColor(sf::Color::White);
        QUITs.setColor(sf::Color::White);

        if (sf::IntRect(161,119,478,162).contains(sf::Mouse::getPosition(window))){
            PVCs.setColor(sf::Color::Red);
            menuAction =1;
        }
        if (sf::IntRect(248,400,304,102).contains(sf::Mouse::getPosition(window))){
            PVPs.setColor(sf::Color::Red);
            menuAction =2;
        }
        if (sf::IntRect(276,621,247,59).contains(sf::Mouse::getPosition(window))){
            QUITs.setColor(sf::Color::Red);
            menuAction =3;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if (menuAction == 1){isMenuNeed = false; gamemode = true;}
            if (menuAction == 2){isMenuNeed = false; gamemode = false;}
            if (menuAction == 3){window.close();isMenuNeed = false;}
        }
        window.clear();

        window.draw(PVCs);
        window.draw(PVPs);
        window.draw(QUITs);

        window.display();
    }
}