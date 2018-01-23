#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class MenuButton
{
public:
	MenuButton(Texture& texture);
	~MenuButton();

public:
	void Draw(RenderWindow& window);
	bool CheckButtonPress(RenderWindow& window);

private:

private:
	Texture buttonTexture;
	Sprite buttonSprite;
	bool isPressed = false;
};

