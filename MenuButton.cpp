#include "MenuButton.h"
#include <iostream>

MenuButton::MenuButton(sf::String caption, int x, int y, int width, int height)
{
	this->caption.setString(caption);
	this->caption.setCharacterSize(width / caption.toWideString().length());
	this->caption.setFillColor(sf::Color::Black);
	this->caption.setPosition(x, y);

	shape.setSize(sf::Vector2f((float)width, (float)height));
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::White);
	mouseOver = false;
}


MenuButton::~MenuButton()
{
}

bool MenuButton::contains(int x, int y)
{
	return shape.getGlobalBounds().contains(x, y);
}

bool MenuButton::Clicked()
{
	return false;
}

void MenuButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape, states);
	target.draw(caption, states);
}

void MenuButton::highlight()
{
	shape.setFillColor(sf::Color::Transparent);
	caption.setFillColor(sf::Color::White);
}

void MenuButton::unhighlight()
{
	shape.setFillColor(sf::Color::White);
	caption.setFillColor(sf::Color::Black);
}

void MenuButton::update(int mouseX, int mouseY)
{
	if (contains(mouseX, mouseY))
	{
		mouseOver = true;
	}
	else if (mouseOver)
	{
		mouseOver = false;
	}
}

void MenuButton::handleEvents()
{
	if (isMouseOver())
		highlight();
	else
		unhighlight();

}

bool MenuButton::isMouseOver()
{
	return mouseOver;
}

void MenuButton::setFont(const sf::Font & font)
{
	this->font = font;
	caption.setFont(font);
}
