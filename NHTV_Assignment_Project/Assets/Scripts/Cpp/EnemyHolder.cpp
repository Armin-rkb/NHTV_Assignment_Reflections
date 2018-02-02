#include "../Header/EnemyHolder.h"

EnemyHolder::EnemyHolder(Texture& enemyTexture, Player& player, Ball& ball, Score& score)
{
	enemyTexturePtr = &enemyTexture;
	playerPtr = &player;
	ballPtr = &ball;
	scorePtr = &score;
}

void EnemyHolder::Update() 
{
	// Call the update of all our enemies.
	for (int i = 0; i < (int)enemies.size(); i++) {
		enemies[i].Update();
	}

	EnemyCollision();
	SpawnCheck();
}

// Draw our list of enemies.
void EnemyHolder::Draw(RenderWindow& window) 
{
	for (int i = 0; i < (int)enemies.size(); i++) {
		enemies[i].Draw(window);
	}
}

// Spawn enemies when under the max amount.
void EnemyHolder::SpawnCheck()
{
	if ((int)enemies.size() < maxEnemies)
	{
		if (!isSpawning) {
			isSpawning = true;
			spawnTime.restart();
		}
	}
	else {
		isSpawning = false;
	}

	if (isSpawning) {
		SpawnEnemy();
	}
}

// Makes a new enemy and adds it to the list.
void EnemyHolder::SpawnEnemy()
{
	if (spawnTime.getElapsedTime() > seconds(1)) {
		//Spawning a random enemy type.
		int rndType = rand() % 3;
		Enemy enemy = Enemy(650, 30, enemyTypeList[rndType], (*enemyTexturePtr), (*playerPtr));
		enemies.push_back(enemy);

		spawnTime.restart();
	}
}

// Ball collision with enemy.
void EnemyHolder::EnemyCollision()
{
	for (int i = 0; i < (int)enemies.size(); i++)
	{
		if (ballPtr->ballState == SAFE && enemies[i].enemyState == ALIVE)
		{
			if (ballPtr->getBallBounds().intersects(enemies[i].getEnemyBounds()))
			{
				enemies[i].EnemyHit();
				scorePtr->AddScore(1);

				// Increase the max amount of enemies.
				if (scorePtr->GetScore() % 3 == 0)
				{
					maxEnemies++;
				}

				// Remove the enemy.
				enemies.erase(enemies.begin() + i);
			}
		}
	}
}

// Clear all enemies in the list.
void EnemyHolder::ClearEnemies()
{
	maxEnemies = 3;
	enemies.clear();
}


EnemyHolder::~EnemyHolder()
{
}
