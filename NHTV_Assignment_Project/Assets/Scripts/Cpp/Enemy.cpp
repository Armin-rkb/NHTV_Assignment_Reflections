#include "../Header/Enemy.h"

Sprite lazer;
Texture lazerTexture;
Enemy::Enemy(float x, float y)
{
	lazerTexture.loadFromFile("Assets/Sprites/metal_ground.png");
	lazer.setTexture(lazerTexture);
	lazer.setPosition(x, y);
	lazer.setScale(0.5f, 0.1f);
}

void Enemy::Update() 
{
	
}

void Enemy::Draw(RenderWindow& window) 
{
	window.draw(lazer);
}

Enemy::~Enemy()
{
}
