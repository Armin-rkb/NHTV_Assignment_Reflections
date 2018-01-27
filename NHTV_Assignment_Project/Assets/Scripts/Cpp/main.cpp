#include <SFML\Graphics.hpp>
#include <iostream>
#include <windows.h>
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
	const int FPS = 60; // The desired Fps.
	const int SKIP_TICKS = 1000 / FPS;
	const int MAX_FRAMESKIP = 10;
	Clock gameTime;
	DWORD nextGameTick = gameTime.getElapsedTime().asMilliseconds();
	int loops = 0;


	// Textures.
	Texture groundTexture;
	groundTexture.loadFromFile("Assets/Sprites/metal_ground.png");

	Texture enemyTexture;
	enemyTexture.loadFromFile("Assets/Sprites/enemy_invader.png");

	// Menu vars.
	MenuButton PlayGameButton(groundTexture);
	MenuButton MainMenuButton(groundTexture);
	
	// Game vars.
	Score score = Score(20, 660, 30);
	Player player = Player(1280 / 2, 586);
	Ball ball = Ball(120, 72);
	EnemyHolder enemySpawner = EnemyHolder(enemyTexture, player, ball, score);

	Sprite ground;
	ground.setTexture(groundTexture);
	ground.setPosition(0, 620);

	// Game Loop.
	Event evnt;
	while (window.isOpen()) {
		// Events.
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
			// Startscreen logic.
			// Update.
			loops = 0;
			while (gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				PlayGameButton.CheckButtonPress(window, [] {
					ChangeState(GAME);
				});

				nextGameTick += SKIP_TICKS;
				loops++;
			}

			// Clear.
			window.clear(Color(0, 0, 150));
			
			// Rendering.
			PlayGameButton.Draw(window);

			// Display the window.
			window.display();
			break;
		case GAME:
			// Game logic.
			loops = 0;
			while (gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				// Update.
				player.Update();
				ball.Update();
				enemySpawner.Update();

				// Collision.
				ball.CheckCollision(player);

				nextGameTick += SKIP_TICKS;
				loops++;
			}

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
			// Gameover logic.
			
			loops = 0;
			while (gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				// Update.
				MainMenuButton.CheckButtonPress(window, [] {
					ChangeState(GAME);
				});

				nextGameTick += SKIP_TICKS;
				loops++;
			}

			// Clear.
			window.clear(Color(150, 150, 150));

			// Rendering.
			window.draw(ground);
			score.Draw(window);
			player.Draw(window);
			enemySpawner.Draw(window);
			ball.Draw(window);

			MainMenuButton.Draw(window);

			// Display the window.
			window.display();
		}
	}

	return 0;
}