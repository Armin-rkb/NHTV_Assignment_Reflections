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
	void Move();
	void ChangeDirX(float newDirX = 0);
	void ChangeDirY(float newDirX = 0);
	void IncreaseBallSpeed();

public:
	FloatRect getBounds();
	Sprite enemySprite;
	bool canHit;

private:
	Texture lazerTextureDanger;
	Texture lazerTextureSafe;
	Vector2f dir;
	float ballSpeed;
};
