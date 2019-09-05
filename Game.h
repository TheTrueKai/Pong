#pragma once
#include <SFML\Graphics.hpp>
#include "GameScene.h"
#include "Menu.h"

namespace Pong
{
	class Game
	{
	public:
		Game(int width, int height, const char* title);
		~Game();
		void run();

	private:
		sf::RenderWindow* pWindow;
		GameScene* pScene;
		MenuScene* pMenu;
		void handleEvents(sf::Event& event);
		void update(float delta);
		void render();

		bool isMenuActive;
	};
}