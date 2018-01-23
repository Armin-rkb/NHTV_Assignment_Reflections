#include "../Header/MenuButton.h"


MenuButton::MenuButton(Texture& texture)
{
	buttonTexture = texture;
	buttonSprite.setTexture(buttonTexture);
}

void MenuButton::Update()
{
	if (Mouse::isButtonPressed(Mouse::Left)) {
		cout << "button pressed!" << endl;
	}
}

void MenuButton::Draw(RenderWindow& window)
{
	window.draw(buttonSprite);
}

MenuButton::~MenuButton()
{
}
