// =================================================================================================================
// File Name: main.cpp
// Summary: Main file for the game
// Description: Main file for the game 
// Version: 0.01V
// Date: 4/6/23
// Author: Conrad Gacay
// =================================================================================================================

// ===================================================== TO DO =====================================================
// 1. Get the inputs from mouse
// 2. Get inputs from keyboard
// 3. Set up input keys
// 4. Get sprites
// 5. Get tile maps
// 6. Set up Player object
// 7. Set up Entity object
// 8. Set up collision objects
// 9. Pray for no memory leaks
// 10. Set up Delta Time
// =================================================================================================================

// ====================================================== LIBRARIES ======================================================
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdexcept>

// ====================================================== HEADER FILES ======================================================

// ====================================================== CLASSES ======================================================
class Entity {
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        std::string spriteFileName;

        void InitialiseSprite();
    public:
        Entity();
        ~Entity();

        sf::Sprite GetSprite();
        void DrawSprite(sf::RenderWindow* window);
};

Entity::Entity() {
}

Entity::~Entity() {
}

void Entity::InitialiseSprite() {
    if (!texture.loadFromFile(spriteFileName)) throw "Sprite File Not Found";
    sprite.setTexture(texture);
    sprite.setOrigin(16,16);
}

sf::Sprite Entity::GetSprite() {
    return sprite;
}

void Entity::DrawSprite(sf::RenderWindow *window){
    window->draw(sprite);
}

class Player : public Entity {
    public:
        Player();
        ~Player();
};

Player::Player() {
    spriteFileName = "Sprites/Player.png";
    InitialiseSprite();
}

Player::~Player() {
}

class Cursor : public Entity{
    public:
        Cursor();
        ~Cursor();

        void UpdatePosition(int localPositionX, int localPositionY);
};

Cursor::Cursor() {
    spriteFileName = "Sprites/Cursor.png";
    InitialiseSprite();
}

Cursor::~Cursor() {
}

void Cursor::UpdatePosition(int localPositionX, int localPositionY) {
    sprite.setPosition(localPositionX, localPositionY);
}


// ====================================================== MAIN ======================================================
int main() {
    int windowWidth = 1280;
    int windowHeight = 720;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Insert Game Name");

    Cursor cursorObject;
    // Test Spriting
    /*sf::Texture texture;
    if (!texture.loadFromFile("Sprites/Cursor.png")) return -1;

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    sprite.setOrigin(16,16);*/
    
    // Infinite loop for when the window is open
    while (window.isOpen()) {
        sf::Event event;

        // When the window is closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::Black);
        //window.draw(sprite);
        //window.draw(cursorObject.GetSprite());
        cursorObject.DrawSprite(&window);

        // Input tests
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.rotate(-0.5);
        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.rotate(0.5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) std::cout << "W Key Pressed!\n";
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) std::cout << "S Key Pressed!\n";

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) std::cout << "Left Mouse Press!\n";
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) std::cout << "Right Mouse Press!\n";

        // Check Mouse Position and Limit Range
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        if (localPosition.x < 0) localPosition.x = 0;
        if (localPosition.y < 0) localPosition.y = 0;

        if (localPosition.x > windowWidth) localPosition.x = windowWidth;
        if (localPosition.y > windowHeight) localPosition.y = windowHeight;

        cursorObject.UpdatePosition(localPosition.x, localPosition.y);
        //sprite.setPosition(localPosition.x, localPosition.y);
        //std::cout << "X Position: " << std::to_string(localPosition.x) << "\n";
        //std::cout << "Y Position: " << std::to_string(localPosition.y) << "\n";

        window.display();
    }
    return 0;
}