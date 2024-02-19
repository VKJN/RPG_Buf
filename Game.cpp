#include "Game.h"
#include <Windows.h>

Game::Game()
	: window(sf::VideoMode(960, 640), "RPG game"),
	player(),
	map(960, 640)
{

}

void Game::processEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			playerMoveDirection = 1;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			playerMoveDirection = 2;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			playerMoveDirection = 3;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			playerMoveDirection = 4;
		}

		else {
			playerMoveDirection = 0;
		}
	}
}

void Game::update() {
	switch (playerMoveDirection) {
	case 1:
		player.move(1);
		break;
	case 2:
		player.move(2);
		break;
	case 3:
		player.move(3);
		break;
	case 4:
		player.move(4);
		break;
	}
	Sleep(TimePerFrame.asSeconds());
}

void Game::render() {
	window.clear();
	map.draw(window);
	player.draw(window);
	window.display();
}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen()) {
		processEvents();
		timeSinceLastUpdate += clock.restart();

		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update();
		}

		render();
	}
}