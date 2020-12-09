#include <SFML/Graphics.hpp>
#include <iostream>
#include"Animation.h"
#include"Player.h"
#include "Platform.h"
#include <stdlib.h>
#include <math.h>
#include<vector>
#include"Bullet.h"
#include"Enemy.h"
#include <sstream>
#include"Boss.h"
#include "Item.h"


int main()
{
	//variable
	int score, playerHP, life=3;
	int animationFrame = 0;
	int hit = 0;

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Ggame",sf::Style::Close);	
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.f, 600.0f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("resource/WizardOat.png");
	
	sf::RectangleShape background(sf::Vector2f(3569*4,200*4));
	sf::Texture backgroundtexture;
	backgroundtexture.loadFromFile("resource/MyMap2.png");
	background.setTexture(&backgroundtexture);

	Player* player;
	player = new Player(&playerTexture, sf::Vector2u(3, 4), 0.2f, 300.0f,240.0f);

	std::vector<Platform> platforms;
	std::vector<Platform> fire;
	std::vector<Bullet*> playerBullet;
	std::vector<Enemy*> monster;
	std::vector<Boss*> boss1;
	std::vector<Item*> coin;

	sf::Texture bulletTexture;
	bulletTexture.loadFromFile("resource/fireball1.png");

	sf::Texture monsterTexture;
	monsterTexture.loadFromFile("resource/monster1.png");

	sf::Texture BossTexture;
	BossTexture.loadFromFile("resource/monster1.png");

	sf::Texture coinTexture;
	coinTexture.loadFromFile("resource/coin1.png");

	
	
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 130.846f, 4 * 129.25f-6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 508.797f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 240.761f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 925.0f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1043.0f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2043.0f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 340.0f, 4 * 82.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 690.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 400.0f, 4 * 99.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 750.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 850.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 975.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1028.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1105.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1300.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1460.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1840.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1940.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2060.0f, 4 * 178.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2297.0f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2467.0f, 4 * 129.25f - 6) ));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2753.0f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2930.0f, 4 * 129.25f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 910.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1000.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1250.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1200.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1430.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 1760.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2000.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2130.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2288.0f, 4 * 66.0f - 6)));
		monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2430.0f, 4 * 66.0f - 6)));
		
	boss1.push_back(new Boss   (&BossTexture, sf::Vector2u(6, 2), 0.3f, 165.0f, sf::Vector2f(4* 3200.0f, 4 * 118.0f)));
	coin.push_back(new Item	(&coinTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(4 * 130.0f, 4 * 100.0f)));
    coin.push_back(new Item(&coinTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(4 * 1647.0f, 4 * 178.0f)));

	fire.push_back(Platform(nullptr, sf::Vector2f(4 * 174.0f, 4 * 14.0f), sf::Vector2f(4 * 353.0f, 4 * 193.0f)));
	fire.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 14.0f), sf::Vector2f(4 * 1617.0f, 4 * 196.0f)));
	fire.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 14.0f), sf::Vector2f(4 * 1681.0f, 4 * 196.0f)));

	//Floor
	platforms.push_back(Platform(nullptr, sf::Vector2f(4  *48.0f ,  4*16.0f),sf::Vector2f(4 *	33.0f, 4 *98.0f)));
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
	platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 28.0f, 4 * 15.0f), sf::Vector2f(4 * 1592.0f, 4 * 81.5f)));	
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
	float bulletTime = 0.0f;
	float hiTtime = 0.0f;
	sf::Clock clock;
	sf::Clock bullTime;
	sf::Clock hittime;
	window.setFramerateLimit(60);		

	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.f / 40.f)
			deltaTime = 1.f / 40.f;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed)
				window.close();
		}
		
		//render				
		player->Update(deltaTime,hit);
		hit = 0;

		Collider playerCollision = player->GetCollider();
		sf::Vector2f direction;

		for (Platform& fire : fire)
			if (fire.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
			{
				player->SetPosition(300.f, 250.f);
				life--;
				playerHP = 100;
			}

		for(Platform& platform : platforms)
			if (platform.GetCollider().CheckCollision(playerCollision,direction,1.0f))
			{
				player->onCollision(direction);
			}
		
		
		bulletTime = bullTime.getElapsedTime().asMilliseconds();
		if (bulletTime > 700) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (player->getDirection() == true) {
					playerBullet.push_back(new Bullet(&bulletTexture, 20, player->GetPosition().x+25, player->GetPosition().y, 1.0f, 0.0f));
					
				}
				if (player->getDirection() == false) {
					playerBullet.push_back(new Bullet(&bulletTexture, 20, player->GetPosition().x-25, player->GetPosition().y, -1.0f, 0.0f));
					
				}
				bullTime.restart();
			}
		}
		int counter1 = 0;
		for (auto* bullet : playerBullet) {
			bullet->Update();
			if (bullet->GetPosition().x >= view.getCenter().x + 500 || bullet->GetPosition().x <= view.getCenter().x-500 )
			{
				delete playerBullet.at(counter1);
				playerBullet.erase(playerBullet.begin() + counter1);
				counter1--;
			}
			counter1++;
		}
		
		for (auto* i : monster) {
			i->Update(deltaTime, player);
		}
		for (auto* i :boss1) {
			i->Update(deltaTime, player);
		}		
		for (auto* i : coin) {
			i->Update(deltaTime);
		}

		int counter=0;
		hiTtime = hittime.getElapsedTime().asSeconds();		
		for (auto* i : monster)
		{
			int counter = 0;
			for (auto* Bullet : playerBullet)
			{
				if (i->GetGlobalBounds().intersects(Bullet->GetGlobalBounds()))
				{
					i->DecreaseHP(1);
					delete playerBullet.at(counter);
					playerBullet.erase(playerBullet.begin() + counter);
					counter--;
				}			
				counter++;
			}
			if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()) && hiTtime>=2)
			{
				hit = 1;
				hittime.restart();
			}
		}
		
		int counterB = 0;
		for (auto* i : boss1)		
		{			
			for (auto* Bullet : playerBullet)
			{
				if (i->GetGlobalBounds().intersects(Bullet->GetGlobalBounds()))
				{
					i->DecreaseHP(1);
					delete playerBullet.at(counterB);
					playerBullet.erase(playerBullet.begin() + counterB);
					counterB--;
				}
				counterB++;
			}
			if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()) && hiTtime >= 2)
			{
				hit = 1;
				hittime.restart();
			}
		}
		int counterC = 0;
		for (auto* i : coin)
		{					
				if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()))
				{
			
					delete coin.at(counterB);
					coin.erase(coin.begin() + counterB);
					counterC--;
				}
				counterC++;		
		}

		for (auto* i : monster)
		{
			i->Update(deltaTime, player);

			if (i->getHP() <= 0)
			{
				delete monster.at(counter);
				monster.erase(monster.begin() + counter);
				counter--;				
			}
			counter++;
		}

		for (auto* i :boss1)
		{
			i->Update(deltaTime, player);

			if (i->getHP() <= 0)
			{
				delete boss1.at(counterB);
				boss1.erase(boss1.begin() + counterB);
				counterB--;
			}
			counterB++;
		}

		view.setCenter(player->GetPosition());
		std::cout << player->GetPosition().x/4 << " " << player->GetPosition().y/4 << std::endl;
		
		window.clear();		
		window.draw(background);
		window.setView(view);			

		
		//for (Platform& platform : platforms)
		//	platform.Draw(window);
		
		for (auto* i : monster)
			i->Draw(window);
		for (auto* bullet : playerBullet)
		{
			bullet->Draw(window);
		}
		for (auto* bullet : playerBullet) {
			bullet->bulletDirection(player->getDirection());
		}
		for (auto* Boss1 : boss1) 
		{
			Boss1->Draw(window);
		}
	

		for (auto* Coin : coin)
		{
			Coin->Draw(window);
		}
		player->Draw(window);

		window.display();
	
	}
	return 0;
}