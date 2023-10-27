#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <string>

class Player : public Entity {
    private:
        // Positional Variables
        float positionX = 50;
        float positionY = 500;

        // Movement Scalars and Maximum (REMEMBER THAT NEGATIVE VALUES GO UP AND LEFT)
        float horizontalAccceleration = 1;
        float jumpAcceleration = -20;

        float horizontalVelocityMax = 10;
        float verticalVelocityMax = 10;

        float gravityAcceleration = 1;

        // Movement Variables
        float playerVelocityY = 0, gravityVelocity = 0, totalVelocityY = 0;
        float playerVelocityX = 0, totalVelocityX = 0;

        float playerAccelerationY = 0, playerAccelerationX = 0;
        // Movement Booleans
        bool moveLeft, moveRight, moveUp, moveDown, jump;
        bool jumpCheck = false;

    public:
        Player();
        ~Player();

        void UpdateSprite();
        void UpdatePosition(int windowWidth, int windowHeight);
};

#endif