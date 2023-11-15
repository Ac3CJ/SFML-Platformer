#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

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
    moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    //moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    //moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    horizontalMovementCheck = moveRight | moveLeft;

    jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    gravityVelocity += gravityAcceleration;
    if (gravityVelocity > verticalVelocityMax) gravityVelocity = verticalVelocityMax;
    
    playerAccelerationX = horizontalAccceleration;

    // Apply Window Limits
    if (positionX <= 0) {
        positionX = 0;
        moveLeft = 0;
        playerVelocityX = 0;
        frictionVelocity = 0;
    }
    if (positionX >= (windowWidth - spriteWidth)) {
        positionX = windowWidth - spriteWidth;
        moveRight = 0;
        playerVelocityX = 0;
        frictionVelocity = 0;
    }
    if (positionY <= 0) {
        positionY = 0;
        playerVelocityY = 0;
    }

    if (positionY >= (windowHeight - spriteHeight)) {
        positionY = windowHeight - spriteHeight;
        gravityVelocity = 0; 
        playerVelocityY = 0;
        jumpCheck = true;
    }

    // Velocity Calculations
    if (jumpCheck == true & jump == true & ((jumpTicks >= jumpTimer - previousJumpTime))) {
        playerAccelerationY = jumpAcceleration;
        jumpTimer = clock();
    }
    else {
        jumpCheck = false;
        playerAccelerationY = 0;
        previousJumpTime = clock();
    }

    playerVelocityY += playerAccelerationY;

    if ((moveRight != moveLeft) && (moveRight == true)) playerVelocityX += playerAccelerationX;
    if ((moveRight != moveLeft) && (moveLeft == true)) playerVelocityX -= playerAccelerationX;

    if (playerVelocityX > horizontalVelocityMax) playerVelocityX = horizontalVelocityMax;
    else if (playerVelocityX < -horizontalVelocityMax) playerVelocityX = -horizontalVelocityMax;

    if (horizontalMovementCheck == false) {
        playerAccelerationX = 0;
        if (totalVelocityX > 2) frictionVelocity -= frictionAcceleration;
        else if (totalVelocityX < -2) frictionVelocity += frictionAcceleration;
        else { 
            frictionVelocity = 0;
            playerVelocityX = 0;
        }
    }
    else frictionVelocity = 0;

    // Total Velocity Calculations
    totalVelocityY = playerVelocityY + gravityVelocity;

    totalVelocityX = playerVelocityX + frictionVelocity;

    // Update Positions
    positionX += totalVelocityX;
    positionY += totalVelocityY;

    UpdateSprite();
}