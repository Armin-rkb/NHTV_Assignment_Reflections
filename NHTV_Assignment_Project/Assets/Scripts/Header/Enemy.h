#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;
class Enemy
{
public:
	Enemy();
	~Enemy();

public:
	void Draw(RenderWindow& window);
	void Update(); 
	void EnemyHit();

public:
	FloatRect getBounds();
	Sprite enemySprite;

private:
	Texture enemyTexture;
};
