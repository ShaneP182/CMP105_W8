#include "PongBall.h"

PongBall::PongBall()
{
	velocity = sf::Vector2f(200, 200);
	leftScore = 0;
	rightScore = 0;
}

PongBall::~PongBall()
{
}

void PongBall::update(float dt)
{
	move(velocity * dt);
	if (getPosition().y > window->getSize().y - getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().x);
		velocity = sf::Vector2f(velocity.x, -velocity.y);
	}

	if (getPosition().x > window->getSize().x - getSize().x)
	{
		setPosition(window->getSize().x / 2, window->getSize().y / 2);
		rightScore++;
		velocity = sf::Vector2f(-velocity.x, velocity.y);
	}

	if (getPosition().x < 0)
	{
		setPosition(window->getSize().x / 2, window->getSize().y / 2);
		leftScore++;
		velocity = sf::Vector2f(-velocity.x, velocity.y);
	}

	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
		velocity = sf::Vector2f(velocity.x, -velocity.y);
	}
}

void PongBall::handleInput(float dt)
{
}

sf::String PongBall::getScore()
{
	return sf::String(std::to_string(leftScore) + " - " + std::to_string(rightScore));
}
