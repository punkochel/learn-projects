#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>

int main()
{
	/*
		Loading
	*/
	sf::Texture logo;
	if(!logo.loadFromFile("img/s_youtube.png"))
	{
		perror("Failed to load texture");
		return 1;
	}
	logo.setSmooth(true);

	sf::Sprite sprite;

	sprite.setTexture(logo);
	sprite.setTextureRect(sf::IntRect(6, 68, 348, 246));
	sprite.setPosition(sf::Vector2f(100.f, 100.f));

	/*
		Creating window
	*/
	sf::RenderWindow window(sf::VideoMode(800, 600), "Texture");
	window.setVerticalSyncEnabled(true);

	/*
		Main loop
	*/
	bool is_scale = false;
	sf::Time msec = sf::milliseconds(0);
	double scale = 1.0;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseMoved)
            {
            	if(event.mouseMove.x >= 6+100
            		&& event.mouseMove.x <= 348+100
            		&& event.mouseMove.y >= 68+100
            		&& event.mouseMove.y <= 246+100)
            	{
            		if(scale < 1.2)
            		{
            			scale += 0.001;
            			sprite.setScale(sf::Vector2f(scale, scale));
            		}
            	}
            	else if(scale > 1.0)
            	{
            		scale -= 0.001;
            		sprite.setScale(sf::Vector2f(scale, scale));
            	}
            }
		}

		window.clear();

		window.draw(sprite);

		window.display();

		sf::sleep(msec);
	}
	return 0;
}