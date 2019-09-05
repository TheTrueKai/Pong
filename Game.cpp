#include "Game.h"

namespace Pong
{

	Game::Game(int width, int height, const char* title)
	{
		pWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
		pWindow->setFramerateLimit(60.0f);
		pScene = new GameScene();
		pScene->setSize(width, height);

		pMenu = new MenuScene();
		pMenu->setSize(width, height);
		pMenu->open();
		pMenu->addButton(MenuButton("Hello", 100, 100, 300, 100));

	}


	Game::~Game()
	{
		delete pScene;
		pScene = nullptr;
		delete pWindow;
		pWindow = nullptr;
		delete pMenu;
		pMenu = nullptr;
	}

	void Game::run()
	{
		sf::Event event;
		sf::Clock clock;
		while (pWindow->isOpen())
		{
			while (pWindow->pollEvent(event))
			{
				handleEvents(event);
			}
			//Update the logic with delta time
			update(clock.restart().asSeconds());

			//clear the window
			pWindow->clear(sf::Color::Black);

			//render the scene / menu
			render();

			//display the window
			pWindow->display();
		}
	}

	void Game::handleEvents(sf::Event& event)
	{
		
		if (event.type == sf::Event::Closed)
			pWindow->close();

		pMenu->handleEvents();
	}

	void Game::update(float deltaT)
	{
		if (pMenu->isClosed())
			pScene->update(deltaT);
		else 
		{
			pMenu->setMousePos(sf::Mouse::getPosition(*pWindow));
			pMenu->update(deltaT);
		}
			
	}

	void Game::render()
	{
		if (pMenu->isClosed())
		{
			pWindow->draw(*pScene);
		}
		else
		{
			pWindow->draw(*pMenu);
		}		
	}
}