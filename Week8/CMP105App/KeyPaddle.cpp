#include "KeyPaddle.h"

KeyPaddle::KeyPaddle()
{
	velocity = sf::Vector2f(0, 200);
}

KeyPaddle::~KeyPaddle()
{
}

void KeyPaddle::update(float dt)
{
	if (getPosition().y > window->getSize().y - getSize().y)
	{
		setPosition(getPosition().x, window->getSize().y - getSize().y);
	}

	if (getPosition().y < 0)
	{
		setPosition(getPosition().x, 0);
	}
}

void KeyPaddle::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		move(-velocity * dt);
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		move(velocity * dt);
	}
}
