#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

enum EnemyState {
	ALIVE,
	DEAD
};

class Enemy
{
public:
	Enemy();
	~Enemy();

public:
	void Draw(RenderWindow& window);
	void Update(); 
	void EnemyHit();

public:
	FloatRect getEnemyBounds();
	FloatRect getLaserBounds();
	Sprite enemySprite;
	EnemyState enemyState;
	RectangleShape laser;

private:
	void ShootLaser();

private:
	Texture enemyTexture;
	float dirX;
	float enemySpeed;
};
