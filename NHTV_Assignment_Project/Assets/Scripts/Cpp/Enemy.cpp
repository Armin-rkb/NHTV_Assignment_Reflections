#include "../Header/Enemy.h"

Enemy::Enemy(float x, float y, Texture& enemyTexture, Player& player)
{
	// Load the textures.
	enemySprite.setTexture(enemyTexture);

	// Set enemy transform.
	enemySprite.setPosition(x, y);
	enemySprite.setScale(1.25, 1.25);
	enemySprite.setOrigin((float)enemySprite.getTextureRect().width / 2, (float)enemySprite.getTextureRect().height / 2);
	
	enemyState = ALIVE;
	dirX = 1;
	enemySpeed = 3;

	playerPtr = &player;
}

void Enemy::Update() 
{
	if (enemyState == ALIVE) {
		Move();
		ShootLaser();
	}

	// Update all our lasers.
	for (int i = 0; i < (int)laserVec.size(); i++) {
		laserVec[i].Update(playerPtr);
		
		// Removing lasers that our outside of the gamefield.
		if (laserVec[i].WithinBounds() == false) {
			laserVec.erase(laserVec.begin() + i);
		}
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

// Spawning a laser.
void Enemy::ShootLaser()
{
	if (laserTime.getElapsedTime() > seconds(1)) {
		// Create a new Laser and add it to the list.
		Laser newLaser;
		newLaser.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
		laserVec.push_back(newLaser);
		
		// Restart the clock to count for the next laser.
		laserTime.restart();
	}
}

void Enemy::EnemyHit()
{
	cout << "Enemy Hit!" << endl;
	enemyState = DEAD; 
}

// Rendering our Enemy and shot lasers.
void Enemy::Draw(RenderWindow& window) 
{
	window.draw(enemySprite);
	for (int i = 0; i < (int)laserVec.size(); i++) {
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
