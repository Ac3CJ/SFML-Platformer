#ifndef CURSOR_HEADER
#define CURSOR_HEADER

#include "Entity.h"

#include <SFML/Graphics.hpp>
#include <string>

class Cursor : public Entity{
    private:
        int positionX;
        int positionY;

    public:
        Cursor();
        ~Cursor();

        void UpdateSprite();
        void UpdatePosition(sf::RenderWindow* window, int windowWidth, int windowHeight);
};

#endif