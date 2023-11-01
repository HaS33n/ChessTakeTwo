#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
#include "GameComponents.h"

class GameManager
{
public:
    GameManager(sf::RenderWindow& window);
    //~GameManager();
    void runGame();

private:
    void updateWindow();
    void handleMouse(sf::Vector2i mousepos);
    void handleKeyboard(sf::Keyboard::Key key);

    Square* board[8][8];
    Square* slctd;
    bool isWhite;

    sf::RenderWindow& window;
    ResourceManager RM;
    ConnectionManager CM;
    sf::Event event;
    MainMenu MM;
};