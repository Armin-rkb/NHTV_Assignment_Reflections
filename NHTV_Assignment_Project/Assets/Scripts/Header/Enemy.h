#pragma once
#include "SFML\Graphics.hpp"
#include "../Header/Laser.h"
#include "../Header/Player.h"
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
	Sprite enemySprite;
	EnemyState enemyState;

private:
	void Move();
	void ShootLaser();

private:
	vector <Laser> laserVec;
	Texture enemyTexture;
	float dirX;
	float enemySpeed;
	Clock clock;
};
