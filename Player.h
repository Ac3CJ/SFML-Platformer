#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <string>

class Player : public Entity {
    private:
        // Positional Variables
        float positionX = 50;
        float positionY = 600;

        // Movement Scalars and Maximum (REMEMBER THAT NEGATIVE VALUES GO UP AND LEFT)
        float horizontalAccceleration = 4;
        float jumpAcceleration = -20;

        float horizontalVelocityMax = 20;
        float verticalVelocityMax = 100;

        // Resistive Forces
        float gravityAcceleration = 1.5;
        float frictionAcceleration = 1.5;

        float frictionMax = 5;

        // Movement Variables
        float playerVelocityY = 0, gravityVelocity = 0, totalVelocityY = 0;
        float playerVelocityX = 0, totalVelocityX = 0, frictionVelocity = 0;

        float playerAccelerationY = 0, playerAccelerationX = 0;
        // Movement Booleans
        bool moveLeft, moveRight, moveUp, moveDown, jump, horizontalMovementCheck;
        bool jumpCheck = false;

    public:
        Player();
        ~Player();

        void UpdateSprite();
        void UpdatePosition(int windowWidth, int windowHeight);
};

#endif