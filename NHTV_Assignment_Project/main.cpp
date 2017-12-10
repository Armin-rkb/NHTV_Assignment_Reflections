#include <SFML\Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Reflection", sf::Style::Default);
	sf::RectangleShape player(sf::Vector2f(100, 100));
	player.setFillColor(sf::Color::Blue);

	while (window.isOpen()) {
		// Events.
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::Resized:
					printf("New window size: %i x %i\n", evnt.size.width, evnt.size.height);
					break;
				case sf::Event::TextEntered:
					if (evnt.text.unicode < 128) {
						printf("%c", evnt.text.unicode);
					}
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			player.move(-0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			player.move(0.5f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			player.move(0.0f, -0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			player.move(0.0f, 0.5f);
		}

		// Clear.
		window.clear();
		// Drawing.
		window.draw(player);
		window.display();
	}

	return 0;
}