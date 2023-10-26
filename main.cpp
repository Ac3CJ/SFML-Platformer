// =================================================================================================================
// File Name: main.cpp
// Summary: Main file for the game
// Description: Main file for the game 
// Author: CJ
// =================================================================================================================

// ===================================================== TO DO =====================================================
// 3. Set up input keys WIP
// 5. Get tile maps
// 6. Set up Player object
// 7. Set up Entity object
// 8. Set up collision objects
// 9. Pray for no memory leaks
// 10. Set up Delta Time WIP
// 12. Get a gun sprite to point to the cursor
// 13. Find a way to set up the map collision objects
// =================================================================================================================

// ====================================================== LIBRARIES ======================================================
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdexcept>

// ====================================================== HEADER FILES ======================================================
#include "Entity.h"
#include "Player.h"

// ====================================================== SYSTEM VARIABLES ======================================================
const int fpsCap = 144,
          tickRate = 30;

// ====================================================== CLASSES ======================================================
// =======================================================================================
// =======================================================================================
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

// ====================================================== FUNCTIONS ======================================================
int deltaTime(int previous) {
    return (clock() - previous);
}

// ====================================================== MAIN ======================================================
int main() {
    int windowWidth = 1280,
        windowHeight = 720,
        offset = 0,
        previousTime = 0;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Insert Game Name");

    Cursor cursorObject;
    Player playerObject;
    
    // Infinite loop for when the window is open
    while (window.isOpen()) {
        sf::Event event;

        // When the window is closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    
        window.clear(sf::Color::Black);
        cursorObject.DrawSprite(&window);
        playerObject.DrawSprite(&window);
        int delta = deltaTime(previousTime) + offset;
        previousTime = clock();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) std::cout << "Left Mouse Press!\n";
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) std::cout << "Right Mouse Press!\n";
        
        for (int i = 0; i < delta / tickRate; i++) {
            cursorObject.UpdatePosition(&window, windowWidth, windowHeight);
            playerObject.UpdatePosition(windowWidth, windowHeight);
        }
        offset = delta % tickRate;
    
        window.display();
    }
    return 0;
}
