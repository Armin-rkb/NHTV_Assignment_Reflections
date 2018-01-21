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
	Enemy enemy = Enemy();

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
			// Reflector Collision with ball.
			if (player.isReflecting && ball.ballState == DANGEROUS)
			{
				if (player.getReflectorBounds().intersects(ball.getBounds()))
				{
					// Change the direction.
					float deltaX = ball.ballSprite.getPosition().x - player.playerSprite.getPosition().x;
					float deltaY = ball.ballSprite.getPosition().y - player.playerSprite.getPosition().y;
					if (abs(deltaX) > abs(deltaY)) {
						if (deltaX <= 0) {
							ball.BallHit(-1, 0);
							cout << "Left?" << endl;
						}
						else {
							ball.BallHit(1, 0);
							cout << "Right?" << endl;
						}
					}
					else {
						if (deltaY <= 0) {
							ball.BallHit(0, -1);
							cout << "Top?" << endl;
						}
						else {
							ball.BallHit(0, 1);
							cout << "Bottom?" << endl;
						}
					}
				}
			}
			// Player collision with ball.
			else if (ball.ballState == DANGEROUS)
			{
				// Player loses!
				if (player.getBounds().intersects(ball.getBounds()))
				{
					window.close();
				}
			}

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
