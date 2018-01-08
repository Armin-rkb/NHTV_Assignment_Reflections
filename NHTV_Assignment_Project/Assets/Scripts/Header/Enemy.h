#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;
class Enemy
{
public:
	Enemy(float x, float y);
	~Enemy();

public:
	void Draw(RenderWindow& window);
	void Update();

public:
	FloatRect getBounds();

public:
	Sprite enemySprite;
};

