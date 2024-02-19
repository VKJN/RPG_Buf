#include "Player.h"
#include <iostream>

Player::Player() {

	if (!texture.loadFromFile("./Image/Player.png")) std::cout << "texture not load";
	
	player.setTexture(&texture);

	player.setSize(sf::Vector2f(32.f, 32.f));
	player.setPosition(sf::Vector2f(9 * 32, 6 * 32));
}

void Player::move(int direction) {
	// 1 - up; 2 - right; 3 - down; 4 - left
	switch (direction) {
	case 1:
		player.move(sf::Vector2f(0, -32));
		break;
	case 2:
		player.move(sf::Vector2f(32, 0));
		break;
	case 3:
		player.move(sf::Vector2f(0, 32));
		break;
	case 4:
		player.move(sf::Vector2f(-32, 0));
		break;
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(player);
}
