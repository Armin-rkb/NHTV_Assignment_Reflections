#pragma once
#include "SFML\Graphics.hpp"

using namespace sf;
enum BallState {
	DANGEROUS,
	SAFE
};
class Ball
{
public:
	Ball(float x, float y);
	~Ball();

public:
	void Draw(RenderWindow& window);
	void Update();
	void Move();
	void BallHit(float newDirX, float newDirY);

public:
	FloatRect getBounds();
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
	float ballSpeed;
	int cdTime = 0;
};
