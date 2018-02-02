#include <SFML\Graphics.hpp>
#include <SFML\Audio\Music.hpp>
#include <iostream>
#include <windows.h>
#include "../Header/States.h"
#include "../Header/UIButton.h"
#include "../Header/UIText.h"
#include "../Header/Score.h"
#include "../Header/Player.h"
#include "../Header/Ball.h"
#include "../Header/EnemyHolder.h"

GameStates currentState = STARTSCREEN;
 
Score* scorePtr;
Player* playerPtr;
Ball* ballPtr;
EnemyHolder* enemyHolderPtr;

Music* menuMusicPtr;
Music* gameMusicPtr;

int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	const int FPS = 60; // The desired Fps.
	const int SKIP_TICKS = 1000 / FPS;
	const int MAX_FRAMESKIP = 10;
	Clock gameTime;
	DWORD nextGameTick = gameTime.getElapsedTime().asMilliseconds();
	int loops = 0;

	// Music.
	Music menuMusic;
	menuMusic.openFromFile("Assets/Sounds/menu.wav");
	menuMusic.setVolume(8);
	menuMusic.setLoop(true);
	menuMusic.play();

	Music gameMusic;
	gameMusic.openFromFile("Assets/Sounds/game.wav");
	gameMusic.setVolume(8);
	gameMusic.setLoop(true);

	// Textures.
	Texture menuTexture;
	menuTexture.loadFromFile("Assets/Sprites/Aegis_Reflector_Menu_Screen.png");

	Texture tutorialTexture;
	tutorialTexture.loadFromFile("Assets/Sprites/tutorial.png");

	Texture groundTexture;
	groundTexture.loadFromFile("Assets/Sprites/metal_ground.png");

	Texture enemyTexture;
	enemyTexture.loadFromFile("Assets/Sprites/enemy_invader.png");

	// Menu vars.
	UIText gameTitle(640, 100, "Aegis Reflector", 72, "Assets/Fonts/pixelFont.ttf");
	UIButton playGameButton(640, 345, "Assets/Sprites/button_red.png", "PLAY", 52);
	UIButton helpButton(640, 440, "Assets/Sprites/button_blue.png", "HELP", 52);
	
	Sprite menuBG;
	menuBG.setTexture(menuTexture);

	Sprite tutorial;
	tutorial.setTexture(tutorialTexture);
	
	// Game vars.
	Score score = Score(100, 660, 30);
	Player player = Player();
	Ball ball = Ball();
	EnemyHolder enemyHolder = EnemyHolder(enemyTexture, player, ball, score);

	Sprite ground;
	ground.setTexture(groundTexture);
	ground.setPosition(0, 620);

	// Game over vars.
	UIText gameoverText(655, 250, "Game over!", 72, "Assets/Fonts/pixelFont.ttf", Color(220, 50, 0));
	UIText endScoreText(640, 310, "End score: ", 52, "Assets/Fonts/pixelFont.ttf");
	UIButton playAgainButton(640, 455, "Assets/Sprites/button_red.png", "RETRY", 52);
	UIButton mainMenuButton(640, 550, "Assets/Sprites/button_blue.png", "MENU", 52);

	// Assign pointers.
	scorePtr = &score;
	playerPtr = &player;
	ballPtr = &ball;
	enemyHolderPtr = &enemyHolder;
	menuMusicPtr = &menuMusic;
	gameMusicPtr = &gameMusic;

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
			while ((DWORD)gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				playGameButton.CheckButtonPress(window, [] {
					menuMusicPtr->stop();
					gameMusicPtr->play();
					ChangeState(GAME);
				});
				
				helpButton.CheckButtonPress(window, [] {
					ChangeState(TUTORIAL);
				});

				nextGameTick += SKIP_TICKS;
				loops++;
			}

			// Clear.
			window.clear(Color(0, 0, 150));
			
			// Rendering.
			window.draw(menuBG);
			gameTitle.Draw(window);
			playGameButton.Draw(window);
			helpButton.Draw(window);

			// Display the window.
			window.display();
			break;	
		case TUTORIAL:
			// Tutorial logic.
			// Update.
			loops = 0;
			while ((DWORD)gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				playGameButton.CheckButtonPress(window, [] {
					menuMusicPtr->stop();
					gameMusicPtr->play();
					ChangeState(GAME);
				});

				nextGameTick += SKIP_TICKS;
				loops++;
			}

			// Clear.
			window.clear(Color(0, 0, 150));
			
			// Rendering.
			window.draw(tutorial);
			playGameButton.Draw(window);

			// Display the window.
			window.display();
			break;
		case GAME:
			// Game logic.
			loops = 0;
			while ((DWORD)gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				// Update.
				player.Update();
				ball.Update();
				enemyHolder.Update();

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
			enemyHolder.Draw(window);
			ball.Draw(window);

			// Display the window.
			window.display();
			break;
		case GAMEOVER:
			// Gameover logic.
			loops = 0;
			while ((DWORD)gameTime.getElapsedTime().asMilliseconds() > nextGameTick && loops < MAX_FRAMESKIP)
			{
				// Update.
				playAgainButton.CheckButtonPress(window, [] {
					gameMusicPtr->play();

					playerPtr->Reset();
					ballPtr->Reset();
					enemyHolderPtr->ClearEnemies();
					scorePtr->Clear();
					ChangeState(GAME);
				});
				mainMenuButton.CheckButtonPress(window, [] {
					gameMusicPtr->stop();
					menuMusicPtr->play();

					playerPtr->Reset();
					ballPtr->Reset();
					enemyHolderPtr->ClearEnemies();
					scorePtr->Clear();
					ChangeState(STARTSCREEN);
				});

				nextGameTick += SKIP_TICKS;
				loops++;
			}

			// Clear.
			window.clear(Color(150, 150, 150));

			// Rendering.
			window.draw(ground);
			player.Draw(window);
			enemyHolder.Draw(window);
			ball.Draw(window);
			endScoreText.SetText("End score: " + to_string(score.GetScore()));
			endScoreText.Draw(window);
			gameoverText.Draw(window);

			playAgainButton.Draw(window);
			mainMenuButton.Draw(window);

			// Display the window.
			window.display();
		}
	}

	return 0;
}