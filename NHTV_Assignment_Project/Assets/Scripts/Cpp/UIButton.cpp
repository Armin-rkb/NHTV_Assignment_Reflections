#include "../Header/UIButton.h"


UIButton::UIButton(float x, float y, string textureURL)
{
	// Setting the texture of the button and position.
	buttonTexture.loadFromFile(textureURL);
	buttonSprite.setTexture(buttonTexture);
	buttonSprite.setPosition(x, y);
	buttonSprite.setOrigin((float)buttonTexture.getSize().x / 2, (float)buttonTexture.getSize().y / 2);
	buttonSprite.setScale(4, 4);
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
}

UIButton::~UIButton()
{
}
