#include "Bat.h"
#include <random>
#include <ctime>


Bat::Bat(float x, float y, float speed) : speed(speed)
{
	position.x = x;
	position.y = y;
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f(32.0f, 200.0f));
	shape->setPosition(x, y);
	shape->setFillColor(sf::Color::White);
}

Bat::~Bat()
{
	delete shape;
}


void Bat::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	shape->setPosition(position);
}

const sf::Vector2f & Bat::getPosition()
{
	return shape->getPosition();
}

void Bat::move(float x, float y)
{
	shape->move(x * speed, y * speed);
	velocity = shape->getPosition().y - position.y;
	position = shape->getPosition();
}

void Bat::setSpeed(float speed)
{
	this->speed = speed;
}

float Bat::getSpeed()
{
	return speed;
}

float Bat::getHeight()
{
	return shape->getSize().y;
}

float Bat::getWidth()
{
	return shape->getSize().x;
}

void Bat::setHeight(float height)
{
	shape->setSize(sf::Vector2f(shape->getSize().x, height));
}

void Bat::setWidth(float width)
{
	shape->setSize(sf::Vector2f(width, shape->getSize().y));
}

void Bat::setColor(sf::Color color)
{
	shape->setFillColor(color);
}

float Bat::getVelocity()
{
	return velocity;
}

void Bat::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*shape, states);
}
