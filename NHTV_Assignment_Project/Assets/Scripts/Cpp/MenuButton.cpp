#include "../Header/MenuButton.h"


MenuButton::MenuButton(Texture& texture)
{
	// Setting the texture of the button.
	buttonTexture = texture;
	buttonSprite.setTexture(buttonTexture);
}

// Registering the click of the left mouse button.
void MenuButton::CheckButtonPress(RenderWindow& window, void(*callback) (void))
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
void MenuButton::Draw(RenderWindow& window)
{
	window.draw(buttonSprite);
}

MenuButton::~MenuButton()
{
}
