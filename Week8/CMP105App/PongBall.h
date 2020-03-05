#pragma once
#include "Framework/GameObject.h"
class PongBall :
	public GameObject
{
public:

	PongBall();
	~PongBall();
	void update(float dt) override;
	void handleInput(float dt) override;
	void setWindow(sf::RenderWindow* hwnd) { window = hwnd; };
	sf::String getScore();

protected:
	sf::RenderWindow* window;

	int leftScore;
	int rightScore;

};

