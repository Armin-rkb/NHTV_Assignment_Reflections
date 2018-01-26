#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Header/States.h"
#include "../Header/MenuButton.h"
#include "../Header/Score.h"
#include "../Header/Player.h"
#include "../Header/Ball.h"
#include "../Header/EnemyHolder.h"

using namespace sf;

GameStates currentState = STARTSCREEN;

int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	window.setFramerateLimit(60);

	Texture groundTexture;
	groundTexture.loadFromFile("Assets/Sprites/metal_ground.png");

	Texture enemyTexture;
	enemyTexture.loadFromFile("Assets/Sprites/enemy_invader.png");

	// Menu vars.
	MenuButton menuButton(groundTexture);
	// Game vars.
	Score score = Score(20, 660, 30);
	Player player = Player(1280 / 2, 586);
	Ball ball = Ball(120, 72);
	EnemyHolder enemySpawner = EnemyHolder(enemyTexture, player, ball, score);

	Sprite ground;
	ground.setTexture(groundTexture);
	ground.setPosition(0, 620);

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
		int i = 0;
		switch (currentState)
		{
		case STARTSCREEN:
			// Startscreen logic.
			// Update.
			menuButton.CheckButtonPress(window, []{
				ChangeState(GAME);
			});

			// Clear.
			window.clear(Color(0, 0, 150));
			
			// Rendering.
			menuButton.Draw(window);

			// Display the window.
			window.display();
			break;
		case GAME:
			// Game logic.
			// Update.
			player.Update();
			ball.Update();
			enemySpawner.Update();

			// Collision.
			ball.CheckCollision(player);

			// Clear.
			window.clear(Color(150, 150, 150));

			// Rendering.
			window.draw(ground);
			score.Draw(window);
			player.Draw(window);
			enemySpawner.Draw(window);
			ball.Draw(window);

			// Display the window.
			window.display();
			break;
		case GAMEOVER:
			// Clear.
			window.clear(Color(150, 150, 150));

			// Rendering.
			window.draw(ground);
			score.Draw(window);
			player.Draw(window);
			enemySpawner.Draw(window);
			ball.Draw(window);

			// Display the window.
			window.display();
		}
	}

	return 0;
}