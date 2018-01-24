#pragma once
#include "SFML\Graphics.hpp"
#include <functional>
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
	void CheckButtonPress(RenderWindow& window, void (*callback) (void));

private:

private:
	Texture buttonTexture;
	Sprite buttonSprite;
	bool isPressed = false;
};

