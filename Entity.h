#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        std::string spriteFileName;
        int spriteWidth;
        int spriteHeight;

        void InitialiseSprite();
    public:
        Entity();
        ~Entity();

        sf::Sprite GetSprite();
        void DrawSprite(sf::RenderWindow* window);
};

#endif