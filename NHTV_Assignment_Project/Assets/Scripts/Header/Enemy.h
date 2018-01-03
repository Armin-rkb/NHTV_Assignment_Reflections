#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;
class Enemy
{
public:
	Enemy(float x, float y);
	~Enemy();
	void Draw(RenderWindow& window);
	void Update();
};

