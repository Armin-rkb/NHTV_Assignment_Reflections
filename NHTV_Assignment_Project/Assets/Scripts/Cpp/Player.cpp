#include "../Header/Player.h"
#include <iostream>

Texture playerTexture;

Player::Player(float x, float y)
{
	playerTexture.loadFromFile("Assets/Sprites/player.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(x, y);
}

// Update gets called every frame.
void Player::Update() {
	// Player Input.
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		playerSprite.move(-5, 0.0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		playerSprite.move(5, 0.0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		playerSprite.move(0.0, -5);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		playerSprite.move(0.0, 5);
	}
}

// Rendering our player.
void Player::Draw(RenderWindow& window) {
	window.draw(playerSprite);
}

FloatRect Player::getBounds() {
	Sprite* ptrSprite = &playerSprite;
	return ptrSprite->getGlobalBounds();
}

Player::~Player()
{
}
