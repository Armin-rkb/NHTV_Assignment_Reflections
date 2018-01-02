#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
class Player
{
public:
	Player(float x, float y, Texture& texture);
	~Player();
	void Draw(RenderWindow& window);
	void Update();
};

