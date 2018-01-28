#pragma once
#include "SFML/Graphics.hpp"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

class UIText
{
public:
	UIText(float x, float y, string text, int textSize, string fontURL);
	~UIText();

public:
	void Draw(RenderWindow& window);
	void SetText(string text);

private:
	Text uiText;
	Font textFont;
	ostringstream ssText;

};

