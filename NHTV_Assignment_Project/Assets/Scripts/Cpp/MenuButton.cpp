#include "../Header/MenuButton.h"


MenuButton::MenuButton(Texture& texture)
{
	buttonTexture = texture;
	buttonSprite.setTexture(buttonTexture);
}

// Registering the click of the left mouse button.
bool MenuButton::CheckButtonPress(RenderWindow& window)
{
	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (buttonSprite.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {
			isPressed = true;
		} else {
			isPressed = false;
		}
	}

	if (!Mouse::isButtonPressed(Mouse::Left) && isPressed) {
		isPressed = false;
		return true;
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
