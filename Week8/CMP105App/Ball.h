#pragma once
#include "Framework/GameObject.h"

class Ball : 
	public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:
	sf::RenderWindow* window;

};

