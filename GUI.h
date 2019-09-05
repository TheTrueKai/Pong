#pragma once
#include <SFML\Graphics.hpp>

class GUI : public sf::Drawable
{
public:
	GUI();
	~GUI();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void initialize(int width, int height, int amountOfLines);
	void update(int width, int height, int scoreA, int scoreB);

private:
	sf::VertexArray lines;
	sf::Text score;
	sf::Font font;
	int lineWidth;
};

