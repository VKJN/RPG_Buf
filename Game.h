#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

class Game {
private:
	sf::RenderWindow window;
	Map map;
	Player player;

	void processEvents();
	void update();
	void render();

	int playerMoveDirection = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);

public:
	Game();
	void run();
};
