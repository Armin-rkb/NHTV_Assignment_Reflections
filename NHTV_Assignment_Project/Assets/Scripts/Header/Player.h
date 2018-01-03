#pragma once
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;
class Player
{
public:
	Player(float x, float y);
	~Player();
	void Draw(RenderWindow& window);
	void Update();
};

