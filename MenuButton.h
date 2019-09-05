#pragma once
#include <SFML\Graphics.hpp>

class MenuButton : public sf::Drawable
{
public:
	MenuButton(sf::String caption, int x, int y, int width, int height);
	~MenuButton();

	bool contains(int x, int y);
	bool Clicked();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void highlight();
	void unhighlight();
	void update(int mouseX, int mouseY);
	void handleEvents();

	bool isMouseOver();
	void setFont(const sf::Font& font);

private:
	bool mouseOver;
	sf::RectangleShape shape;
	sf::Text caption;
	sf::Font font;
};

