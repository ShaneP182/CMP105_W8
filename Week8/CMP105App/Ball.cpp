#include "Ball.h"

Ball::Ball()
{
	velocity = sf::Vector2f(100, 0);
}

Ball::~Ball()
{

}

void Ball::update(float dt)
{
	move(velocity*dt);

	/*
	if (getPosition().y > window->getSize().y - 50)
	{
		setPosition(getPosition().x, window->getSize().y - 50);
		velocity = sf::Vector2f(velocity.x, -velocity.y) * 0.8f;
	}
	*/

	if (getPosition().x > window->getSize().x - getSize().x)
	{
		setPosition(window->getSize().x - getSize().x, getPosition().y);
		velocity = sf::Vector2f(-velocity.x, velocity.y);
	}

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity = sf::Vector2f(-velocity.x, velocity.y);
	}

	/*
	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity = sf::Vector2f(velocity.x, -velocity.y);
	}
	*/

}

void Ball::handleInput(float dt)
{

}
