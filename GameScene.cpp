#include "GameScene.h"
#include <random>


GameScene::GameScene()
{
	//Initialize Ball
	pBall = new Ball();
	pBall->setSpeed(1100.0f);
	pBall->randomDirection();

	//Initialize Players
	pPlayer1 = new Bat();
	pPlayer2 = new Bat();
	pPlayer1->setSpeed(500.0f);
	pPlayer2->setSpeed(500.0f);
	score_player1 = 0;
	score_player2 = 0;


	//Initialize GUI
	pGUI = new GUI();
}


GameScene::~GameScene()
{
	delete pBall;
	delete pPlayer1;
	delete pPlayer2;
	delete pGUI;
}

void GameScene::setSize(int width, int height)
{
	//Update Dimensions
	this->width = width;
	this->height = height;

	//Update Ball-Starting-Position
	pBall->setPosition(width / 2.0, height / 2.0);

	//Update Player-Starting-Position
	pPlayer1->setPosition(pPlayer1->getWidth(), height / 2.0f - pPlayer1->getHeight() / 2.0f);
	pPlayer2->setPosition(width - pPlayer2->getWidth() * 2, height / 2.0f - pPlayer2->getHeight() / 2.0f);

	pGUI->initialize(width, height, 9);
}

void GameScene::update(float deltaT)
{
	pBall->move(deltaT);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		pPlayer1->move(0.0f, -deltaT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pPlayer1->move(0.0f, deltaT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pPlayer2->move(0.0f, -deltaT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		pPlayer2->move(0.0f, deltaT);
	}

	solveCollsion();
}

void GameScene::handleEvents()
{
}

void GameScene::updateScore()
{
}

void GameScene::resetBall()
{
	pBall->randomDirection();
	pBall->setPosition(width / 2.0f, height / 2.0f);
	pBall->setColor(getRandomColor());
}

void GameScene::solveCollsion()
{
	//Ball-Wall Collision

	const sf::Vector2f& pBallPos = pBall->getPosition();
	const sf::Vector2f& pBallDir = pBall->getDirection();

	if (pBallPos.x + Ball::SIZE > width) //Right Wall
	{
		score_player1++;
		pGUI->update(width, height, score_player1, score_player2);
		resetBall();
	}
	else if (pBallPos.x - Ball::SIZE < 0) //Left Wall
	{
		score_player2++;
		pGUI->update(width, height, score_player1, score_player2);
		resetBall();
	}

	if (pBallPos.y + Ball::SIZE > height) //Floor
	{
		pBall->setPosition(pBallPos.x, height - Ball::SIZE);
		pBall->setDirection(pBallDir.x, pBallDir.y * -1);
	}
	else if (pBallPos.y - Ball::SIZE < 0) //Ceiling
	{
		pBall->setPosition(pBallPos.x, Ball::SIZE);
		pBall->setDirection(pBallDir.x, pBallDir.y * -1);
	}

	//Paddel-Wall Collision
	const sf::Vector2f& p1Pos = pPlayer1->getPosition();
	const sf::Vector2f& p2Pos = pPlayer2->getPosition();

	if (p1Pos.y < 0)
	{
		pPlayer1->setPosition(p1Pos.x, 0);
	}
	else if (p1Pos.y + pPlayer1->getHeight() > height)
	{
		pPlayer1->setPosition(p1Pos.x, height - pPlayer1->getHeight());
	}

	if (p2Pos.y < 0)
	{
		pPlayer2->setPosition(p2Pos.x, 0);
	}
	else if (p2Pos.y + pPlayer2->getHeight() > height)
	{
		pPlayer2->setPosition(p2Pos.x, height - pPlayer2->getHeight());
	}

	//Paddel-Ball Collision

	if (pBallDir.x < 0.0f) //The pBall is flying towards pPlayer1
	{

		//Y-Axys alignment
		if (pBallPos.y + Ball::SIZE > p1Pos.y && pBallPos.y - Ball::SIZE < p1Pos.y + pPlayer1->getHeight())
		{
			//X-Axys alignment
			if (pBallPos.x - Ball::SIZE < p1Pos.x + pPlayer1->getWidth() && pBallPos.x + Ball::SIZE > p1Pos.x)
			{
				pBall->setPosition(p1Pos.x + pPlayer1->getWidth() + Ball::SIZE, pBallPos.y);
				pBall->setDirection(pBallDir.x *-1, pBallDir.y);
				pPlayer1->setColor(pBall->getColor());
			}
		}
	}
	else //The pBall is flying towards pPlayer2
	{
		//Y-Axys alignment
		if (pBallPos.y + Ball::SIZE > p2Pos.y && pBallPos.y - Ball::SIZE < p2Pos.y + pPlayer2->getHeight())
		{
			//X-Axys alignment
			if (pBallPos.x + Ball::SIZE > p2Pos.x && pBallPos.x - Ball::SIZE < p2Pos.x + pPlayer2->getWidth())
			{
				pBall->setPosition(p2Pos.x - Ball::SIZE, pBallPos.y);
				pBall->setDirection(pBallDir.x *-1, pBallDir.y);
				pPlayer2->setColor(pBall->getColor());
			}
		}
	}
}

void GameScene::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*pBall, states);
	target.draw(*pPlayer1, states);
	target.draw(*pPlayer2, states);
	target.draw(*pGUI, states);
}