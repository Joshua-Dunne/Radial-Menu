#ifndef RADIAL_H
#define RADIAL_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Xbox360Controller.h"

class Radial
{
public:
	Radial();
	Radial(sf::Vector2f t_pos);

	enum class RadialState {NEUTRAL, UP, DOWN, LEFT, RIGHT};

private:

	sf::Texture m_radialTex;
	sf::Sprite m_radialSprite;

	sf::IntRect m_radialMid;
	sf::IntRect m_radialUp;
	sf::IntRect m_radialDown;
	sf::IntRect m_radialLeft;
	sf::IntRect m_radialRight;

	RadialState m_radialCurrent{ RadialState::NEUTRAL };

public:

	void processInput(Xbox360Controller t_controller);
	void drawRadial(sf::RenderWindow& t_window);
};

#endif