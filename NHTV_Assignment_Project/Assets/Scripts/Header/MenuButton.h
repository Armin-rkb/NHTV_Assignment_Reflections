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
	void Update();
	void Draw(RenderWindow& window);

private:
	Texture buttonTexture;
	Sprite buttonSprite;
};

