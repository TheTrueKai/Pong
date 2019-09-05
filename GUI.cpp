#include "GUI.h"



GUI::GUI() 
{
	lineWidth = 10;
	if (!font.loadFromFile("fonts/SFPixelate.ttf"))
	{
		//Cry a lot
	}

	score.setFont(font); // font is a sf::Font
	score.setString("0 : 0");
	score.setCharacterSize(200);
	score.setFillColor(sf::Color::White);
	
}


GUI::~GUI()
{
}

void GUI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(lines, states);
	target.draw(score);
}

void GUI::initialize(int width, int height, int amountOfLines)
{
	//clear VertexArray
	lines = sf::VertexArray(sf::Lines, amountOfLines * 2);

	//Create dashed lines
	const float spacingRatio = 1.5;
	const int lineHeight = height / amountOfLines;
	for (int i = 0; i < amountOfLines; i++)
	{
		lines[i * 2].position = sf::Vector2f(width / 2.0, i * lineHeight);
		lines[i * 2 + 1].position = sf::Vector2f(width / 2.0, i * lineHeight + lineHeight / spacingRatio);
	}

	update(width, height, 0, 0);
}

void GUI::update(int width, int height, int scoreA, int scoreB)
{
	score.setString(std::to_string(scoreA) + " : " + std::to_string(scoreB));
	score.setPosition(width / 2.0 - score.getLocalBounds().width / 2.0f - 20, 30);
}
