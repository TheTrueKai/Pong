#pragma once
#include "Scene.h"
#include "Ball.h"
#include "Bat.h"
#include "GUI.h"

class GameScene : public Scene
{

//public functions
public: 
	GameScene();
	~GameScene();
	void setSize(int width, int height);
	void update(float deltaT);
	void handleEvents();

//public variables
public: 
	//WIP

//private functions
private:
	void solveCollsion();
	void updateScore();
	void resetBall();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

//private variables
private: 
	GUI* pGUI;
	Ball* pBall;
	Bat* pPlayer1;
	Bat* pPlayer2;

	int score_player1;
	int score_player2;
};

