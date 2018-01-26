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

struct EnemyType { float enemySpeed; float laserShootDelay; float laserSpeed; Vector2f laserSize; };

class Enemy
{
public:
	Enemy(float x, float y, EnemyType& enemyType, Texture& enemyTexture, Player& player);
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
	int dirX;
	float enemySpeed;
	float shootDelay;
	Clock laserTime;
	Vector2f laserSize;
	float laserSpeed;
};
