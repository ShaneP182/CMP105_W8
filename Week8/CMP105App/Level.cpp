#include "Level.h"
#include "Framework/Collision.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	notBallTexture.loadFromFile("gfx/Goomba.png");
	font.loadFromFile("font/arial.ttf");

	ball1.setSize(sf::Vector2f(100, 100));
	ball1.setPosition(0, window->getSize().y/2);
	ball1.setTexture(&ballTexture);
	ball1.setWindow(window);

	ball2.setSize(sf::Vector2f(100, 100));
	ball2.setPosition(window->getSize().x, window->getSize().y / 2);
	ball2.setTexture(&ballTexture);
	ball2.setWindow(window);

	notBall1.setSize(sf::Vector2f(100, 100));
	notBall1.setPosition(0, window->getSize().y / 3);
	notBall1.setTexture(&notBallTexture);
	notBall1.setWindow(window);
	notBall1.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	notBall1.setVelocity(sf::Vector2f(200, 0));

	notBall2.setSize(sf::Vector2f(100, 100));
	notBall2.setPosition(window->getSize().x, window->getSize().y / 3);
	notBall2.setTexture(&notBallTexture);
	notBall2.setWindow(window);
	notBall2.setCollisionBox(sf::FloatRect(0, 0, 100, 100));
	notBall2.setVelocity(sf::Vector2f(200, 0));

	mousePaddle.setSize(sf::Vector2f(20,100));
	mousePaddle.setPosition(window->getSize().x - mousePaddle.getSize().x, window->getSize().y / 2);
	mousePaddle.setCollisionBox(sf::FloatRect(0, 0, 20, 100));
	mousePaddle.setInput(input);
	mousePaddle.setWindow(window);

	keyPaddle.setSize(sf::Vector2f(20, 100));
	keyPaddle.setPosition(0, window->getSize().y/2);
	keyPaddle.setCollisionBox(sf::FloatRect(0, 0, 20, 100));
	keyPaddle.setInput(input);
	keyPaddle.setWindow(window);

	pongBall.setSize(sf::Vector2f(20, 20));
	pongBall.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	pongBall.setCollisionBox(sf::FloatRect(0, 0, 20, 20));
	pongBall.setWindow(window);

	score.setFont(font);
	score.setCharacterSize(20);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	mousePaddle.handleInput(dt);
	keyPaddle.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	mousePaddle.update(dt);
	keyPaddle.update(dt);
	pongBall.update(dt);

	score.setPosition(window->getSize().x / 2, 10);
	score.setString(pongBall.getScore());
	

	if (Collision::checkBoundingBox(&keyPaddle, &pongBall))
	{
		pongBall.setPosition(pongBall.getPosition().x + 1, pongBall.getPosition().y);
		pongBall.setVelocity(sf::Vector2f(-pongBall.getVelocity().x, pongBall.getVelocity().y));
	}

	if (Collision::checkBoundingBox(&mousePaddle, &pongBall))
	{
		pongBall.setPosition(pongBall.getPosition().x - 1, pongBall.getPosition().y);
		pongBall.setVelocity(sf::Vector2f(-pongBall.getVelocity().x, pongBall.getVelocity().y));
	}

	/*
	ball1.update(dt);
	ball2.update(dt);
	notBall1.update(dt);
	notBall2.update(dt);


	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.setVelocity(sf::Vector2f(-ball1.getVelocity().x, ball1.getVelocity().y));
		ball2.setVelocity(sf::Vector2f(-ball2.getVelocity().x, ball2.getVelocity().y));
	}

	if (Collision::checkBoundingBox(&notBall1, &notBall2))
	{
		notBall1.setVelocity(sf::Vector2f(-notBall1.getVelocity().x, notBall1.getVelocity().y));
		notBall2.setVelocity(sf::Vector2f(-notBall2.getVelocity().x, notBall2.getVelocity().y));
	}
	*/
}

// Render level
void Level::render()
{
	beginDraw();

	/*
	window->draw(ball1);
	window->draw(ball2);

	window->draw(notBall1);
	window->draw(notBall2);
	*/

	window->draw(keyPaddle);
	window->draw(mousePaddle);
	window->draw(pongBall);
	window->draw(score);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}