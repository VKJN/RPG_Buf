#pragma once
#include <SFML/Graphics.hpp>

class Player {
private:
	sf::RectangleShape player;
	sf::Texture playerTexture;

	sf::Texture inventoryTexture;
	sf::RectangleShape inventory;
public:
	Player(sf::Vector2f startPosition);
	void move(int direction);
	void draw(sf::RenderWindow& window);
	void drawInventory(sf::RenderWindow& window);
	void setTexture(std::string path);
	sf::Vector2f getPosition();
};