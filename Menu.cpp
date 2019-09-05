#include "Menu.h"
#include <iostream>


MenuScene::MenuScene()
{
	font.loadFromFile("fonts/SFPixelate.ttf");

	infoText.setFont(font);
	infoText.setString("Press Space To Start the Game...");
	infoText.setFillColor(sf::Color::White);
	infoText.setCharacterSize(100.0f);
	closed = true;
}


MenuScene::~MenuScene()
{
}

void MenuScene::handleEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !closed)
	{
		closed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && closed)
	{
		closed = false;
	}

	for (MenuButton& mb : buttons)
	{
		mb.handleEvents();
	}
}

void MenuScene::update(float deltaT)
{
	for (MenuButton& mb : buttons)
	{
		mb.update(mousePos.x, mousePos.y);
	}
	handleEvents();
}

bool MenuScene::isClosed()
{
	return closed;
}

void MenuScene::close()
{
	closed = true;
}

void MenuScene::open()
{
	closed = false;
}

void MenuScene::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (MenuButton mb : buttons) {
		target.draw(mb, states);
	}
	target.draw(infoText);
}

void MenuScene::addButton(MenuButton button)
{
	button.setFont(font);
	buttons.push_back(button);
}

void MenuScene::setMousePos(const sf::Vector2i & mousePos)
{
	this->mousePos = mousePos;
}
