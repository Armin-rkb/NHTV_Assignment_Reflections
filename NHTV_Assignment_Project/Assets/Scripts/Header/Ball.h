#pragma once
#include "SFML\Graphics.hpp"
#include "../Header/Player.h"
#include "../Header/Score.h"

using namespace sf;

enum BallState {
	DANGEROUS,
	SAFE
};

class Ball
{
public:
	Ball();
	~Ball();

public:
	void Draw(RenderWindow& window);
	void Update();
	void CheckCollision(Player& player);
	void Move();
	void BallHit(float newDirX, float newDirY);
	void Reset();

public:
	FloatRect getBallBounds();
	BallState ballState;
	Sprite ballSprite;

private:
	void ChangeDirX(float newDirX = 0);
	void ChangeDirY(float newDirY = 0);
	void IncreaseBallSpeed();

private:
	Texture ballTextureDanger;
	Texture ballTextureSafe;
	Vector2f dir;
	float ballSpeed ;
	int cdTime = 0;
};
