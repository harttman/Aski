#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

using namespace std;
using namespace sf;
int main() {
	const int windowWidth = 800; 
	const int windowHeigth = 600;
	// Ширина, довжина
	int score = 0;
	// підрахунок
	RenderWindow window(VideoMode(windowWidth, windowHeigth), "Asci");
	Font font;
	Text scoreInfo;
	Text buttonText;
	RectangleShape button(Vector2f(200, 100));


	if (!font.loadFromFile("fonts/Roboto-Bold.ttf"))
		return EXIT_FAILURE;


	scoreInfo.setFont(font);
	scoreInfo.setCharacterSize(24);
	scoreInfo.setFillColor(Color::White);
	scoreInfo.setPosition(10, 10);
	scoreInfo.setString(L"Валюта: 0");

	button.setFillColor(Color::Green);
	button.setPosition(windowWidth / 2 - 100, windowHeigth / 2 - 50); // 300, 250

	buttonText.setFont(font);
	buttonText.setCharacterSize(20);
	buttonText.setFillColor(Color::Black);
	buttonText.setString(L"Робити");
	buttonText.setPosition(button.getPosition().x + 50, button.getPosition().y + 30); // 330, 270


	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			Vector2i mousePos = Mouse::getPosition(window);
			// коли наша мишка у вікни отримуєм позицію.
			if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
				score++;
				scoreInfo.setString(L"Бали: " + to_wstring(score));
			}
		}

		window.clear(Color::Black);
		window.draw(button);
		window.draw(buttonText);
		window.draw(scoreInfo);
		window.display();
	}

	return 0;
}
