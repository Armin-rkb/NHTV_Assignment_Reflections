#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Header/Player.h"
#include "../Header/Ball.h"
#include "../Header/Enemy.h"
#include "../Header/MenuButton.h"

using namespace sf;

enum gameStates {
	STARTSCREEN,
	GAME,
	GAMEOVER
};
gameStates currentState = STARTSCREEN;

int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	window.setFramerateLimit(60);


	Texture groundTexture;
	groundTexture.loadFromFile("Assets/Sprites/metal_ground.png");
	Sprite ground;
	ground.setTexture(groundTexture);
	ground.setPosition(0, 620);

	// Menu vars.
	MenuButton menuButton(groundTexture);

	// Game vars.
	Player player = Player(1280 / 2, 586);
	Ball ball = Ball(120, 72);
	Enemy enemy = Enemy(player);

	// Game Loop.
	while (window.isOpen()) {
		// Events.
		Event evnt;
		while (window.pollEvent(evnt)) 
		{
			switch (evnt.type){
				case Event::Closed:
					window.close();
					break;
			}
		}
		
		switch (currentState) 
		{
		case STARTSCREEN:
			// Startscreen logic
			// Update.
			menuButton.Update();

			// Rendering.
			menuButton.Draw(window);
			break;
		case GAME:
			// Update.
			player.Update();
			ball.Update();
			enemy.Update();

			// Collision.
			ball.CheckCollision(player, enemy);

			// Clear.
			window.clear(Color(150, 150, 150));

			// Rendering.
			window.draw(ground);
			player.Draw(window);
			enemy.Draw(window);
			ball.Draw(window);
			window.display();
			break;
		}
	}

	return 0;
}
