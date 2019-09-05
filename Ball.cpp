#include "Ball.h"
#include <random>


sf::Vector2f getRandom(float size);
float getLength(sf::Vector2f& vec);
void normalize(sf::Vector2f& vec);

Ball::Ball(float x, float y, sf::Color color)
{
	shape = new sf::CircleShape(SIZE);
	shape->setOrigin(SIZE, SIZE);
	shape->setPosition(x, y);
	shape->setFillColor(color);

	srand(std::time(0));
}

Ball::~Ball()
{
	delete shape;
}

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*shape, states);
}

void Ball::setPosition(float x, float y)
{
	shape->setPosition(x, y);
}

void Ball::move(float deltaT)
{
	shape->move(direction * deltaT);
}

float Ball::getSpeed()
{
	return speed;
}

void Ball::setSpeed(float speed)
{
	this->speed = speed;
}

void Ball::randomDirection()
{
	direction = getRandom(speed);
}

const sf::Vector2f & Ball::getPosition()
{
	return shape->getPosition();
}

void Ball::setDirection(float x, float y)
{
	direction.x = x;
	direction.y = y;
}

const sf::Vector2f & Ball::getDirection()
{
	return direction;
}

void Ball::setColor(sf::Color color)
{
	shape->setFillColor(color);
}

const sf::Color & Ball::getColor()
{
	return shape->getFillColor();
}

//Vector2f helper functions
sf::Vector2f getRandom(float size)
{
	//X should always be 2-3x larger than Y
	float y = (float)rand() / (float)RAND_MAX * 1.25f - 0.75f;
	float x = (float)rand() / (float)RAND_MAX * 4.0f - 2.0f;
	x = (x < 0.5 && x > -0.5) ? 1 / x : x;

	//Vector is scaled
	sf::Vector2f result(x, y);
	normalize(result);
	result *= size;

	return result;
}

float getLength(sf::Vector2f& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

void normalize(sf::Vector2f& vec)
{
	const float length = getLength(vec);
	vec /= length;
}
