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
	EnemyHolder(Player& player, Ball& ball, Score& score);
	~EnemyHolder();

public:
	void Update();
	void Draw(RenderWindow& window);

private:
	vector<Enemy> enemies;
	Ball* ballPtr;
	Score* scorePtr;
};
