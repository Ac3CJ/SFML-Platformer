#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <string>

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::InitialiseSprite() {
    if (!texture.loadFromFile(spriteFileName)) throw "Sprite File Not Found";
    sprite.setTexture(texture);
    
    sf::FloatRect spriteLocalBounds = sprite.getLocalBounds();
    spriteWidth = spriteLocalBounds.width;
    spriteHeight = spriteLocalBounds.height;
}

sf::Sprite Entity::GetSprite() {
    return sprite;
}

void Entity::DrawSprite(sf::RenderWindow *window){
    window->draw(sprite);
}