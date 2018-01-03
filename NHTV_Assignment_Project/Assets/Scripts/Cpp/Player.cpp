#include "../Header/Player.h"
#include <iostream>

Sprite player;
Texture playerTexture;

Player::Player(float x, float y)
{
	playerTexture.loadFromFile("Assets/Sprites/metal_ground.png");
	player.setTexture(playerTexture);
	player.setPosition(x, y);
	player.setScale(0.2f, 0.2f);
}

// Update gets called every frame.
void Player::Update() {
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		player.move(-5, 0.0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		player.move(5, 0.0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		player.move(0.0, -5);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		player.move(0.0, 5);
	}
}

// Rendering our player.
void Player::Draw(RenderWindow& window) {
	window.draw(player);
}

Player::~Player()
{
}
