#include "Game.h"

Game::Game() : m_window(sf::VideoMode(800, 600), "Radial Test"), m_dial(sf::Vector2f{400.0f,300.0f})
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);

	while (m_window.isOpen())
	{
		processKeys();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}
		render();
	}
}

void Game::processKeys()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update(sf::Time dt)
{
	m_controller.update();
	m_dial.processInput(m_controller);
}

void Game::render()
{
	m_window.clear();
	m_dial.drawRadial(m_window);
	m_window.display();
}
