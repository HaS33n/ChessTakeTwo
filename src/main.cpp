#include <SFML/Graphics.hpp>
#include "../include/GameManager.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400,400), "Chezz"); 
	GameManager GM(window);
	GM.runGame();

	return 0;
}