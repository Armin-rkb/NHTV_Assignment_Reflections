#pragma once
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Player
{
public:
	Player(float x, float y);
	~Player();

public:
	void Draw(RenderWindow& window);
	void Update();
	void PlayerHit();

public:
	FloatRect getBounds();
	FloatRect getReflectorBounds();
	Sprite playerSprite;
	RectangleShape reflector;
	bool isReflecting;

private:
	void Reflect();

private:
	bool canJump;
	bool isJumping;
	bool canReflect;
	bool reflectCooling;
	int jumpTime = 0;
	Clock reflectTime;
};

