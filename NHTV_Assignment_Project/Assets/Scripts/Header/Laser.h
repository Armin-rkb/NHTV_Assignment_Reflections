#pragma once
#include "SFML\Graphics.hpp"
#include "../Header/Player.h"

using namespace std;
using namespace sf;
class Laser
{
public:
	Laser();
	~Laser();

public:
	void Draw(RenderWindow& window);
	void Update(Player* player);
	void setPosition(float x, float y);

public:
	FloatRect getLaserBounds();

private:
	void MoveLaser();
	void CheckCollision(Player* player);

private:
	RectangleShape laser;
	float laserSpeed;
};

