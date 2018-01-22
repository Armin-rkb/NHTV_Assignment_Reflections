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
	
	// Set Laser transform.
	laser.setSize(Vector2f(20, 80));
	laser.setOrigin(Vector2f(10, 40));
	laser.setFillColor(Color(000, 000, 150));

	enemyState = ALIVE;
	dirX = 1;
	enemySpeed = 3;
}

void Enemy::Update() 
{
	if (enemyState == ALIVE) {
		enemySprite.move(Vector2f(enemySpeed * dirX, 0));
		
		// Flip direction when reaching the borders.
		if (enemySprite.getPosition().x > 1280) {
			dirX = -1;
		}
		else if (enemySprite.getPosition().x < 0) {
			dirX = 1;
		}
	}
}

void Enemy::EnemyHit()
{
	cout << "Enemy Hit!" << endl;
	enemyState = DEAD; 
}

void Enemy::ShootLaser()
{

}

// Rendering our Enemy.
void Enemy::Draw(RenderWindow& window) 
{
	window.draw(enemySprite);
}

// Returns the bounds of our enemy.
FloatRect Enemy::getEnemyBounds() {
	Sprite* ptrEnemy = &enemySprite;
	return ptrEnemy->getGlobalBounds();
}

// Returns the bounds of our enemy laser.
FloatRect Enemy::getLaserBounds() {
	RectangleShape* ptrLaser = &laser;
	return ptrLaser->getGlobalBounds();
}

Enemy::~Enemy()
{
}
