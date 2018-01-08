#include "../Header/Enemy.h"

Texture lazerTexture;
Enemy::Enemy(float x, float y)
{
	lazerTexture.loadFromFile("Assets/Sprites/metal_ground.png");
	enemySprite.setTexture(lazerTexture);
	enemySprite.setPosition(x, y);
	enemySprite.setScale(0.5f, 0.1f);
}

void Enemy::Update() 
{
	
}

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
