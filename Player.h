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
        float horizontalAccceleration = 10;
        float jumpAcceleration = -50;

        float horizontalVelocityMax = 10;
        float verticalVelocityMax = 10;

        float gravityAcceleration = 5;

        // Movement Variables
        float gravityVelocity, playerVelocityX, playerVelocityY;
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