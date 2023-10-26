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
    bool moveLeft, moveRight, moveUp, moveDown;

    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    if (positionX <= 0) moveLeft = 0;
    if (positionX >= (windowWidth - spriteWidth)) moveRight = 0;
    if (positionY <= 0) moveUp = 0;
    if (positionY >= (windowHeight - spriteHeight)) moveDown = 0;

    velocityX = (moveRight - moveLeft) * 10;
    velocityY = (moveDown - moveUp) * 10;
    positionX = positionX + velocityX;
    positionY = positionY + velocityY;

    UpdateSprite();
}