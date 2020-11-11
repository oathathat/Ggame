#include <SFML/Graphics.hpp>
#include <iostream>
#include"Animation.h"
#include"Player.h"
#include "Platform.h"
#include <stdlib.h>
#include <math.h>
#include<vector>



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ggame",sf::Style::Close);	
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.f, 600.0f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("resource/tux_from_linux.png");
	
	sf::RectangleShape background(sf::Vector2f(3569*3,200*3));
	sf::Texture backgroundtexture;
	backgroundtexture.loadFromFile("resource/MyMap.png");
	background.setTexture(&backgroundtexture);

	Player player(&playerTexture, sf::Vector2u(3, 9), 1.0f, 300.0f,300.0f);

	std::vector<Platform> platforms;

	//Floor
	platforms.push_back(Platform(nullptr, sf::Vector2f(3  *48.0f ,  3*16.0f),	  sf::Vector2f(3 *	24.0f, 3 *88.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3  * 17.0f,  3 * 16.0f), sf::Vector2f(3 * 55.5f,  3 * 113.9f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3  * 17.0f,  3 * 16.0f), sf::Vector2f(3 * 71.5f , 3 * 130.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3  * 177.0f, 3 * 8.0f), sf::Vector2f(3 * 168.5f, 3 * 142.0f)));
	
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 32.0f, 3 * 4.0f), sf::Vector2f(3 * 304.0f, 3 * 83.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 32.0f, 3 * 4.0f), sf::Vector2f(3 * 368.0f, 3 * 99.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 72.0f, 3 * 48.0f), sf::Vector2f(3 * 468.0f, 3 * 152.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 969.0f, 3 * 4.0f), sf::Vector2f(3 * 987.5f, 3 * 178.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 265.0f, 3 * 15.0f), sf::Vector2f(3 * 668.5f, 3 * 119.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 233.0f, 3 * 14.0f), sf::Vector2f(3 * 684.5f, 3 * 103.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 218.0f, 3 * 16.0f), sf::Vector2f(3 * 692.0f, 3 * 88.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 202.0f, 3 * 16.0f), sf::Vector2f(3 * 700.0f, 3 * 72.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 177.0f, 3 * 15.0f), sf::Vector2f(3 * 968.5f, 3 * 71.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 208.0f, 3 * 15.0f), sf::Vector2f(3 * 968.0f, 3 * 135.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 338.0f, 3 * 15.0f), sf::Vector2f(3 * 1288.0f, 3 * 71.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 305.0f, 3 * 16.0f), sf::Vector2f(3 * 1272.5f, 3 * 88.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 290.0f, 3 * 16.0f), sf::Vector2f(3 * 1264.0f, 3 * 104.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 274.0f, 3 * 15.0f), sf::Vector2f(3 * 1256.0f, 3 * 119.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 48.0f), sf::Vector2f(3 * 1496.0f, 3 * 152.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 65.0f, 3 * 8.0f), sf::Vector2f(3 * 1551.5f, 3 * 180.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 16.0f, 3 * 24.0f), sf::Vector2f(3 * 1640.0f, 3 * 188.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 32.0f, 3 * 15.0f), sf::Vector2f(3 * 1592.0f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 15.0f), sf::Vector2f(3 * 1648.0f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 160.0f, 3 * 15.0f), sf::Vector2f(3 * 1768.0f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 96.0f, 3 * 48.0f), sf::Vector2f(3 * 1800.0f, 3 * 113.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 15.0f), sf::Vector2f(3 * 1904.0f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 112.0f, 3 * 15.0f), sf::Vector2f(3 * 2016.0f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 15.0f), sf::Vector2f(3 * 1920.0f, 3 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 112.0f, 3 * 15.0f), sf::Vector2f(3 * 2032.0f, 3 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 15.0f), sf::Vector2f(3 * 2128.0f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 15.0f), sf::Vector2f(3 * 2144.0f, 3 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 16.0f, 3 * 64.0f), sf::Vector2f(3 * 2192.5f, 3 * 105.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 239.0f, 3 * 15.0f), sf::Vector2f(3 * 2320.5f, 3 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 336.0f, 3 * 16.0f), sf::Vector2f(3 * 2384.0f, 3 * 178.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 320.0f, 3 * 16.0f), sf::Vector2f(3 * 2392.0f, 3 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 304.0f, 3 * 16.0f), sf::Vector2f(3 * 2400.0f, 3 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 48.0f), sf::Vector2f(3 * 2624.0f, 3 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 128.0f, 3 * 48.0f), sf::Vector2f(3 * 2744.0f, 3 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 32.0f, 3 * 48.0f), sf::Vector2f(3 * 2856.0f, 3 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 32.0f, 3 * 48.0f), sf::Vector2f(3 * 2920.0f, 3 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 96.0f, 3 * 48.0f), sf::Vector2f(3 * 3016.0f, 3 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 208.0f, 3 * 16.0f), sf::Vector2f(3 * 3168.0f, 3 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 48.0f, 3 * 64.0f), sf::Vector2f(3 * 3296.0f, 3 * 154.0f)));	
	platforms.push_back(Platform(nullptr, sf::Vector2f(3 * 249.0f, 3 * 4.0f), sf::Vector2f(3 * 3444.5f, 3 * 188.0f)));
	

	

	float deltaTime = 0.0f;
	sf::Clock clock;

	window.setFramerateLimit(60);		

	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
				window.close();
		}
		
		//render
		player.Update(deltaTime);

		Collider playerCollision = player.GetCollider();
		sf::Vector2f direction;
		for(Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(playerCollision,direction,1.0f))
			{
				player.onCollision(direction);
			}
		
		view.setCenter(player.GetPosition());
		std::cout << player.GetPosition().x << " " << player.GetPosition().y << std::endl;
		
		window.clear();
		
		window.draw(background);
		window.setView(view);
		player.Draw(window);
		for (Platform& platform : platforms)
			platform.Draw(window);
		
		window.display();
	}
	return 0;
}