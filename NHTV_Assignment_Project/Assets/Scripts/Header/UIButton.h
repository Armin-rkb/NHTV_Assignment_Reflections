#pragma once
#include "SFML\Graphics.hpp"
#include <functional>

using namespace std;
using namespace sf;

class UIButton
{
public:
	UIButton(float x, float y, string textureURL);
	~UIButton();

public:
	void Draw(RenderWindow& window);
	void CheckButtonPress(RenderWindow& window, function<void()> callback);

private:
	Texture buttonTexture;
	Sprite buttonSprite;
	bool isPressed = false;
};

