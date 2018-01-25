#include "../Header/EnemyHolder.h"

EnemyHolder::EnemyHolder(Player& player, Ball& ball, Score& score)
{
	Texture enemyTexture;
	enemyTexture.loadFromFile("Assets/Sprites/enemy_invader.png");

	for (int i = 0; i < 3; i++) {
		Enemy enemy = Enemy(150 * (float)i, 30, enemyTexture, player);
		enemies.push_back(enemy);
	}

	ballPtr = &ball;
	scorePtr = &score;
}

// Call the update of all our enemies.
void EnemyHolder::Update() 
{
	for (int i = 0; i < (int)enemies.size(); i++) {
		enemies[i].Update();
	}

	// Ball collision with enemy.
	for (int i = 0; i < (int)enemies.size(); i++)
	{
		if (ballPtr->ballState == SAFE && enemies[i].enemyState == ALIVE)
		{
			if (ballPtr->getBallBounds().intersects(enemies[i].getEnemyBounds()))
			{
				enemies[i].EnemyHit();
				scorePtr->AddScore(1);

				// Remove the enemy.
				enemies.erase(enemies.begin() + i);
			}
		}
	}
}

// Draw our list of enemies.
void EnemyHolder::Draw(RenderWindow& window) 
{
	for (int i = 0; i < (int)enemies.size(); i++) {
		enemies[i].Draw(window);
	}
}

EnemyHolder::~EnemyHolder()
{
}
