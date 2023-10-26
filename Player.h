#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <string>

class Player : public Entity {
    private:
        float positionX;
        float positionY;

    public:
        Player();
        ~Player();

        void UpdateSprite();
        void UpdatePosition(int windowWidth, int windowHeight);
};

#endif