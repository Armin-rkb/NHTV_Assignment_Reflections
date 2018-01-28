#pragma once
#include <SFML\Graphics.hpp>
#include "../Header/States.h"

using namespace sf;

class Player
{
public:
	Player();
	~Player();

public:
	void Draw(RenderWindow& window);
	void Update();
	void PlayerHit();
	void Reset();

public:
	FloatRect getBounds();
	FloatRect getReflectorBounds();
	Sprite playerSprite;
	RectangleShape reflector;
	bool isReflecting;

private:
	void PlayerMovement();
	void CheckReflector();
	void ApplyGravity();
	void Reflect();

private:
	Texture playerTexture;
	Texture playerDeadTexture;
	bool canJump;
	bool isJumping;
	bool canReflect;
	bool reflectCooling;
	int jumpTime = 0;
	Clock reflectTime;

private:
	const float groundHeight = 586;
	const float movementSpeed = 12;
	const float gravitySpeed = 16;
	const float reflectorSize = 25;
};

