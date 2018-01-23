#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Header/Loader.h"
#include "../Header/Player.h"
#include "../Header/Ball.h"
#include "../Header/Enemy.h"

using namespace sf;

enum gameStates {
	STARTSCREEN,
	GAME,
	GAMEOVER
};

int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	window.setFramerateLimit(60);

	gameStates currentState = GAME;

	Texture groundTexture;
	groundTexture.loadFromFile("Assets/Sprites/metal_ground.png");
	Sprite ground;
	ground.setTexture(groundTexture);
	ground.setPosition(0, 620);

	Player player = Player(1280 / 2, 586);
	Ball ball = Ball(120, 72);
	Enemy enemy = Enemy(player);

	// TODO: Pre-load our textures.
	//InitLoader();

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

			// Drawing.
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
