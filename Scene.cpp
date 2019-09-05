#include "Scene.h"
#include <random>

Scene::Scene() {}


Scene::~Scene() {}

void Scene::setSize(int width, int height)
{
	//Update Dimensions
	this->width = width;
	this->height = height;
}


//Color helper functions
sf::Color Scene::getRandomColor()
{
	const int r = rand() % 255;
	const int g = rand() % 255;
	const int b = rand() % 255;

	return sf::Color(r, g, b);
}
