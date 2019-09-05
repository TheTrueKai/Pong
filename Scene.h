#pragma once
#include <SFML\Graphics.hpp>

class Scene : public sf::Drawable
{
public:	
	explicit Scene();
	~Scene();
	virtual void setSize(int width, int height);
	virtual void update(float deltaT) = 0; //pure virtual
	virtual void handleEvents() = 0;

public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

protected:
	static sf::Color getRandomColor();

protected:
	int width, height;
};

