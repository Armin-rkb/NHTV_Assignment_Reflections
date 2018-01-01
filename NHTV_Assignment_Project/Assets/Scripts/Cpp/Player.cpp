#include "../Header/Player.h"
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Sprite player;
Player::Player(float x, float y, Texture& texture)
{
	player.setTexture(texture);
	player.setPosition(x, y);
	player.setScale(0.2f, 0.2f);
}

void Player::Update() {
	cout << "updating" << endl;
	
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		player.move(-0.25f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		player.move(0.25f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		player.move(0.0f, -0.25f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		player.move(0.0f, 0.25f);
	}
}

void Player::Draw(RenderWindow& window) {
	window.draw(player);
}

Player::~Player()
{
}
