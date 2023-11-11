#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>

class Player : public Entity {
    private:
        // Positional Variables
        float positionX = 50;
        float positionY = 600;

        // Movement Scalars and Maximum (REMEMBER THAT NEGATIVE VALUES GO UP AND LEFT)
        int horizontalAccceleration = 5;
        int jumpAcceleration = -6;
        int jumpTicks = 100;

        int horizontalVelocityMax = 20;
        int verticalVelocityMax = 100;

        // Resistive Forces
        float gravityAcceleration = 1.5;
        float frictionAcceleration = 1.5;

        float frictionMax = 5;

        // Movement Variables
        float playerVelocityY = 0, gravityVelocity = 0, totalVelocityY = 0;
        float playerVelocityX = 0, totalVelocityX = 0, frictionVelocity = 0;

        float playerAccelerationY = 0, playerAccelerationX = 0;

        // Other Variables
        bool moveLeft, moveRight, moveUp, moveDown, jump, horizontalMovementCheck;
        bool jumpCheck = false;
        int jumpTimer = 0;
        int previousJumpTime = 0;

    public:
        Player();
        ~Player();

        void UpdateSprite();
        void UpdatePosition(int windowWidth, int windowHeight);
};

#endif // PLAYER_HEADER