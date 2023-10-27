#include "Cursor.h"
#include <SFML/Graphics.hpp>

Cursor::Cursor() {
    spriteFileName = "Sprites/Cursor.png";
    InitialiseSprite();
    sprite.setOrigin(16,16);
}

Cursor::~Cursor() {
}

void Cursor::UpdateSprite() {
    sprite.setPosition(positionX, positionY);
}

void Cursor::UpdatePosition(sf::RenderWindow* window, int windowWidth, int windowHeight) {
    sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
    if (localPosition.x < 0) localPosition.x = 0;
    if (localPosition.y < 0) localPosition.y = 0;

    if (localPosition.x > windowWidth) localPosition.x = windowWidth;
    if (localPosition.y > windowHeight) localPosition.y = windowHeight;

    positionX = localPosition.x;
    positionY = localPosition.y;

    UpdateSprite();
}