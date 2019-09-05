#pragma once
#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{

public:
	static const int SIZE = 120;

	Ball(float x = 0.0f, float y = 0.0f, sf::Color color = sf::Color::White);
	~Ball();
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();

	void setDirection(float x, float y);
	const sf::Vector2f& getDirection();

	void setColor(sf::Color color);
	const sf::Color& getColor();

	void move(float deltaT);
	void randomDirection();

	float getSpeed();
	void setSpeed(float speed);

private:
	sf::CircleShape* shape;
	sf::Vector2f direction;
	float speed;
};

