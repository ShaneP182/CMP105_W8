#include "MousePaddle.h"

MousePaddle::MousePaddle()
{
}

MousePaddle::~MousePaddle()
{
}

void MousePaddle::update(float dt)
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

void MousePaddle::handleInput(float dt)
{
	setPosition(window->getSize().x - getSize().x, input->getMouseY());
}
