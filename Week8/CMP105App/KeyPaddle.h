#pragma once
#include "Framework/GameObject.h"
class KeyPaddle :
	public GameObject
{
public:

	KeyPaddle();
	~KeyPaddle();
	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };

protected:
	sf::RenderWindow* window;

};

