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

// ====================================================== MAIN ======================================================
int main() {
    int windowWidth = 1280;
    int windowHeight = 720;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Insert Game Name");

    // Test Spriting
    sf::Texture texture;
    if (!texture.loadFromFile("Sprites/Player.png")) return -1;

    sf::Sprite sprite;
    sprite.setTexture(texture);
    
    sprite.setOrigin(16,16);
    
    // Infinite loop for when the window is open
    while (window.isOpen()) {
        sf::Event event;

        // When the window is closed
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(sprite);
        // Input tests
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) sprite.rotate(-0.5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) sprite.rotate(0.5);
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
        sprite.setPosition(localPosition.x, localPosition.y);
        //std::cout << "X Position: " << std::to_string(localPosition.x) << "\n";
        //std::cout << "Y Position: " << std::to_string(localPosition.y) << "\n";

        window.display();
    }
    return 0;
}