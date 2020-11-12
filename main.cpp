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
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Ggame",sf::Style::Close);	
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.f, 600.0f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("resource/tux_from_linux.png");
	
	sf::RectangleShape background(sf::Vector2f(3569*4,200*4));
	sf::Texture backgroundtexture;
	backgroundtexture.loadFromFile("resource/MyMap.png");
	background.setTexture(&backgroundtexture);

	Player player(&playerTexture, sf::Vector2u(3, 9), 1.0f, 300.0f,260.0f);

	std::vector<Platform> platforms;

	//Floor
	platforms.push_back(Platform(nullptr, sf::Vector2f(4  *48.0f ,  4*16.0f),sf::Vector2f(4 *	24.0f, 4 *88.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4  * 9.0f,  4 * 16.0f), sf::Vector2f(4 * 51.5f,  4 * 98.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4  * 17.0f,  4 * 16.0f), sf::Vector2f(4 * 63.5f , 4 * 114.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4  * 17.0f,  4 * 16.0f), sf::Vector2f(4 * 79.5f , 4 * 130.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4  * 177.0f, 4 * 50.0f), sf::Vector2f(4 * 175.5f, 4 * 163.0f)));	
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 8.0f), sf::Vector2f(4 * 312.0f, 4 * 95.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 8.0f), sf::Vector2f(4 * 376.0f, 4 * 111.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 72.0f, 4 * 48.0f), sf::Vector2f(4 * 476.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 969.0f, 4 * 4.0f), sf::Vector2f(4 * 995.5f, 4 * 188.0f)));	
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 200.0f, 4 * 63.0f), sf::Vector2f(4 * 708.0f, 4 * 105.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 47.0f), sf::Vector2f(4 * 600.0f, 4 * 113.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 31.0f), sf::Vector2f(4 * 584.0f, 4 * 121.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 15.0f), sf::Vector2f(4 * 560.0f, 4 * 129.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 177.0f, 4 * 15.0f), sf::Vector2f(4 * 976.5f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 208.0f, 4 * 15.0f), sf::Vector2f(4 * 976.0f, 4 * 145.5f)));	
	//bug
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 70.0f, 4 * 63.0f), sf::Vector2f(4 * 1163.0f, 4 * 105.5f)));	
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 202.0f, 4 * 63.0f), sf::Vector2f(4 * 1299.0f, 4 * 105.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 48.0f), sf::Vector2f(4 * 1408.0f, 4 * 98.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 31.0f), sf::Vector2f(4 * 1424.0f, 4 * 89.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 15.0f), sf::Vector2f(4 * 1448.0f, 4 * 81.5f)));


	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 48.0f), sf::Vector2f(4 * 1504.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 65.0f, 4 * 8.0f), sf::Vector2f(4 * 1559.5f, 4 * 190.0f)));
	
	//bug
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 14.0f), sf::Vector2f(4 * 1648.0f, 4 * 193.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 15.0f), sf::Vector2f(4 * 1592.0f, 4 * 81.5f)));	
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 15.0f), sf::Vector2f(4 * 1648.0f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 160.0f, 4 * 15.0f), sf::Vector2f(4 * 1768.0f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 96.0f, 4 * 48.0f), sf::Vector2f(4 * 1800.0f, 4 * 113.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 15.0f), sf::Vector2f(4 * 1904.0f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 112.0f, 4 * 15.0f), sf::Vector2f(4 * 2016.0f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 15.0f), sf::Vector2f(4 * 1920.0f, 4 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 112.0f, 4 * 15.0f), sf::Vector2f(4 * 2032.0f, 4 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 15.0f), sf::Vector2f(4 * 2128.0f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 15.0f), sf::Vector2f(4 * 2144.0f, 4 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 64.0f), sf::Vector2f(4 * 2192.5f, 4 * 105.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 239.0f, 4 * 15.0f), sf::Vector2f(4 * 2320.5f, 4 * 81.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 336.0f, 4 * 16.0f), sf::Vector2f(4 * 2384.0f, 4 * 178.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 320.0f, 4 * 16.0f), sf::Vector2f(4 * 2392.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 304.0f, 4 * 16.0f), sf::Vector2f(4 * 2400.0f, 4 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 48.0f), sf::Vector2f(4 * 2624.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 128.0f, 4 * 48.0f), sf::Vector2f(4 * 2744.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 48.0f), sf::Vector2f(4 * 2856.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 48.0f), sf::Vector2f(4 * 2920.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 96.0f, 4 * 48.0f), sf::Vector2f(4 * 3016.0f, 4 * 162.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 208.0f, 4 * 16.0f), sf::Vector2f(4 * 3168.0f, 4 * 145.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 64.0f), sf::Vector2f(4 * 3296.0f, 4 * 154.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 249.0f, 4 * 4.0f), sf::Vector2f(4 * 3444.5f, 4 * 188.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 1592.0f, 4 * 4.0f), sf::Vector2f(4 * 2500.0f, 4 * 188.0f)));

	//ceiling
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 256.0f, 4 * 47.0f), sf::Vector2f(4 * 136.0f, 4 * 33.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 3306.0f, 4 * 15.0f), sf::Vector2f(4 * 1916.0f, 4 * 17.5f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 61.0f, 4 * 32.0f), sf::Vector2f(4 * 481.5f, 4 * 41.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 32.0f, 4 * 48.0f), sf::Vector2f(4 * 3304.0f, 4 * 49.0f)));
	
	
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