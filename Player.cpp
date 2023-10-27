#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() {
    spriteFileName = "Sprites/Player.png";
    InitialiseSprite();
}

Player::~Player() {
}

void Player::UpdateSprite() {
    sprite.setPosition(positionX, positionY);
    //std::cout << "Y Pos: " << positionY << "\n";
}

void Player::UpdatePosition(int windowWidth, int windowHeight) {
    float velocityX, velocityY;
    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    //moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    //moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    gravityVelocity += gravityAcceleration;

    // Limits
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
        gravityVelocity = 0; 
        playerVelocityY = 0;
        jumpCheck = true;
    }

    if (jumpCheck == true & jump == true) {
        jumpCheck = false;
        playerAccelerationY = jumpAcceleration;
    }
    else {playerAccelerationY = 0;}

    // Velocity Calculations
    playerVelocityY += playerAccelerationY;

    totalVelocityY = playerVelocityY + gravityVelocity;

    velocityX = (moveRight - moveLeft) * horizontalAccceleration;

    positionX = positionX + velocityX;
    positionY += totalVelocityY;

    UpdateSprite();
}