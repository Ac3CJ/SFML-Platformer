#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player() {
    spriteFileName = "Sprites/Player.png";
    InitialiseSprite();
}

Player::~Player() {
}

void Player::UpdateSprite() {
    sprite.setPosition(positionX, positionY);
}

void Player::UpdatePosition(int windowWidth, int windowHeight) {
    float velocityX, velocityY;
    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    //moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    //moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    velocityY += gravityAcceleration;

    if (positionX <= 0) {
        moveLeft = 0;
        velocityX = 0;
    }
    if (positionX >= (windowWidth - spriteWidth)) {
        velocityX = 0;
        moveRight = 0;
    }
    if (positionY <= 0) {
        moveUp = 0;
    }
    if (positionY >= (windowHeight - spriteHeight)) {
        velocityY = 0;
        moveDown = 0;
        jumpCheck = true;
    }

    velocityX = (moveRight - moveLeft) * horizontalAccceleration;
    if (jumpCheck == true & jump == true) {
        jumpCheck = false;
        velocityY += jumpAcceleration;
    }

    positionX = positionX + velocityX;
    positionY = positionY + velocityY;

    UpdateSprite();
}