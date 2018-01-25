#pragma once
#include "SFML\Graphics.hpp"
#include "../Header/Laser.h"
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
	Enemy(float x, float y, Texture& enemyTexture, Player& player);
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
	Player* playerPtr;
	vector<Laser> laserVec;
	float dirX;
	float enemySpeed;
	Clock laserTime;
};
