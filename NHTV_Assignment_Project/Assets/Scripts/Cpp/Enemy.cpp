#include "../Header/Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(float x, float y)
{
	// Load the textures.
	lazerTextureSafe.loadFromFile("Assets/Sprites/blue_lazer.png");
	lazerTextureDanger.loadFromFile("Assets/Sprites/red_lazer.png");
	enemySprite.setTexture(lazerTextureDanger);

	enemySprite.setPosition(x, y);
	enemySprite.setScale(2, 2);
	enemySprite.setOrigin((float)enemySprite.getTextureRect().width / 2, (float)enemySprite.getTextureRect().height / 2);

	ballSpeed = 5;
	dir.x = 1;
	dir.y = 1;
	
	canHit = true;
}

// Update gets called every frame.
void Enemy::Update()
{
	Move();
}

void Enemy::Move()
{
	// Constantly move our ball.
	enemySprite.move(Vector2f(dir.x * ballSpeed, dir.y * ballSpeed));

	// Bounce the ball inside game bounds.
	if (enemySprite.getPosition().x < 0) {
		ChangeDirX();
	}
	if (enemySprite.getPosition().x > 1280) {
		ChangeDirX();
	} 
	if (enemySprite.getPosition().y < 0) {
		ChangeDirY();
	}
	if (enemySprite.getPosition().y > 600) {
		ChangeDirY();
	}
}

void Enemy::ChangeDirX(float newDirX)
{
	if (newDirX != 0) {
		dir.x *= newDirX;
	}
	else {
		dir.x *= -1;
	}
}

void Enemy::ChangeDirY(float newDirY)
{
	if (newDirY != 0) {
		dir.y *= newDirY;
	}
	else {
		dir.y *= -1;
	}
}

void Enemy::IncreaseBallSpeed()
{
	ballSpeed++; 
	enemySprite.setTexture(lazerTextureSafe);

	cout << dir.x << endl;
}

// Rendering our Ball.
void Enemy::Draw(RenderWindow& window) 
{
	window.draw(enemySprite);
}

FloatRect Enemy::getBounds() {
	Sprite* ptrSprite = &enemySprite;
	return ptrSprite->getGlobalBounds();
}

Enemy::~Enemy()
{
}
