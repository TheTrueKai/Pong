#pragma once
#include <SFML\Graphics.hpp>

class Bat : public sf::Drawable
{
public:

	Bat(float x = 0.0f, float y = 0.0f, float speed = 500.0f);
	~Bat();

	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();

	void move(float x, float y);

	void setSpeed(float speed);
	float getSpeed();

	float getHeight();
	float getWidth();

	void setHeight(float height);
	void setWidth(float width);

	void setColor(sf::Color color);
	float getVelocity();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape* shape;
	sf::Vector2f position;
	float speed;
	float velocity;
};

