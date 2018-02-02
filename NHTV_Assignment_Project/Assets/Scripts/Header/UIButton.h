#pragma once
#include "SFML\Graphics.hpp"
#include "../Header/UIText.h"
#include <functional>

using namespace std;
using namespace sf;

class UIButton
{
public:
	UIButton(float x, float y, string textureURL, string text = "", int textSize = 32, string fontURL= "Assets/Fonts/pixelFont.ttf");
	~UIButton();

public:
	void Draw(RenderWindow& window);
	void CheckButtonPress(RenderWindow& window, function<void()> callback);

private:
	Texture buttonTexture;
	Sprite buttonSprite;
	UIText* buttonText;
	bool isPressed = false;
};

