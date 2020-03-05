#pragma once
#include "Framework/GameObject.h"

class MousePaddle :
	public GameObject
{
public:

	MousePaddle();
	~MousePaddle();
	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:
	sf::RenderWindow* window;

};

