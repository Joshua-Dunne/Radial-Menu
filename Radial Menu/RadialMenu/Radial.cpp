#include "Radial.h"

Radial::Radial() : 
	m_radialUp(0,0,257,257), 
	m_radialRight(257,0,257,257), 
	m_radialDown(0,257,257,257), 
	m_radialLeft(257,257,257,257), 
	m_radialMid(0,517,257,257)
{
	if (m_radialTex.loadFromFile("resources/img/radialTex.png"))
	{
		std::cerr << "problem loading radial texture in resources/img/radialTex.png" << std::endl;
	}

	m_radialSprite.setTexture(m_radialTex);
	m_radialSprite.setTextureRect(m_radialMid);
}

Radial::Radial(sf::Vector2f t_pos) :
	m_radialUp(0, 0, 257, 257),
	m_radialRight(257, 0, 257, 257),
	m_radialDown(0, 257, 257, 257),
	m_radialLeft(257, 257, 257, 257),
	m_radialMid(0, 517, 257, 257)
{
	if (!m_radialTex.loadFromFile("resources/img/radialTex.png"))
	{
		std::cerr << "problem loading radial texture in resources/img/radialTex.png" << std::endl;
	}

	m_radialSprite.setTexture(m_radialTex);
	m_radialSprite.setTextureRect(m_radialMid);

	m_radialSprite.setPosition(t_pos);
}

void Radial::processInput(Xbox360Controller t_controller)
{
	if (m_radialCurrent != RadialState::NEUTRAL)
	{
		m_radialSprite.setTextureRect(m_radialMid);
		m_radialCurrent = RadialState::NEUTRAL;
	}

	if (t_controller.m_currentState.LeftThumbStick.x > 20.0f
		&& m_radialCurrent != RadialState::RIGHT)
	{
		m_radialSprite.setTextureRect(m_radialRight);
		m_radialCurrent = RadialState::RIGHT;
	}
	else if (t_controller.m_currentState.LeftThumbStick.x < -20.0f
		&& m_radialCurrent != RadialState::LEFT)
	{
		m_radialSprite.setTextureRect(m_radialLeft);
		m_radialCurrent = RadialState::LEFT;
	}
	else if (t_controller.m_currentState.LeftThumbStick.y > 20.0f
		&& m_radialCurrent != RadialState::DOWN)
	{
		m_radialSprite.setTextureRect(m_radialDown);
		m_radialCurrent = RadialState::DOWN;
	}
	else if (t_controller.m_currentState.LeftThumbStick.y < -20.0f
		&& m_radialCurrent != RadialState::UP)
	{
		m_radialSprite.setTextureRect(m_radialUp);
		m_radialCurrent = RadialState::UP;
	}
}

void Radial::drawRadial(sf::RenderWindow& t_window)
{
	t_window.draw(m_radialSprite);
}
