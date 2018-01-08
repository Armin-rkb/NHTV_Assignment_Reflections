#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Header/Loader.h"
#include "../Header/Player.h"
#include "../Header/Enemy.h"

using namespace sf;
int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	window.setFramerateLimit(60);
	
	Player player = Player(1280 / 2, 720 / 2);
	Enemy lazer = Enemy(120, 72);


	// TODO: Pre-load our textures.
	//InitLoader();

	while (window.isOpen()) {
		// Events.
		Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
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
		if (player.getBounds().intersects(lazer.getBounds())) {
			cout << "Collided with Enemy" << endl;
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