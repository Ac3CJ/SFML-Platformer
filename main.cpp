// =================================================================================================================
// File Name: main.cpp
// Summary: Main file for the game
// Description: Main file for the game 
// Version: 0.01V
// Date: 4/6/23
// Author: Conrad Gacay
// =================================================================================================================

// ===================================================== TO DO =====================================================

// =================================================================================================================

// ====================================================== LIBRARIES ======================================================
#include <SFML/Graphics.hpp>
#include <iostream>

// ====================================================== HEADER FILES ======================================================


// ====================================================== MAIN FILE ======================================================
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
        std::cout << "THIS IS A TEST! ";
    }
    return 0;
}