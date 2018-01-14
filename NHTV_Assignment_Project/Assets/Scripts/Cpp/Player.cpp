#include "../Header/Player.h"
#include <iostream>

// Player Texture
Texture playerTexture;

// Gravity Variables.
const int groundHeight = 600;
const float movementSpeed = 9;
const float gravitySpeed = 13;
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
	reflector.setFillColor(Color(000, 000, 150));
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
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		playerSprite.move(0.0, -movementSpeed * 2);
		isJumping = true;
	} else {
		isJumping = false;
	}

	// Jumping
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		Reflect();
	} else {
		isReflecting = false;
	}

	// Gravity
	if (playerSprite.getPosition().y < groundHeight && !isJumping) {
		playerSprite.move(0, gravitySpeed);
	}
}

// Reflector logic.
void Player::Reflect()
{
	isReflecting = true;
	reflector.setPosition(playerSprite.getPosition());
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
