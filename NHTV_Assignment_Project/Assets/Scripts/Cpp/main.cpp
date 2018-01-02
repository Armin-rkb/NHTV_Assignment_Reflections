#include <SFML\Graphics.hpp>
#include <iostream>
#include "../Header/Loader.h"
#include "../Header/player.h"

using namespace sf;
int main() {
	RenderWindow window(VideoMode(1280, 720), "Reflection", Style::Default);
	window.setFramerateLimit(60);
	
	Texture playerTexture;
	playerTexture.loadFromFile("Assets/Sprites/metal_ground.png");

	Player player = Player(1280/2, 720/2, playerTexture);

	// Load our images.
	InitLoader();

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
				case Event::TextEntered:
					if (evnt.text.unicode < 128) {
						printf("%c", evnt.text.unicode);
					}
					break;
			}
		}

		// Update.
		player.Update();
		
		// Clear.
		window.clear();

		// Drawing.
		player.Draw(window);
		window.display();
	}

	return 0;
}