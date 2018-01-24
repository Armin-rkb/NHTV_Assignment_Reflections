#include "../Header/Player.h"
#include <iostream>

// Player Texture
Texture playerTexture;

// Gravity Variables.
const float groundHeight = 586;
const float movementSpeed = 12;
const float gravitySpeed = 16;
const float reflectorSize = 20;

Player::Player(float x, float y)
{
	playerTexture.loadFromFile("Assets/Sprites/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(x, y);

	Vector2f playerSize = Vector2f((float)playerSprite.getTextureRect().width, (float)playerSprite.getTextureRect().height);
	playerSprite.setOrigin(playerSize.x / 2, playerSize.y / 2);

	reflector.setOrigin((playerSize.x / 2) + (reflectorSize / 2), (playerSize.y / 2) + (reflectorSize / 2));
	reflector.setSize(Vector2f(playerSize.x + reflectorSize, playerSize.y + reflectorSize));
	reflector.setFillColor(Color(000, 000, 150, 190));

	canJump = true;
	canReflect = true;
	reflectCooling = false;
	isReflecting = false;
}

// Update gets called every frame.
void Player::Update() {
	// Player Input.

	// Movement.
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		playerSprite.move(-movementSpeed, 0.0);
		// Flip the sprite to face the walking direction.
		if (playerSprite.getScale().x == 1)
			playerSprite.setScale(-1, 1);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		playerSprite.move(movementSpeed, 0.0);
		// Flip the sprite to face the walking direction.
		if (playerSprite.getScale().x == -1)
			playerSprite.setScale(1, 1);
	}

	// Jumping
	if (Keyboard::isKeyPressed(Keyboard::Key::W) && canJump) {
		playerSprite.move(0.0, -movementSpeed * 2);
		isJumping = true;
	}
	if (isJumping) {
		jumpTime++;
		if (jumpTime > 12) {
			isJumping = false;
			canJump = false;
			jumpTime = 0;
		}
	}

	// Reflector
	// Start reflecting when we aren't on cooldown.
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		if (canReflect == true && reflectCooling == false) {
			canReflect = false;
			isReflecting = true;
			reflectTime.restart();
		}
	}
	else {
		// Ensuring we can't hold the spacebar to keep reflecting. 
		canReflect = true;
	}

	// Activate the reflector for an amount of time.
	if (isReflecting == true) {
		if (reflectTime.getElapsedTime() < milliseconds(100)) {
			Reflect();
		}
		else {
			// Go on cooldown.
			isReflecting = false;
			reflectCooling = true;
			reflectTime.restart();
		}
	}

	// Cooldown for a set amount of time.
	if (isReflecting == false && reflectCooling == true) {
		if (reflectTime.getElapsedTime() > milliseconds(500)) {
			reflectCooling = false;
		}
	}

	// Gravity
	if (playerSprite.getPosition().y < groundHeight && !isJumping ||
		playerSprite.getPosition().y < groundHeight && !Keyboard::isKeyPressed(Keyboard::Key::W)) 
	{
		playerSprite.move(0, gravitySpeed);
	} else if (playerSprite.getPosition().y >= groundHeight) {
		canJump = true;
		playerSprite.setPosition(playerSprite.getPosition().x, groundHeight);
	}
}

// Reflector logic.
void Player::Reflect()
{
	isReflecting = true;
	reflector.setPosition(playerSprite.getPosition());
}

// Gets called when the player is hit.
void Player::PlayerHit()
{
	cout << "Player Died!" << endl;
}

// Rendering our player.
void Player::Draw(RenderWindow& window) {
	window.draw(playerSprite);
	
	// Only render the reflector when it's active.
	if (isReflecting) 
	{
		window.draw(reflector);
	}
}

// Returns the bounds of our player.
FloatRect Player::getBounds() 
{
	Sprite* ptrPlayer = &playerSprite;
	return ptrPlayer->getGlobalBounds();
}

// Returns the bounds of the reflector.
FloatRect Player::getReflectorBounds()
{
	RectangleShape* ptrReflector = &reflector;
	return ptrReflector->getGlobalBounds();
}

Player::~Player()
{
}
