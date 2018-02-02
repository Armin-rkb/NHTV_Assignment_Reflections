#include "../Header/UIButton.h"


UIButton::UIButton(float x, float y, string textureURL, string text, int textSize, string fontURL)
{
	// Setting the texture of the button and position.
	buttonTexture.loadFromFile(textureURL);
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(x, y);
	buttonSprite.setOrigin((float)buttonTexture.getSize().x / 2, (float)buttonTexture.getSize().y / 2);

	// If text exists....
	if (text != "") {
		Vector2f textPos(x, y - (textSize * 0.35));
		buttonText = new UIText(textPos.x, textPos.y, text, textSize, fontURL);
	}
}

// Registering the click of the left mouse button.
void UIButton::CheckButtonPress(RenderWindow& window, function<void()> callback)
{
	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (buttonSprite.getGlobalBounds().contains((float)Mouse::getPosition(window).x, (float)Mouse::getPosition(window).y)) {
			isPressed = true;
		} else {
			isPressed = false;
		}
	}

	if (!Mouse::isButtonPressed(Mouse::Left) && isPressed) {
		isPressed = false;
		callback();
	}
}

// Drawing our button.
void UIButton::Draw(RenderWindow& window)
{
	window.draw(buttonSprite);
	buttonText->Draw(window);
}

UIButton::~UIButton()
{
}
