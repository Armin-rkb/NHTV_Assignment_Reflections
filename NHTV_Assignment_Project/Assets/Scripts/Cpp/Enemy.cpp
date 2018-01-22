#include "../Header/Enemy.h"

Enemy::Enemy()
{
	// Load the textures.
	enemyTexture.loadFromFile("Assets/Sprites/enemy_invader.png");
	enemySprite.setTexture(enemyTexture);

	// Set enemy transform.
	enemySprite.setPosition(500, 35);
	enemySprite.setScale(1.25, 1.25);
	enemySprite.setOrigin((float)enemySprite.getTextureRect().width / 2, (float)enemySprite.getTextureRect().height / 2);
	
	enemyState = ALIVE;
	dirX = 1;
	enemySpeed = 3;
}

void Enemy::Update() 
{
	if (enemyState == ALIVE) {
		Move();
		ShootLaser();
	}
	for (int i = 0; i < laserVec.size(); i++) {
		laserVec[i].Update();
	}
}

void Enemy::Move() 
{
	enemySprite.move(Vector2f(enemySpeed * dirX, 0));

	// Flip direction when reaching the game borders.
	if (enemySprite.getPosition().x > 1280) {
		dirX = -1;
	}
	else if (enemySprite.getPosition().x < 0) {
		dirX = 1;
	}
}

void Enemy::ShootLaser()
{
	if (clock.getElapsedTime() > seconds(3)) {
		cout << "Shoot Laser!" << endl;
		Laser newLaser;
		newLaser.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
		laserVec.push_back(newLaser);
		clock.restart();
	}
}

void Enemy::EnemyHit()
{
	cout << "Enemy Hit!" << endl;
	enemyState = DEAD; 
}

// Rendering our Enemy.
void Enemy::Draw(RenderWindow& window) 
{
	window.draw(enemySprite);
	for (int i = 0; i < laserVec.size(); i++) {
		laserVec[i].Draw(window);
	}
}

// Returns the bounds of our enemy.
FloatRect Enemy::getEnemyBounds() {
	Sprite* ptrEnemy = &enemySprite;
	return ptrEnemy->getGlobalBounds();
}

Enemy::~Enemy()
{
}
