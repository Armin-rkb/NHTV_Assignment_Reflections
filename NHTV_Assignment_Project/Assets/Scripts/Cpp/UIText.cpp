#include "../Header/UIText.h"

UIText::UIText(float x, float y, string text, int textSize, string fontURL)
{
	textFont.loadFromFile(fontURL);
	uiText.setFont(textFont);
	uiText.setPosition(x, y);
	uiText.setCharacterSize(textSize);
	
	SetText(text);
	uiText.setOrigin(uiText.getLocalBounds().width / 2, uiText.getLocalBounds().height / 2);
}

// Drawing our text to the screen.
void UIText::Draw(RenderWindow& window)
{
	window.draw(uiText);
}

// Setting a new text
void UIText::SetText(string text)
{
	ssText.str("");
	ssText << text;
	uiText.setString(ssText.str());
}

UIText::~UIText()
{
}
