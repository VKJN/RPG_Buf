#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
	sf::RectangleShape player;
	sf::Texture texture;
public:
	Player();
	void move(int direction);
	void draw(sf::RenderWindow& window);
};