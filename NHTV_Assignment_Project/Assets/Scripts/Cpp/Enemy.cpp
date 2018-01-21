#include "../Header/Enemy.h"

Enemy::Enemy()
{
	// Load the textures.
	enemyTexture.loadFromFile("Assets/Sprites/enemy_invader.png");
	enemySprite.setTexture(enemyTexture);

	enemySprite.setPosition(500, 35);
	enemySprite.setScale(1.25, 1.25);
	enemySprite.setOrigin((float)enemySprite.getTextureRect().width / 2, (float)enemySprite.getTextureRect().height / 2);
}

void Enemy::Update() 
{

}

void Enemy::EnemyHit()
{
	cout << "Enemy Hit!" << endl;
}

// Rendering our Enemy.
void Enemy::Draw(RenderWindow& window) 
{
	window.draw(enemySprite);
}

// Returns the bounds of our player.
FloatRect Enemy::getBounds() {
	Sprite* ptrSprite = &enemySprite;
	return ptrSprite->getGlobalBounds();
}

Enemy::~Enemy()
{
}
