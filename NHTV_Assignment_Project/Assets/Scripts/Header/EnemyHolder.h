#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"
#include "player.h"
#include "ball.h"
#include "Score.h"

using namespace std;
using namespace sf;
class EnemyHolder
{
public:
	EnemyHolder(Texture& enemyTexture, Player& player, Ball& ball, Score& score);
	~EnemyHolder();

public:
	void Update();
	void Draw(RenderWindow& window);

private:
	void SpawnEnemy();

private:
	vector<Enemy> enemies;
	Texture* enemyTexturePtr;
	Player* playerPtr;
	Ball* ballPtr;
	Score* scorePtr;

private:
	// EnemyType holds: float enemySpeed, float laserShootDelay, float laserSpeed, Vector2f laserSize;.
	EnemyType slowEnemy = { 3, 3, 3.5, Vector2f(20, 40) };
	EnemyType normalEnemy = { 5, 2.5, 6, Vector2f(15, 50) };
	EnemyType fastEnemy = { 10, 1.5, 10, Vector2f(10, 35) };
};
