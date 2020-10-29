#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <math.h>
int main()
{
	//variable
	int x=0, y=0;
	float vx = 300, g = 10, ty = 0;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Ggame",sf::Style::Close);
		
	//circle
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Cyan);
	shape.setPosition({ 100.f, 100.f });

	// Texture
	sf::Texture playerTexture;
	if (!playerTexture.loadFromFile("resource/player.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("resource/town.png"))
	{
		std::cout << "Load failed" << std::endl;
	}
	//background
	sf::Sprite background;
	background.setTexture(backgroundTexture);

	// Player
	sf::Sprite player;
	player.setTexture(playerTexture);
	//int spriteSizeX = playerTexture.getSize().x / 3;
	//int spriteSizeY = playerTexture.getSize().y / 4;
	player.setTextureRect(sf::IntRect(20, 515, 24, 64));
	player.setPosition(20, 20);
	player.setScale(2.f, 2.f);
	int animationFrame = 0;

	//platform
	sf::RectangleShape platform;
	platform.setSize(sf::Vector2f(800, 10));
	platform.setFillColor(sf::Color::Magenta);
	platform.setPosition(0, 500);

	//time
	sf::Clock c;
	sf::Time t;

	while (window.isOpen()) 
	{
		t = c.restart();
		float deltatime = t.asSeconds();
		printf("%f\n", deltatime);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		window.draw(background);
		window.draw(player);
		window.draw(shape);
		window.draw(platform);
		window.setFramerateLimit(60);

		//keyboard
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.move(vx*deltatime, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				player.move(-vx*deltatime, 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getGlobalBounds().intersects(platform.getGlobalBounds()))
			{
				player.move(0.f, -1.f);
				ty = -25 * deltatime; //u
			}		
			ty = ty + deltatime;		
			//gravity
			if (player.getGlobalBounds().intersects(platform.getGlobalBounds()))
				{
					ty = 0;
				}
			else {player.move(.0f, g * ty);}		
			
			//circle ชน
			if (player.getGlobalBounds().intersects(shape.getGlobalBounds()))
			{
				player.setPosition(20, 20);
			}
			window.display();
	}
	return 0;
}