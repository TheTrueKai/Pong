#pragma once
#include <SFML\Graphics.hpp>
#include "Scene.h"
#include "MenuButton.h"
#include <vector>

class MenuScene : public Scene
{
public:
	MenuScene();
	~MenuScene();

	void handleEvents();
	void update(float deltaT);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool isClosed();
	void close();
	void open();
	void addButton(MenuButton button);
	void setMousePos(const sf::Vector2i &mousePos);

private:
	bool closed;
	std::vector<MenuButton> buttons;
	sf::Vector2i mousePos;
	sf::Text infoText;
	sf::Font font;
};

