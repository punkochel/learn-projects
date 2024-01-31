#include <SFML/Graphics.hpp>

enum {
	max_colors = 8,
	delay_blink = 250 // msec
};

static const sf::Color colors[max_colors] = {
	sf::Color::Black,
	sf::Color::Blue,
	sf::Color::Cyan,
	sf::Color::Green,
	sf::Color::Magenta,
	sf::Color::Red,
	sf::Color::White,
	sf::Color::Yellow
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Blink window");
	window.setVerticalSyncEnabled(true);

	int i = 0;
	sf::Time msec = sf::milliseconds(delay_blink);

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(colors[i]);
		window.display();

		sf::sleep(msec);

		i++;
		if(i == max_colors)
			i = 0;
	}
	return 0;
}