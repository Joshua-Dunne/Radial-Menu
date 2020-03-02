#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Radial.h"

class Game
{
public:
	Game();

private:
	Xbox360Controller m_controller;
	Radial m_dial;
	sf::RenderWindow m_window;

public:
	void run();
	void processKeys();
	void update(sf::Time dt);
	void render();
};

#endif