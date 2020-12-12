#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <iostream>
#include"Animation.h"
#include"Player.h"
#include "Platform.h"
#include <stdlib.h>
#include <time.h>
#include<vector>
#include"Bullet.h"
#include"Enemy.h"
#include <sstream>
#include"Boss.h"
#include "Item.h"
#include"Menu.h"
#include"retryMenu.h"
int section_number = 0;

int main()
{
	//variable	
	int totalscore = 0;

	while (true)
	{
		if (section_number == 0) {
			sf::SoundBuffer  select;
			sf::Sound  selectSound;
			select.loadFromFile("resource/menuselect.wav");
			selectSound.setBuffer(select);
			selectSound.setVolume(40.0);
			if (totalscore != 0)
			{
				selectSound.play();
			}

			sf::RenderWindow window(sf::VideoMode(1000, 800), "Ggame");
			Menu menu(window.getSize().x, window.getSize().y);
			sf::Texture Mtexture;
			Mtexture.loadFromFile("resource/menuBG.jpg");

			sf::Sprite Mbackground;
			Mbackground.setTexture(Mtexture);
			Mbackground.setPosition(0, 15);

			while (window.isOpen())
			{

				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							menu.MoveUp();
							break;
						case sf::Keyboard::Down:
							menu.MoveDown();
							break;
						case sf::Keyboard::Return:
							switch (menu.GetPressedItem())
							{
							case 0:
								section_number = 1;
								std::cout << "Play button has been pressed" << std::endl;
								window.close();
								break;
							case 1:
								section_number = 2;
								window.close();
								break;
							case 2:
								return 0;

							}
						}
					}
				}

				window.clear();
				window.draw(Mbackground);
				menu.draw(window);
				window.display();
			}
		}
		if (section_number == 1) {

			sf::SoundBuffer  select;
			sf::Sound  selectSound;
			select.loadFromFile("resource/menuselect.wav");
			selectSound.setBuffer(select);
			selectSound.setVolume(40.0);
			selectSound.play();

			sf::RenderWindow window(sf::VideoMode(1000, 800), "Ggame", sf::Style::Close);

			sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.f, 600.0f));
			int hit = 0;
			int ulti = 0;
			int score = 0;
			unsigned int randomPercent = 33;
			int animationFrame = 0;

			sf::Texture playerTexture;
			playerTexture.loadFromFile("resource/WizardOat.png");
			sf::RectangleShape background(sf::Vector2f(3569 * 4, 200 * 4));
			sf::Texture backgroundtexture;
			backgroundtexture.loadFromFile("resource/MyMap2.png");
			background.setTexture(&backgroundtexture);

			sf::RectangleShape HPbar(sf::Vector2f(500, 500));
			sf::Texture HPbarTexture;
			HPbarTexture.loadFromFile("resource/HP.png");
			HPbar.setTexture(&HPbarTexture);
			HPbar.setTextureRect((sf::IntRect(0, 0, HPbarTexture.getSize().x / 4, HPbarTexture.getSize().y)));
			HPbar.setSize(sf::Vector2f(175.f, 176.f));
			HPbar.setScale(0.3, 0.3);

			Player* player;
			player = new Player(&playerTexture, sf::Vector2u(3, 4), 0.2f, 300.0f, 240.0f);
			player->SetPosition(player->getspawnX(), player->getspawnY());

			std::vector<Platform> platforms;
			std::vector<Platform> fire;
			std::vector<Bullet*> playerBullet;
			std::vector<Bullet*> special;
			std::vector<Enemy*> monster;
			std::vector<Boss*> boss1;
			std::vector<Item*> coin;
			std::vector<Item*> potion;
			std::vector<Item*> mana;
			std::vector<Item*> heart;
			std::vector<Item*> key;



			sf::Texture bulletTexture;
			bulletTexture.loadFromFile("resource/fireball1.png");

			sf::Texture specialTexture;
			specialTexture.loadFromFile("resource/Ufireball1.png");

			sf::Texture monsterTexture;
			monsterTexture.loadFromFile("resource/monster1.png");

			sf::Texture BossTexture;
			BossTexture.loadFromFile("resource/ghost.png");

			sf::Texture coinTexture;
			coinTexture.loadFromFile("resource/coin1.png");

			sf::Texture potionTexture;
			potionTexture.loadFromFile("resource/HPpotion.png");

			sf::Texture manaTexture;
			manaTexture.loadFromFile("resource/mana.png");

			sf::Texture heartTexture;
			heartTexture.loadFromFile("resource/heart1.png");

			sf::Texture keyTexture;
			keyTexture.loadFromFile("resource/key.png");

			//TEXT
			sf::Font lifeFont;
			lifeFont.loadFromFile("resource/Ancient.ttf");
			sf::Text lifeText;
			lifeText.setCharacterSize(50);
			lifeText.setPosition({ 140 ,240 });
			lifeText.setFont(lifeFont);
			lifeText.setString("LIFE");
			lifeText.setFillColor(sf::Color::Color(255, 127, 80));

			sf::Clock Timer;
			int timeCount = 0;
			sf::Text gameTime;
			gameTime.setCharacterSize(50);
			gameTime.setPosition({ 140 ,240 });
			gameTime.setFont(lifeFont);
			gameTime.setString(std::to_string(timeCount));
			gameTime.setFillColor(sf::Color::Color(250, 250, 210));

			sf::Text lifeNum;
			lifeNum.setCharacterSize(50);
			lifeNum.setPosition({ 140 ,240 });
			lifeNum.setFont(lifeFont);
			lifeNum.setString(std::to_string(player->getLife()));
			lifeNum.setFillColor(sf::Color::Color(255, 127, 80));

			sf::Text scorenum;
			scorenum.setCharacterSize(40);
			scorenum.setPosition({ 140 ,240 });
			scorenum.setFont(lifeFont);
			scorenum.setString(std::to_string(score));
			scorenum.setFillColor(sf::Color::Color(255, 160, 122));

			sf::Text scoretext;
			scoretext.setCharacterSize(40);
			scoretext.setPosition({ 140 ,240 });
			scoretext.setFont(lifeFont);
			scoretext.setString("Score");
			scoretext.setFillColor(sf::Color::Color(255, 160, 122));

			//sound
			sf::SoundBuffer shotBuff;
			shotBuff.loadFromFile("resource/fireball.wav");

			sf::SoundBuffer coinBuff;
			coinBuff.loadFromFile("resource/coin.wav");

			sf::SoundBuffer enemydieBuff;
			enemydieBuff.loadFromFile("resource/death.wav");

			sf::SoundBuffer hitBuff;
			hitBuff.loadFromFile("resource/hit.wav");

			sf::SoundBuffer lifeBuff;
			lifeBuff.loadFromFile("resource/life.wav");

			sf::SoundBuffer gameoverBuff;
			gameoverBuff.loadFromFile("resource/Gameover.wav");

			sf::SoundBuffer ultiBuff;
			ultiBuff.loadFromFile("resource/FireballWhoosh.wav");

			sf::SoundBuffer powerupBuff;
			powerupBuff.loadFromFile("resource/mana.wav");

			sf::SoundBuffer HPBuff;
			HPBuff.loadFromFile("resource/HP.wav");

			sf::SoundBuffer delifeBuff;
			delifeBuff.loadFromFile("resource/Delife.wav");

			sf::SoundBuffer hitplayerBuff;
			hitplayerBuff.loadFromFile("resource/hitplayer.wav");


			sf::Sound shotSound;
			shotSound.setBuffer(shotBuff);

			sf::Sound coinSound;
			coinSound.setBuffer(coinBuff);

			sf::Sound enemydieSound;
			enemydieSound.setBuffer(enemydieBuff);

			sf::Sound hitSound;
			hitSound.setBuffer(hitBuff);

			sf::Sound lifeSound;
			lifeSound.setBuffer(lifeBuff);

			sf::Sound gameoverSound;
			gameoverSound.setBuffer(gameoverBuff);

			sf::Sound ultiSound;
			ultiSound.setBuffer(ultiBuff);

			sf::Sound powerupSound;
			powerupSound.setBuffer(powerupBuff);

			sf::Sound HPsound;
			HPsound.setBuffer(HPBuff);

			sf::Sound delifeSound;
			delifeSound.setBuffer(delifeBuff);

			sf::Sound hitplayerSound;
			hitplayerSound.setBuffer(hitplayerBuff);


			shotSound.setVolume(30.0);
			coinSound.setVolume(30.0);
			enemydieSound.setVolume(30.0);
			hitSound.setVolume(30.0);
			lifeSound.setVolume(40.0);
			gameoverSound.setVolume(30.0);
			ultiSound.setVolume(50.0);
			powerupSound.setVolume(30.0);
			HPsound.setVolume(50.0);
			delifeSound.setVolume(30.0);
			hitplayerSound.setVolume(28.0);


			sf::Music song;
			song.openFromFile("resource/song.wav");
			song.setVolume(18.0);
			song.play();

			monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 130.846f, 4 * 129.25f - 6)));
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
			monster.push_back(new Enemy(&monsterTexture, sf::Vector2u(6, 2), 0.3f, 140.0f, sf::Vector2f(4 * 2467.0f, 4 * 129.25f - 6)));
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

			boss1.push_back(new Boss(&BossTexture, sf::Vector2u(4, 2), 0.3f, 165.0f, sf::Vector2f(4 * 3200.0f, 4 * 118.0f - 50)));
			coin.push_back(new Item(&coinTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(4 * 50.0f, 4 * 75.0f)));
			coin.push_back(new Item(&coinTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(4 * 1647.0f, 4 * 178.0f)));
			coin.push_back(new Item(&coinTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(4 * 2575.0f, 4 * 178.0f)));
			coin.push_back(new Item(&coinTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(4 * 2887.0f, 4 * 178.0f)));
			key.push_back(new Item(&keyTexture, sf::Vector2u(1, 1), 0.4f, sf::Vector2f(4 * 3500.0f, 4 * 180.0f)));

			fire.push_back(Platform(nullptr, sf::Vector2f(4 * 174.0f, 4 * 14.0f), sf::Vector2f(4 * 353.0f, 4 * 193.0f)));
			fire.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 14.0f), sf::Vector2f(4 * 1617.0f, 4 * 196.0f)));
			fire.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 14.0f), sf::Vector2f(4 * 1681.0f, 4 * 196.0f)));

			//Floor
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 9.0f, 4 * 36.0f), sf::Vector2f(15 * 4.0f, 4 * 74.0f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 48.0f, 4 * 16.0f), sf::Vector2f(4 * 33.0f, 4 * 98.0f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 9.0f, 4 * 16.0f), sf::Vector2f(4 * 51.5f, 4 * 98.0f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 17.0f, 4 * 16.0f), sf::Vector2f(4 * 63.5f, 4 * 114.0f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 17.0f, 4 * 16.0f), sf::Vector2f(4 * 79.5f, 4 * 130.0f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 177.0f, 4 * 50.0f), sf::Vector2f(4 * 175.5f, 4 * 163.0f)));
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
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 24.0f, 4 * 15.0f), sf::Vector2f(4 * 1592.0f, 4 * 81.5f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 40.0f, 4 * 15.0f), sf::Vector2f(4 * 1648.0f, 4 * 81.5f)));
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 158.0f, 4 * 15.0f), sf::Vector2f(4 * 1768.0f, 4 * 81.5f)));
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
			platforms.push_back(Platform(nullptr, sf::Vector2f(4 * 16.0f, 4 * 161.0f), sf::Vector2f(4 * 3561.0f, 4 * 105.5f)));

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
				timeCount = Timer.getElapsedTime().asSeconds();

				gameTime.setString(std::to_string(timeCount));
				lifeNum.setString(std::to_string(player->getLife()));
				scorenum.setString(std::to_string(score));

				deltaTime = clock.restart().asSeconds();
				if (deltaTime > 1.f / 40.f)
					deltaTime = 1.f / 40.f;
				srand(time(0));
				int random = rand() % 4;
				int hrandom = rand() % 12;
				int manaRandom = rand() % randomPercent;
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
						window.close();
						return 0;
					}
				}

				//render				
				player->Update(deltaTime, hit);
				hit = 0;

				Collider playerCollision = player->GetCollider();
				sf::Vector2f direction;

				for (Platform& fire : fire) {
					if (fire.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
					{
						delifeSound.play();
						player->spawn();
						player->DecreaseLife(1);
						player->setHP(100);
					}
				}

				for (Platform& platform : platforms) {
					if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f))
					{
						player->onCollision(direction);
					}
					for (auto* i : monster) {
						Collider enemyCollision = i->GetCollider();
						if (platform.GetCollider().CheckCollision(enemyCollision, direction, 1.0f))
						{
							i->onCollision(direction);
						}

					}
				}


				bulletTime = bullTime.getElapsedTime().asMilliseconds();
				if (bulletTime > 400) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						shotSound.play();
						if (player->getDirection() == true) {
							playerBullet.push_back(new Bullet(&bulletTexture, 20, player->GetPosition().x + 25, player->GetPosition().y, 1.0f, 0.0f, 1.0f, 1.0f, 1));
						}
						if (player->getDirection() == false) {
							playerBullet.push_back(new Bullet(&bulletTexture, 20, player->GetPosition().x - 25, player->GetPosition().y, -1.0f, 0.0f, 1.0f, 1.0f, 1));
						}
						bullTime.restart();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && ulti > 0) {
						ultiSound.play();
						if (player->getDirection() == true) {
							special.push_back(new Bullet(&specialTexture, 10, player->GetPosition().x + 40, player->GetPosition().y, 1.0f, 0.0f, 2.0f, 2.0f, 2));

						}
						if (player->getDirection() == false) {
							special.push_back(new Bullet(&specialTexture, 10, player->GetPosition().x - 40, player->GetPosition().y, -1.0f, 0.0f, 2.0f, 2.0f, 2));
						}
						ulti = ulti - 1;
						bullTime.restart();
					}
					for (auto* bullet : playerBullet) {
						bullet->bulletDirection(player->getDirection());
					}
					for (auto* bullet : special) {
						bullet->bulletDirection(player->getDirection());
					}
				}


				int counter1 = 0;
				for (auto* bullet : playerBullet) {
					bullet->Update();
					if (bullet->GetPosition().x >= view.getCenter().x + 500 || bullet->GetPosition().x <= view.getCenter().x - 500)
					{
						delete playerBullet.at(counter1);
						playerBullet.erase(playerBullet.begin() + counter1);
						counter1--;
					}
					counter1++;
				}
				int counter11 = 0;
				for (auto* bullet : special) {
					bullet->Update();
					if (bullet->GetPosition().x >= view.getCenter().x + 500 || bullet->GetPosition().x <= view.getCenter().x - 500)
					{
						delete special.at(counter11);
						special.erase(special.begin() + counter11);
						counter11--;
					}
					counter11++;
				}


				for (auto* i : monster) {
					i->Update(deltaTime, player);
				}
				for (auto* i : boss1) {
					i->Update(deltaTime, player);
				}
				for (auto* i : coin) {
					i->Update(deltaTime);
				}
				for (auto* i : potion) {
					i->Update(deltaTime);
				}
				for (auto* i : mana) {
					i->Update(deltaTime);
				}
				for (auto* i : heart) {
					i->Update(deltaTime);
				}
				for (auto* i : key) {
					i->Update(deltaTime);
				}
				for (auto* i : special) {
					i->Update();
				}

				int counter = 0;
				hiTtime = hittime.getElapsedTime().asSeconds();

				for (auto* i : monster)
				{
					int counter = 0;
					for (auto* Bullet : playerBullet)
					{
						if (i->GetGlobalBounds().intersects(Bullet->GetGlobalBounds()))
						{
							hitSound.play();
							i->DecreaseHP(1);
							delete playerBullet.at(counter);
							playerBullet.erase(playerBullet.begin() + counter);
							counter--;
						}
						counter++;
					}

					for (auto* Bullet : special)
					{
						if (i->GetGlobalBounds().intersects(Bullet->GetGlobalBounds()))
						{
							hitSound.play();
							i->DecreaseHP(100);
						}
					}

					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()) && hiTtime >= 2)
					{
						hitplayerSound.play();
						player->DecreaseHP(25);
						hit = 1;
						hittime.restart();
					}
				}

				int counterB = 0;
				for (auto* i : boss1)
				{
					for (auto* Bullet : special)
					{
						if (i->GetGlobalBounds().intersects(Bullet->GetGlobalBounds()))
						{
							i->DecreaseHP(100);
							delete special.at(counterB);
							special.erase(special.begin() + counterB);
							counterB--;
						}
						counterB++;
					}
					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()) && hiTtime >= 2)
					{
						delifeSound.play();
						player->DecreaseLife(1);
						player->spawn();
						player->setHP(100);
						hit = 1;
						hittime.restart();
					}
				}
				int counterC = 0;
				for (auto* i : coin)
				{
					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()))
					{
						score = score + 10;
						coinSound.play();
						delete coin.at(counterC);
						coin.erase(coin.begin() + counterC);
						counterC--;
					}
					counterC++;
				}

				int counterD = 0;
				for (auto* i : potion)
				{
					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()))
					{
						HPsound.play();
						player->DecreaseHP(-25);
						delete potion.at(counterD);
						potion.erase(potion.begin() + counterD);
						counterD--;
					}
					counterD++;
				}

				int counterE = 0;
				for (auto* i : heart)
				{
					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()))
					{
						lifeSound.play();
						player->DecreaseLife(-1);
						delete heart.at(counterE);
						heart.erase(heart.begin() + counterE);
						counterE--;
					}
					counterE++;
				}

				int counterF = 0;
				for (auto* i : mana)
				{
					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()))
					{
						ulti = ulti + 1;
						powerupSound.play();
						delete mana.at(counterF);
						mana.erase(mana.begin() + counterF);
						counterF--;
					}
					counterF++;
				}

				int counterG = 0;
				for (auto* i : key)
				{
					if (i->GetGlobalBounds().intersects(player->GetGlobalBounds()))
					{
						totalscore = player->getLife() * 15 - (timeCount / 5) + score + ulti * 3;
						powerupSound.play();
						delete key.at(counterG);
						key.erase(key.begin() + counterG);
						counterG--;

						section_number = 4;
						window.close();
						break;
					}
					counterG++;
				}

				for (auto* i : monster)
				{
					i->Update(deltaTime, player);

					if (i->getHP() <= 0)
					{
						score++;
						if (manaRandom == 0) {
							mana.push_back(new Item(&manaTexture, sf::Vector2u(1, 1), 0.4f, sf::Vector2f(i->getPosition().x, i->getPosition().y + 15)));
						}
						else if (hrandom == 0) {
							heart.push_back(new Item(&heartTexture, sf::Vector2u(6, 1), 0.4f, sf::Vector2f(i->getPosition().x, i->getPosition().y + 10)));
						}
						else if (random == 0) {
							potion.push_back(new Item(&potionTexture, sf::Vector2u(1, 1), 0.4f, sf::Vector2f(i->getPosition().x, i->getPosition().y + 20)));
						}
						enemydieSound.play();
						delete monster.at(counter);
						monster.erase(monster.begin() + counter);
						counter--;
						randomPercent--;
					}
					counter++;
				}

				if (randomPercent == 0) {
					randomPercent = 1;
				}

				int bosscounter = 0;
				for (auto* i : boss1)
				{
					i->Update(deltaTime, player);

					if (i->getHP() <= 0)
					{
						enemydieSound.play();
						delete boss1.at(bosscounter);
						boss1.erase(boss1.begin() + bosscounter);
						bosscounter--;
					}
					bosscounter++;
				}

				if (player->GetPosition().x < 3569 * 4 - 500 && player->GetPosition().x > 500)
				{
					if (player->GetPosition().y < 125 * 4) {
						if (player->GetPosition().y > 84 * 4) {
							view.setCenter(player->GetPosition());
							lifeText.setPosition(player->GetPosition().x - 395, player->GetPosition().y - 300);
							lifeNum.setPosition(player->GetPosition().x - 250, player->GetPosition().y - 300);
							HPbar.setPosition(player->GetPosition().x + 300, player->GetPosition().y - 275);
							gameTime.setPosition(player->GetPosition().x, player->GetPosition().y - 300);
							scoretext.setPosition(player->GetPosition().x - 395, player->GetPosition().y - 240);
							scorenum.setPosition(player->GetPosition().x - 250, player->GetPosition().y - 240);
						}
						else
						{
							view.setCenter(player->GetPosition().x, 84 * 4);
							lifeText.setPosition(player->GetPosition().x - 395, 84 * 4 - 300);
							lifeNum.setPosition(player->GetPosition().x - 250, 84 * 4 - 300);
							HPbar.setPosition(player->GetPosition().x + 300, 84 * 4 - 275);
							gameTime.setPosition(player->GetPosition().x, 84 * 4 - 300);
							scoretext.setPosition(player->GetPosition().x - 395, 84 * 4 - 240);
							scorenum.setPosition(player->GetPosition().x - 250, 84 * 4 - 240);
						}
					}
					else if (player->GetPosition().y >= 125 * 4) {
						view.setCenter(player->GetPosition().x, 125 * 4);
						lifeText.setPosition(player->GetPosition().x - 395, 125 * 4 - 300);
						lifeNum.setPosition(player->GetPosition().x - 250, 125 * 4 - 300);
						HPbar.setPosition(player->GetPosition().x + 300, 125 * 4 - 275);
						gameTime.setPosition(player->GetPosition().x, 125 * 4 - 300);
						scoretext.setPosition(player->GetPosition().x - 395, 125 * 4 - 240);
						scorenum.setPosition(player->GetPosition().x - 250, 125 * 4 - 240);

					}
				}

				else if (player->GetPosition().x < 500) {
					if (player->GetPosition().y < 125 * 4) {
						if (player->GetPosition().y > 84 * 4) {
							view.setCenter(499, player->GetPosition().y);
							lifeText.setPosition(104, player->GetPosition().y - 300);
							lifeNum.setPosition(499 - 250, player->GetPosition().y - 300);
							HPbar.setPosition(799, player->GetPosition().y - 275);
							gameTime.setPosition(499, player->GetPosition().y - 300);
							scoretext.setPosition(499 - 395, player->GetPosition().y - 240);
							scorenum.setPosition(499 - 250, player->GetPosition().y - 240);
						}
						else
						{
							view.setCenter(499, 84 * 4);
							lifeText.setPosition(104, 84 * 4 - 300);
							lifeNum.setPosition(499 - 250, 84 * 4 - 300);
							HPbar.setPosition(799, 84 * 4 - 275);
							gameTime.setPosition(499, 84 * 4 - 300);
							scoretext.setPosition(499 - 395, 84 * 4 - 240);
							scorenum.setPosition(499 - 250, 84 * 4 - 240);
						}
					}
					else if (player->GetPosition().y >= 125 * 4) {
						view.setCenter(499, 125 * 4);
						lifeText.setPosition(104, 125 * 4 - 300);
						lifeNum.setPosition(499 - 250, 125 * 4 - 300);
						HPbar.setPosition(799, 125 * 4 - 275);
						gameTime.setPosition(499, 125 * 4 - 300);
						scoretext.setPosition(499 - 395, 125 * 4 - 240);
						scorenum.setPosition(499 - 250, 125 * 4 - 240);

					}
				}


				if (player->getHP() >= 100) {
					animationFrame = 0;
				}
				else if (player->getHP() >= 75) {
					animationFrame = 1;
				}
				else if (player->getHP() >= 50) {
					animationFrame = 2;
				}
				else if (player->getHP() <= 25) {
					animationFrame = 3;
				}

				HPbar.setTextureRect((sf::IntRect(animationFrame * HPbarTexture.getSize().x / 4, 0, HPbarTexture.getSize().x / 4, HPbarTexture.getSize().y)));
				HPbar.setSize(sf::Vector2f(175.f, 176.f));
				HPbar.setScale(0.3, 0.3);


				std::cout << player->GetPosition().x / 4 << " " << player->GetPosition().y / 4 << std::endl;
				window.clear();
				window.setView(view);
				window.draw(background);
				window.draw(lifeText);
				window.draw(lifeNum);
				window.draw(gameTime);
				window.draw(HPbar);
				window.draw(scorenum);
				window.draw(scoretext);


				//for (Platform& platform : platforms)
				//	platform.Draw(window);

				if (player->getHP() <= 0) {
					delifeSound.play();
					player->spawn();
					player->setHP(100);
					player->DecreaseLife(1);
				}

				if (player->getLife() < 0) {
					totalscore = player->getLife() * 15 - (timeCount / 5) + score + ulti * 3;
					section_number = 3;
					window.close();
				}

				if (player->GetPosition().x >= 1710.f * 4 && player->GetPosition().x <= 1780.f * 4 && player->GetPosition().y <= 75.f * 4) {
					player->setspawnX(1730.f * 4);
					player->setspawnY(60.0f * 4);
				}
				for (auto* i : monster)
					i->Draw(window);

				for (auto* bullet : playerBullet)
				{
					bullet->Draw(window);
				}
				for (auto* bullet : special)
				{
					bullet->Draw(window);
				}

				for (auto* Boss1 : boss1)
				{
					Boss1->Draw(window);
				}

				for (auto* Coin : coin)
				{
					Coin->Draw(window);
				}

				for (auto* Potion : potion)
				{
					Potion->Draw(window);
				}
				for (auto* Potion : mana)
				{
					Potion->Draw(window);
				}
				for (auto* Heart : heart)
				{
					Heart->Draw(window);
				}
				for (auto* Key : key)
				{
					Key->Draw(window);
				}
				player->Draw(window);
				window.display();

			}

		}
		if (section_number == 3)
		{
			sf::RenderWindow window(sf::VideoMode(1000, 800), "Ggame");
			retryMenu retrymenu(window.getSize().x, window.getSize().y);
			sf::Texture Rtexture;
			Rtexture.loadFromFile("resource/retryBG.jpg");

			sf::Sprite Rbackground;
			Rbackground.setTexture(Rtexture);
			Rbackground.setPosition(0, 15);

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					switch (event.type)
					{
					case sf::Event::KeyReleased:
						switch (event.key.code)
						{
						case sf::Keyboard::Up:
							retrymenu.MoveUp();
							break;
						case sf::Keyboard::Down:
							retrymenu.MoveDown();
							break;
						case sf::Keyboard::Return:
							switch (retrymenu.GetPressedItem())
							{
							case 0:

								section_number = 1;
								window.close();
								break;

							case 1:
								section_number = 0;
								window.close();
								break;

							}
						}
					}
				}
				window.clear();
				window.draw(Rbackground);
				retrymenu.draw(window);
				window.display();
			}
		}
	}


	return 0;
}