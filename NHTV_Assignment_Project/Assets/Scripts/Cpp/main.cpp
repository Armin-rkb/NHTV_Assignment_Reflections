#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Header/Loader.h"
#include "../Header/Player.h"
#include "../Header/Enemy.h"

using namespace sf;
int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	window.setFramerateLimit(60);
	
	Player player = Player(1280 / 2, 600);
	Enemy lazer = Enemy(120, 72);

	// TODO: Pre-load our textures.
	//InitLoader();

	while (window.isOpen()) {
		// Events.
		Event evnt;
		while (window.pollEvent(evnt)) 
		{
			switch (evnt.type)
			{
				case Event::Closed:
					window.close();
					break;
				case Event::Resized:
					printf("New window size: %i x %i\n", evnt.size.width, evnt.size.height);
					break;
			}
		}

		// Update.
		player.Update();
		lazer.Update();

		// Collision.
		if (player.isReflecting && lazer.canHit) 
		{
			if (player.getReflectorBounds().intersects(lazer.getBounds())) 
			{
				// Change the direction.
				float deltaX = lazer.enemySprite.getPosition().x - player.playerSprite.getPosition().x;
				float deltaY = lazer.enemySprite.getPosition().y - player.playerSprite.getPosition().y;
				if (abs(deltaX) > abs(deltaY)) 
				{
					if (deltaX <= 0) {
						lazer.ChangeDirX();
						cout << "Left?" << endl;
					}
					else 
					{
						lazer.ChangeDirX();
						cout << "Right?" << endl;
					}
				}
				else 
				{
					if (deltaY <= 0) 
					{
						lazer.ChangeDirY();
						cout << "Top?" << endl;
					}
					else 
					{
						lazer.ChangeDirY();
						cout << "Bottom?" << endl;
					}
				}

				// Add ball speed.
				//lazer.IncreaseBallSpeed();
			}
		}
		else if (lazer.canHit)
		{
			// Player gets loses!
			if (player.getBounds().intersects(lazer.getBounds())) 
			{
				window.close();
			}
		}

		// Clear. 
		window.clear(Color(150,150,150));

		// Drawing.
		player.Draw(window);
		lazer.Draw(window);
		window.display();
	}

	return 0;
}